/*
 * test3-intr.c
 *
 * Created: 2024-03-29 오전 11:22:33
 * Author : KangHeeJun
 */ 

#include "myHeader.h"
//#define F_CPU 16000000L

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define __delay_t 500
#define OPMODEMAX	3
#define STATE_MAX	3

uint8_t digit[]
= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71,0xc0,0x00};
char arr[5];  //세그먼트 이미지 정보를 담을 안전 영역
volatile int opmode = 0, state = 0; //최적화 금지

ISR(INT4_vect) //INT4 인터럽트 처리 루틴 : sw1
{
	opmode++;
	if(opmode >= OPMODEMAX ) opmode=0;
}

ISR(INT5_vect) // INT5 인터럽트
{
	state++;
	if(state >= STATE_MAX)  state= 0;
}
ISR(INT6_vect)

	




int main(void)
{
    /* Replace with your application code */
	//7-segment 사용 : 4 Module - C type
	//	Pin assign : PAx -> Segment img, PBx - module sel
	//Interrupt 사용 : INT4 ~ INT6 (Ext Int)
	//	Pin assign: PE4 ~ PE6
	DDRD = 0xff;
	DDRC = 0x0f;
	EIMSK = 0x70; //0111 0000b
	EICRB = 0x2a; //0010 1010b
	SREG |= 0x80; //status Register - 인터럽트 허용
	sei();		  //set interrupt - 인터럽트 시작
}

	unsigned long t = 0;
	while (1) 
    {
		switch(opmode)
		{
			case 0: // reset & wait 
			t=0; break;
			case 1: // counter start
			t++; break;
			case 2: // count stop
				break;
			default: break;		
		}
		Disp(t);
    }
}