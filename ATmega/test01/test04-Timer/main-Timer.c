/*
 * test04-Timer.c
 *
 * Created: 2024-03-28 오전 10:59:04
 * Author : KangHeeJun
 */ 
#include "myHeader.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define __delay_t 500

unsigned long cnt = 0, tcnt = 0;

int main(void)
{
	/*Replace with your application code*/
	DDRD = 0xFF;// 세그먼트 제어 핀 8개를 출ㄺ으로 설정
	DDRC = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
	
    TIMSK |= 0x01; // 0000 0001b - Timer 0 TCNT overflow Interrupt
	//TIMSK |= 0x40; // 0000 0001b - Timer 2 TCNT overflow Interrupt
	TCCR0 = 0x04; // 분주비 (Pre - Scaler) 64
	//TCCR2 = 0x04; // 분주비 (Pre - Scaler) 64
	SREG |= 0x80;
	sei();
    while (1) 
    {
		if (cnt >= 0x10000) cnt = 0;
		Disp(cnt);
	}
}
	ISR(TIMER0_OVF_vect)
	{
		tcnt++;
		if(tcnt >= 1000)
		{
			cnt++, tcnt = 0;
		}
	}
