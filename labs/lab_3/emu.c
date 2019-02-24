#include "emu.h"

/* This code is originally Silicon Labs and copy righted by Silicon Labs� in 
 * 2015 and Silicon Labs� grants permission to anyone to use the software for 
 * any purpose, including commercial applications, and to alter it, and 
 * redistribute it freely subject that the origins is not miss represented, 
 * altered source version must be plainly marked, and this notice cannot be 
 * altered or removed from any source distribution.
 *
 * Names of routines have been changed to confirm to the naming convention of 
 * the application developer.
 *
 * Routines include:
 *
 * void Sleep_Block_Mode(unsigned int EM);
 * void Sleep_UnBlock_Mode(unsigned int EM);
 * void Enter_Sleep(void);
 *
 */

/******************************************************************************
 * filename: emu.c                                                            *
 *                                                                            *
 * purpose: Contains functions pertaining to the EMU of the Pearl Gecko and   *
 *          that modify the energy mode that the Pearl Gecko operates in      *
 *                                                                            *
 * date created: 22 Jan 2019                                                  *
 *                                                                            *
 * authors: Dylan Oh and Mike Fruge                                           *
 *****************************************************************************/

/******************************************************************************
 * GLOBAL VARIABLES                                                           *
 *****************************************************************************/
volatile uint32_t lowest_energy_mode[MAX_EM_ELEMENTS];


/******************************************************************************
 * FUNCTION DEFINITIONS                                                       *
 *****************************************************************************/

/*
 * function name: blockSleepMode
 *
 * description: Sets a limit on the minimum allowable energy mode that the
 *              Pearl Gecko can operate in
 * 
 * arguments:
 * argument     type        description
 * --------     ----        -----------
 * minimumMode  uint8_t     minimum mode the Pearl Gecko can operate in
 * 
 * returns: none
 */

void blockSleepMode(uint8_t EM){
    CORE_ATOMIC_IRQ_DISABLE();
    lowest_energy_mode[EM]++;
    CORE_ATOMIC_IRQ_ENABLE();
}

/*****************************************************************************/

/*
 * function name: unblockSleepMode
 *
 * description: Removes limit on the minimum allowable energy mode that the
 *              Pearl Gecko can operate in
 * 
 * arguments:
 * argument     type        description
 * --------     ----        -----------
 * minimumMode  uint8_t     minimum mode the Pearl Gecko can operate in
 * 
 * returns: none
 */

void unblockSleepMode(uint8_t EM){
    CORE_ATOMIC_IRQ_DISABLE();
    if (lowest_energy_mode[EM] > 0) lowest_energy_mode[EM]--;
    CORE_ATOMIC_IRQ_ENABLE();
}

/*****************************************************************************/

/*
 * function name: enter_sleep
 *
 * description: Puts the Pearl Gecko to sleep in the lowest energy mode
 *              allowed by the block and unblock functions
 * 
 * arguments: none
 * 
 * returns: none
 */

void enter_sleep(void){
    if (lowest_energy_mode[EM0] > 0){
        return;
    } else if (lowest_energy_mode[EM1] > 0){
        return;
    } else if (lowest_energy_mode[EM2] > 0){
        EMU_EnterEM1();
    } else if (lowest_energy_mode[EM3] > 0){
        EMU_EnterEM2(true);
    } else {
        EMU_EnterEM3(true);
    }
}
