/*
 * test4-timer.c
 *
 * Created: 2024-03-29 오전 11:28:51
 * Author : KangHeeJun
 */ 

#include "myHeader.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define _delay_t 500

void SegPort(char *p1, char *p2);

unsigned long cnt = 0, tcnt = 0;

int main(void)
{
	/*Replace with your application code*/
	DDRA = 0xFF;// 세그먼트 제어 핀 8개를 출력으로 설정
	DDRB = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
	SegPort(&PORTA, &PORTB);
	SegType(0);
	
    //TIMSK |= 0x01; // 0000 0001b - Timer 0 TCNT overflow Interrupt
	//TIMSK | = 0x04; // 0000 0100b - Timer 1 TCNT overflow interrupt
	TIMSK |= 0x40; // 0000 0001b - Timer 2 TCNT overflow Interrupt
	//ETIMSK |= 0x04; // 0000 0001b - Timer 3 TCNT overflow Interrupt
	TCCR0 = 0x04; // 분주비 (Pre - Scaler) 64
	TCCR2 = 0b0000111; //분주비
	TCCR1B = 0x04;// 분주비 (Pre - Scaler) 64
	//TCCR2 = 0x04; // 분주비 (Pre - Scaler) 64
	SREG |= 0x80;
	sei();
    while (1) 
    {
		if (cnt >= 0x10000) cnt = 0;
		SegDisp(cnt);
	}
}
	/*ISR(TIMER0_OVF_vect)
	{
		tcnt++;
		if(tcnt >= 1000)
		{
			cnt++, tcnt = 0;
		}
	}
*/
	ISR(TIMER1_OVF_vect)
	{
		cnt++;
	}
	
	
		/*ISR(TIMER2_OVF_vect)
		{
			tcnt++;
			if(tcnt >= 1000)
			{
				cnt++, tcnt = 0;
			}
		}
*/
ISR(TIMER2_OVF_vect)
{
	tcnt++;
	if(tcnt >= 500)	// 8bit timer 사용시
	{
		cnt++; tcnt = 0;
	}
}