#include "emu.h"

/******************************************************************************
 * filename: emu.c															  *
 * 																			  *
 * purpose: Contains functions pertaining to the EMU of the Pearl Gecko and   *
 * 			that modify the energy mode that the Pearl Gecko operates in      *
 * 																			  *
 * date created: 22 Jan 2019												  *
 *																			  *
 * authors: Dylan Oh and Mike Fruge											  *
 *****************************************************************************/

/******************************************************************************
 * GLOBAL VARIABLES      					 								  *
 *****************************************************************************/
volatile uint32_t sleep_block_counter[MAX_EM_ELEMENTS];


/******************************************************************************
 * FUNCTION DEFINITIONS 					 								  *
 *****************************************************************************/

/*
 * function name: blockSleepMode
 *
 * description: Sets a limit on the minimum allowable energy mode that the
 * 				Pearl Gecko can operate in
 * 
 * arguments:
 * argument		type		I/O		description
 * --------		----	    ---		-----------
 * minimumMode	uint8_t		input	minimum mode the Pearl Gecko can operate in
 * 
 * returns: none
 */

void blockSleepMode(uint8_t minimumMode){
	CORE_ATOMIC_IRQ_DISABLE();
	sleep_block_counter[minimumMode]++;
	CORE_ATOMIC_IRQ_ENABLE();
}

/*****************************************************************************/

/*
 * function name: unblockSleepMode
 *
 * description: Removes limit on the minimum allowable energy mode that the
 * 				Pearl Gecko can operate in
 * 
 * arguments:
 * argument		type		I/O		description
 * --------		----	    ---		-----------
 * minimumMode	uint8_t		input	minimum mode the Pearl Gecko can operate in
 * 
 * returns: none
 */

void unblockSleepMode(uint8_t minimumMode){
	CORE_ATOMIC_IRQ_DISABLE();
	if (sleep_block_counter[minimumMode] > 0){
		sleep_block_counter[minimumMode]--;
	}
	CORE_ATOMIC_IRQ_ENABLE();
}

/*****************************************************************************/

/*
 * function name: enter_sleep
 *
 * description: Puts the Pearl Gecko to sleep in the lowest energy mode
 * 				allowed by the block and unblock functions
 * 
 * arguments: none
 * 
 * returns: none
 */

void enter_sleep(void){
	if (sleep_block_counter[EM0] > 0){
		return;
	} else if (sleep_block_counter[EM1] > 0){
		return;
	} else if (sleep_block_counter[EM2] > 0){
		EMU_EnterEM1();
	} else if (sleep_block_counter[EM3] > 0){
		EMU_EnterEM2(true);
	} else {
		EMU_EnterEM3(true);
	}
}