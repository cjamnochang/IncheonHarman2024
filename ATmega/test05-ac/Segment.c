/*
 * Segment.c
 *
 * Created: 2024-03-29 오전 11:30:16
 *  Author: KangHeeJun
 */ 

#include "myHeader.h"
//#define F_CPU 16000000L

#include <avr/io.h>
#include <avr/delay.h>

#define SEG_NUM 4

uint8_t digit[] = {0x3F, 0X06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71 };
char arr[SEG_NUM]; // 세그먼트 이미지 정보를 담을 안전 영역
char *PA = &PORTD, *PB = &PORTC;
int segType = 1; // 1 : C-Type, 0 : A-Type

void SegPort(char *p1, char *p2)
{
	PA = p1; PB = p2;
}
void SegType(int tp)
{
	segType = tp;
}
void seg(int sel, uint8_t c)
{
	if(segType)
	{
		*PB |= 0X0F;
		*PB &= ~(1 << (SEG_NUM-1-sel));
		*PA = c;		// 숫자 데이터 출력
	}
	else
	{
		*PB &= 0xF0;
		*PB |= (1 << (SEG_NUM-1-sel));
		*PA = ~c;		// 숫자 데이터 출력
	}
	//_delay_us(1);	// 0.01 초 간격으로 전환
}

int digitNum = SEG_NUM;
void FND_4(char *inf) // segment Image 배열
{
	int i;
	for(i = 0;i < digitNum;i++)
	{
		seg(i, *(inf+i));
		_delay_ms(5);
	}
}

char* SegDispX(unsigned long num)  // 10진 정수 ==> 16진수 문자열 : 56506 ==> 0xDCBA
//		   ==> 4 digit 16진수 segment 출력
{
	num %= 65536;
	int n1 = num % 16;			// A (10) : 문자가 아닌 숫자
	int n2 = (num / 16) % 16;	// B (11)
	int n3 = (num / 256 ) % 16;	// C (12)
	int n4 = (num / 4096);		// D (13)
	arr[0] = digit[n1];
	arr[1] = digit[n2];
	arr[2] = digit[n3];
	arr[3] = digit[n4];
	digitNum = (num > 4095) ? 4 : (num > 256) ? 3 : (num > 16) ? 2 : 1;
	FND_4(arr);
	return arr;
}
char* SegDisp(unsigned long num)  // 4321  4 digit 10진수 segment 출력
{
	int n1 = num % 10;			// 1  : 문자가 아닌 숫자
	int n2 = (num / 10) % 10;	// 2
	int n3 = (num / 100 ) % 10;	// 3
	int n4 = (num / 1000);		// 4
	arr[0] = digit[n1];
	arr[1] = digit[n2];
	arr[2] = digit[n3];
	arr[3] = digit[n4];
	digitNum = (num > 999) ? 4 : (num > 99) ? 3 : (num > 9) ? 2 : 1;
	FND_4(arr);
	return arr;
}