/*
 * FT-710 IFDSP M33: SCT0 PWM on SCT0_OUT0 (PIO2_2) into the RC filter R2041/C2003 (T24, recreated from the image
 * 0x81164..0x81270). 20 kHz, centre aligned; every 400 periods (20 ms) the duty cycle is reloaded from register 0x4005,
 * which the DSP writes, clamped to 1..99 % (docs/code/ifdsp/control-link.md, register 0x4005).
 */
#include "fsl_common.h"
#include "fsl_sctimer.h"
#include "regfile.h"
#include "pwm.h"

#define PWM_FREQ_HZ      20000U
#define PWM_RELOAD_TICKS 400U /* 20 ms at 20 kHz */

static uint32_t s_pwmEvent;
static uint32_t s_pwmTicks;
static volatile uint8_t s_pwmDuty; /* volatile: the image stores and re-reads it [fact: 0x81204] */

/* SCT0 interrupt callback, once per PWM period */
void sct0_pwm_callback(void)
{
    if (++s_pwmTicks >= PWM_RELOAD_TICKS)
    {
        uint16_t duty;

        s_pwmTicks = 0;
        duty       = regfile_read(REG_PWM_DUTY);
        if (duty == 0U)
        {
            duty = 1;
        }
        if (duty > 98U)
        {
            duty = 99;
        }
        s_pwmDuty = (uint8_t)duty;
        SCTIMER_UpdatePwmDutycycle(SCT0, kSCTIMER_Out_0, s_pwmDuty, s_pwmEvent);
    }
    if ((SCTIMER_GetStatusFlags(SCT0) & (1UL << s_pwmEvent)) != 0U)
    {
        SCTIMER_ClearStatusFlags(SCT0, 1UL << s_pwmEvent);
    }
}

void sct0_pwm_init(void)
{
    sctimer_config_t config;
    sctimer_pwm_signal_param_t pwm;
    uint32_t sctClock = CLOCK_GetFreq(kCLOCK_BusClk);

    SCTIMER_GetDefaultConfig(&config);
    SCTIMER_Init(SCT0, &config);

    s_pwmDuty            = 1;
    s_pwmEvent           = 0;
    pwm.output           = kSCTIMER_Out_0;
    pwm.level            = kSCTIMER_HighTrue;
    pwm.dutyCyclePercent = s_pwmDuty;
    if (SCTIMER_SetupPwm(SCT0, &pwm, kSCTIMER_CenterAlignedPwm, PWM_FREQ_HZ, sctClock, &s_pwmEvent) == kStatus_Fail)
    {
        return;
    }
    SCTIMER_EnableInterrupts(SCT0, 1UL << s_pwmEvent);
    SCTIMER_SetCallback(SCT0, sct0_pwm_callback, s_pwmEvent);
    EnableIRQ(SCT0_IRQn);
}

/* Started by main once the tasks exist. */
void sct0_pwm_start(void)
{
    SCTIMER_StartTimer(SCT0, kSCTIMER_Counter_U);
}
