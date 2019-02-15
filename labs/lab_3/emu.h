#include "em_emu.h"
#include "em_core.h"
#include "main.h"

/******************************************************************************
 * filename: emu.h                                                            *
 *                                                                            *
 * purpose: Contains function declarations and macros used in emu.c           *
 *                                                                            *
 * date created: 22 Jan 2019                                                  *
 *                                                                            *
 * authors: Dylan Oh and Mike Fruge                                           *
 *****************************************************************************/

/******************************************************************************
 * MACRO DEFINITIONS                                                          *
 *****************************************************************************/
#define MAX_EM_ELEMENTS 5
#define EM0             0
#define EM1             1
#define EM2             2
#define EM3             3
#define EM4             4


/******************************************************************************
 * FUNCTION DECLARATIONS                                                      *
 *****************************************************************************/
void blockSleepMode(uint8_t);
void unblockSleepMode(uint8_t);
void enter_sleep(void);
