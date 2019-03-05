#include "em_leuart.h"
/*
 * leuart.h
 *
 *  Created on: 26 Feb 2019
 *      Author: Dylan
 */

#ifndef SRC_LEUART_H_
#define SRC_LEUART_H_

extern volatile bool stop_RX;
extern volatile bool stop_TX;

#define LEUART0_CMD        LEUART0 -> CMD
#define LEUART0_CTRL       LEUART0 -> CTRL
#define LEUART0_INT_EN     LEUART0 -> IEN
#define LEUART0_FLAG       LEUART0 -> IF
#define LEUART0_FLAG_CLR   LEUART0 -> IFC
#define LEUART0_RX         LEUART0 -> RXDATA
#define LEUART0_TX         LEUART0 -> TXDATA
#define LEUART0_ROUTELOC   LEUART0 -> ROUTELOC0
#define LEUART0_ROUTEPEN   LEUART0 -> ROUTEPEN

#define LEUART0_Loopback_Enable() (LEUART0_CTRL |= LEUART_CTRL_LOOPBK)
#define LEUART0_TX_Disable()      (LEUART0_CMD &= ~LEUART_CMD_TXEN)
#define LEUART0_RX_Disable()      (LEUART0_CMD &= ~LEUART_CMD_RXEN)
#define LEUART0_TXBL_Enable()     (LEUART0_INT_EN |= LEUART_IEN_TXBL)
#define LEUART0_TXBL_Disable()    (LEUART0_INT_EN &= ~LEUART_IEN_TXBL)
#define LEUART0_RXDATAV_Enable()  (LEUART0_INT_EN |= LEUART_IEN_RXDATAV)
#define LEUART0_RXDATAV_Disable() (LEUART0_INT_EN &= ~LEUART_IEN_RXDATAV)

void leuart0_init(void);
void LEUART0_Write(void);
uint8_t LEUART0_Read(void);
void LEUART0_Change_Name(void);
void LEUART0_Wait_TXBL(void);
void LEUART0_Wait_RXDATAV(void);
#endif /* SRC_LEUART_H_ */
