/* FT-710 IFDSP M33: SCT0 PWM (T24), see pwm.c. */
#ifndef PWM_H_
#define PWM_H_

void sct0_pwm_callback(void);
void sct0_pwm_init(void);
void sct0_pwm_start(void);

#endif /* PWM_H_ */
