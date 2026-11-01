/* Public functions of the SCI0..SCI5 drivers (src/main/drivers/r_cg_sci.c, r_cg_sci_user.c), T24 MAIN. */
#ifndef R_CG_SCI_H
#define R_CG_SCI_H

#include "main.h"

void R_SCI0_Create(void);
void R_SCI0_Create_UserInit(void);
void R_SCI0_Start(void);
void R_SCI0_Stop(void);
MD_STATUS R_SCI0_Serial_Receive(uint8_t *rx_buf, uint16_t rx_num);
MD_STATUS R_SCI0_Serial_Send(uint8_t *tx_buf, uint16_t tx_num);
void r_sci0_transmit_interrupt(void);
void r_sci0_transmitend_interrupt(void);
void r_sci0_receive_interrupt(void);
void r_sci0_receiveerror_interrupt(void);
void r_sci0_callback_transmitend(void);
void r_sci0_callback_receiveerror(void);
void r_sci0_callback_receiveend(void);

void R_SCI1_Create(void);
void R_SCI1_Create_UserInit(void);
void R_SCI1_Start(void);
void R_SCI1_Stop(void);
MD_STATUS R_SCI1_Serial_Receive(uint8_t *rx_buf, uint16_t rx_num);
MD_STATUS R_SCI1_Serial_Send(uint8_t *tx_buf, uint16_t tx_num);
void r_sci1_transmit_interrupt(void);
void r_sci1_transmitend_interrupt(void);
void r_sci1_receive_interrupt(void);
void r_sci1_receiveerror_interrupt(void);
void r_sci1_callback_transmitend(void);
void r_sci1_callback_receiveerror(void);
void r_sci1_callback_receiveend(void);

void R_SCI2_Create(void);
void R_SCI2_Create_UserInit(void);
void R_SCI2_Start(void);
void R_SCI2_Stop(void);
MD_STATUS R_SCI2_Serial_Receive(uint8_t *rx_buf, uint16_t rx_num);
MD_STATUS R_SCI2_Serial_Send(uint8_t *tx_buf, uint16_t tx_num);
void r_sci2_transmit_interrupt(void);
void r_sci2_transmitend_interrupt(void);
void r_sci2_receive_interrupt(void);
void r_sci2_receiveerror_interrupt(void);
void r_sci2_callback_transmitend(void);
void r_sci2_callback_receiveerror(void);
void r_sci2_callback_receiveend(void);

void R_SCI3_Create(void);
void R_SCI3_Create_UserInit(void);
void R_SCI3_Start(void);
void R_SCI3_Stop(void);
MD_STATUS R_SCI3_Serial_Receive(uint8_t *rx_buf, uint16_t rx_num);
MD_STATUS R_SCI3_Serial_Send(uint8_t *tx_buf, uint16_t tx_num);
void r_sci3_transmit_interrupt(void);
void r_sci3_transmitend_interrupt(void);
void r_sci3_receive_interrupt(void);
void r_sci3_receiveerror_interrupt(void);
void r_sci3_callback_transmitend(void);
void r_sci3_callback_receiveerror(void);
void r_sci3_callback_receiveend(void);

void R_SCI4_Create(void);
void R_SCI4_Create_UserInit(void);
void R_SCI4_Start(void);
void R_SCI4_Stop(void);
MD_STATUS R_SCI4_Serial_Receive(uint8_t *rx_buf, uint16_t rx_num);
MD_STATUS R_SCI4_Serial_Send(uint8_t *tx_buf, uint16_t tx_num);
void r_sci4_transmit_interrupt(void);
void r_sci4_transmitend_interrupt(void);
void r_sci4_receive_interrupt(void);
void r_sci4_receiveerror_interrupt(void);
void r_sci4_callback_transmitend(void);
void r_sci4_callback_receiveerror(void);

void R_SCI5_Create(void);
void R_SCI5_Create_UserInit(void);
void R_SCI5_Start(void);
void R_SCI5_Stop(void);
MD_STATUS R_SCI5_Serial_Receive(uint8_t *rx_buf, uint16_t rx_num);
MD_STATUS R_SCI5_Serial_Send(uint8_t *tx_buf, uint16_t tx_num);
void r_sci5_transmit_interrupt(void);
void r_sci5_transmitend_interrupt(void);
void r_sci5_receive_interrupt(void);
void r_sci5_receiveerror_interrupt(void);
void r_sci5_callback_transmitend(void);
void r_sci5_callback_receiveerror(void);
void r_sci5_callback_receiveend(void);

void r_sci0_rx_byte_hook(void);
void sci3_rx_byte_hook(void);
void sci4_rx_frame_done(void);
void sci5_rx_byte_hook(void);

#endif
