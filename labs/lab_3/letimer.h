#include "em_letimer.h"
#include "emu.h"

/******************************************************************************
 * filename: letimer.h														  *
 * 																			  *
 * purpose: contains function declarations and macros used in letimer.c       *
 * 																			  *
 * date created: 22 Jan 2019												  *
 *																			  *
 * authors: Dylan Oh and Mike Fruge											  *
 *****************************************************************************/

/******************************************************************************
 * MACRO DEFINITIONS     					 								  *
 *****************************************************************************/
#define     LFXO_FREQ       32768u
#define     ULFRCO_FREQ     1000u
#define     MAX_COUNT       65535
#define     LETIMER_PERIOD  1.75
#define     LED_ON_TIME     0.4
#define     LETIMER0_EM     3


/******************************************************************************
 * FUNCTION DECLARATIONS 					 								  *
 *****************************************************************************/
void letimer0_init(void);
void LETIMER0_IRQHandler(void);