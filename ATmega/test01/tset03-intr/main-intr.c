/*
 * tset03-intr.c
 *
 * Created: 2024-03-27 오후 12:25:35
 * Author : SYSTEM-00
 */ 
#define F_CPU 16000000L

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


char arr[5];//세그먼트 이미지 정보를 담을 안전영역
ISR(INT4_vect) //INT4 인터럽트 처리 루틴 : sw1
{
	opmode++;
	if(opmode >=OPMODEMAX ) opmode=0;
}

ISR(INT5_vect) // INT5 인터럽트
{
	state++;
	if(state>=STATE_MAX)  state= 0;
}
ISR(INT6_vect)
{
	
}


void LED(char* p,int n) //n : n번째 비트 0-7, delay in ms
{
	char b = 1 <<n;
	*p= b;
	_delay_ms(500);
	*p &= ~b;// PORTA의 0번째 비트를 LOW로 출력
	_delay_ms(500);
}
//LED(PORTD,0);

void seg(int sel, uint8_t c)
{
	int i = 0;
	PORTC |= 0x0f;
	PORTC &= ~(1<<(3-sel));
	//PORTC &= ~(1<<sel);
	PORTD = c;
	_delay_ms(5);
}

void FND_4(char *inf) // segment Image 배열
{
	for(int i = 0; i< 4 ; i++)
	{
		seg(i, *(inf+i));
	}
	
}
//문자열 고려서 안전영역 고려
//정적변수 영역에 부여
char* Disp(unsigned long num)//10진수 정수 ==> 16진수 문자열로 변환 : 65535 ==> 0xFFFF, 56506 ==> 0xDCBA
{								//16비트 세그문트 이미지 배열
	int n1 = num%0x10;			//A 1		:문자가 아닌 숫자
	int n2 = (num/0x10)%16;		//B 16		:
	int n3 = (num/0x100)%16;	//C 256
	int n4 = num/0x1000;		//D 4096	
	if(!(num/0x1000))
	{
		n4=17;
		if(!(num/0x100))
		{
			n3=17;
			if(!(num/0x10))n2=17;
		}
	}
	arr[0] = digit[n1];//char 1byte cast() LED문자로 표현
	arr[1] = digit[n2];
	arr[2] = digit[n3];
	arr[3] = digit[n4];
	//+, - 빠름
	//* 실수 연산 여러 클럭 사용
	//'/' 연산 여러 클럭 사용
	FND_4(arr);
	//return arr;
}

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
