/*
 * timer.c
 *
 *  Created on: 10 oct. 2011
 *      Author: timothee
 */
#include <msp430.h>
#include "timer.h"
#include "bithacks.h"
#include "target.h"
#include "power.h"
#include <stdio.h>
#include "uart.h"

void TimerTA0Start()
{
#ifdef 		TA0_0_PIN
	B_SET(	TA0_0_DIR, 	TA0_0_PIN);			//BUZZER pin as output
	B_UNSET(TA0_0_OUT, 	TA0_0_PIN);			//BUZZER pin as timer output
	B_SET(	TA0_0_SEL, 	TA0_0_PIN);			//BUZZER pin as timer output
	B_UNSET(TA0_0_SEL2, TA0_0_PIN);			//BUZZER pin as timer output
#endif //	TA0_0_PIN


#ifdef 		TA0_1_PIN
	B_UNSET(P2SEL, 7);
	B_UNSET(P2SEL2, 7);
	B_SET(	TA0_1_DIR, 	TA0_1_PIN);			//BUZZER pin as output
	B_SET(	TA0_1_SEL, 	TA0_1_PIN);			//BUZZER pin as output
	B_UNSET(TA0_1_SEL2, TA0_1_PIN);			//BUZZER pin as timer output
	TA0CCTL1 = OUTMOD_2;
#endif //	TA0_1_PIN

#ifdef 		TA0_2_PIN

	B_SET(	TA0_2_DIR, 	TA0_2_PIN);			//BUZZER pin as output
	B_UNSET(TA0_2_OUT,	TA0_2_PIN);			//BUZZER pin as timer output
	B_SET(	TA0_2_SEL, 	TA0_2_PIN);			//BUZZER pin as timer output
	B_UNSET(TA0_2_SEL2, TA0_2_PIN);			//BUZZER pin as timer output
	TA0CCTL2 = OUTMOD_6;
#endif //	TA0_2_PIN

	TA0CTL = TASSEL_2 +  MC_3 + ID_0;     	// SMCLK, Up to CCR0 mode, Start timer
}

void TimerTA1Start()
{

#ifdef 		TA1_0_PIN
	B_SET(	TA1_0_DIR,	TA1_0_PIN);			//BUZZER pin as output
	B_UNSET(TA1_0_OUT, 	TA1_0_PIN);			//BUZZER pin as timer output
	B_SET(	TA1_0_SEL, 	TA1_0_PIN);			//BUZZER pin as timer output
	B_UNSET(TA1_0_SEL2, TA1_0_PIN);			//BUZZER pin as timer output
#endif //	TA1_0_PIN

#ifdef 		TA1_1_PIN
	B_SET(	TA1_1_DIR, 	TA1_1_PIN);			//BUZZER pin as output
	B_UNSET(TA1_1_OUT, 	TA1_1_PIN);			//BUZZER state as low
	B_SET(	TA1_1_SEL, 	TA1_1_PIN);			//BUZZER pin as timer output
	B_UNSET(TA1_1_SEL2, TA1_1_PIN);			//BUZZER pin as timer output
	TA1CCTL1 = OUTMOD_2;
#endif //	TA1_1_PIN

#ifdef 		TA1_2_PIN
	B_SET(	TA1_2_DIR, 	TA1_2_PIN);			//BUZZER pin as output
	B_UNSET(TA1_2_OUT, 	TA1_2_PIN);			//BUZZER state as low
	B_SET(	TA1_2_SEL, 	TA1_2_PIN);			//BUZZER pin as timer output
	B_UNSET(TA1_2_SEL2, TA1_2_PIN);			//BUZZER pin as timer output
	TA1CCTL2 = OUTMOD_6;
#endif //	TA1_2_PIN

	TA1CTL = TASSEL_2 +  MC_3 + ID_3;     // SMCLK, Up down mode, Start timer

}



void TimerTA0Set(int ccr0, int ccr1, int ccr2)
{
	TA0CCR0 = ccr0;
	TA0CCR1 = ccr1;
	TA0CCR2 = ccr2;
	TimerTA0Start();
}

void TimerTA1Set(int ccr0, int ccr1, int ccr2)
{
	TA1CCR0 = ccr0;
	TA1CCR1 = ccr1;
	TA1CCR2 = ccr2;
	TimerTA1Start();
}

void TimerTA0Stop()
{
	TA0CTL = MC_0;     // Stop timer
#ifdef TA0_0_PIN

#endif //	TA0_0_PIN

#ifdef TA0_1_PIN
	//TA0CCTL1 = 0;
	B_UNSET(TA0_1_SEL, 	TA0_1_PIN);			//Charge Pump pin as GPIO
	B_UNSET(TA0_1_SEL2, TA0_1_PIN);			//Charge Pump pin as GPIO
	B_UNSET(TA0_1_DIR, 	TA0_1_PIN);			//Charge Pump pin as input
#endif //	TA0_1_PIN

#ifdef TA0_2_PIN
	B_UNSET(TA0_2_SEL, 	TA0_2_PIN);			//Charge Pump pin as GPIO
	B_UNSET(TA0_2_SEL2, TA0_2_PIN);			//Charge Pump pin as GPIO
	B_UNSET(TA0_2_DIR, 	TA0_2_PIN);			//Charge Pump pin as input
#endif //	TA0_2_PIN
}

void TimerTA1Stop()
{
	TA1CTL = MC_0;     // Stop timer
#ifdef TA1_0_PIN

#endif //	TA1_0_PIN
#ifdef TA1_1_PIN
	B_UNSET(TA1_1_SEL, TA1_1_PIN);			//BUZZER pin as GPIO
	B_UNSET(TA1_1_SEL2,TA1_1_PIN);			//BUZZER pin as GPIO
	B_UNSET(TA1_1_OUT, TA1_1_PIN);			//BUZZER pin state low
	B_SET(	TA1_1_DIR, TA1_1_PIN);			//BUZZER pin as output
#endif //	TA1_1_PIN
#ifdef TA1_2_PIN
	B_UNSET(TA1_2_SEL, TA1_2_PIN);			//BUZZER pin as GPIO
	B_UNSET(TA1_2_SEL2,TA1_2_PIN);			//BUZZER pin as GPIO
	B_UNSET(TA1_2_OUT, TA1_2_PIN);			//BUZZER pin state low
	B_SET(	TA1_2_DIR, TA1_2_PIN);			//BUZZER pin as output
#endif //	TA1_2_PIN

}



static uint16_t TimerCycleCounter = 0;

void TimerRegister(uint16_t cycle)
{
#if	DELAY_TIMER != 0
	__disable_interrupt();
	TimerCycleCounter = cycle;
	TA0CCTL0 |= CCIE;       				// CCR0 interrupt enabled
	__enable_interrupt();
#endif
}

void TimerDisable(void)
{
	TA0CCTL0 = 0;       				// CCR0 interrupt disabled
}

void TimerWait()
{
#if	DELAY_TIMER != 0
	while (TimerCycleCounter)
	{
		__no_operation();
		PowerEnterLowPower();
	}
#endif
}


interrupt(TIMER0_A0_VECTOR) TIMER0_A0_ISR(void)
{
	if (TimerCycleCounter)
	{
		TimerCycleCounter--;
		if (!TimerCycleCounter)
		{
			TimerDisable();
			PowerExitLowPower();
		}
	}
}

interrupt(TIMER0_A1_VECTOR) TIMER0_A1_ISR(void)
{
}



