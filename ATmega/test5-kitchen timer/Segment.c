﻿/*
 * Segment.c
 *
 * Created: 2024-03-29 오후 4:04:00
 *  Author: KangHeeJun
 */ 
#define F_CPU 16000000L		//Board CLK 정보(16MHz)
#include <avr/io.h>
#include <avr/delay.h>

#define OPTMAX 3
#define STATEMAX 3

uint8_t digit[] = {	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71 };
uint8_t character[] = { // -,
0x40, 0 };

char arr[5];		//세그먼트 이미지 정보를 담을 안전공간
char *PD = &PORTD, *PC = &PORTC;	//포트 변수화

void SegPortSet(char *p1, char *p2){
	PD = p1; PC = p2;
}
void seg(int sel, uint8_t c){
	*PC |= 0X0F;
	*PC &= ~(1 << (3-sel));
	*PD = c;	//숫자 데이터 출력
	_delay_ms(2);
}


void FND_4(char *inf){	//segment Image 배열
	for (int i = 0; i < 4; i++){
		seg(i, *(inf+i));

	}
}

//16진수 segment image 배열
char* Display(unsigned long num){	//10진 정수를 입력받아 16진수 문자열로 변환 ex)65535 ==> 0xffff, 56506=>0xBCDA
	int n1 = num % 10;			//A(10): 문자가 아닌 숫자
	int n2 = (num / 10) % 6;	//B(11)
	int n3 = (num / 60) % 10;	//C(12)
	int n4 = (num / 600) % 6;		//D(13)
	
	arr[0] = digit[n1]; arr[1] = digit[n2]; arr[2] = digit[n3] + 0x80; arr[3] = digit[n4];
	
	if ( num< 10 ){
		arr[3] = 0; arr[1] = 0; arr[2] = 0x80;
	}
	else if ( num<60 ){
		arr[2] = 0x80; arr[3] = 0;
	}
	else if ( num<600 ){
		arr[3] = 0;
	}
	
	FND_4(arr);
	return arr;
}

void display_digit(int position, int number){
	PORTC |= 0x0F;
	PORTC &= ~(1 << (position - 1));
	
	PORTD = digit[number];
}
void display_character(int position, int number){
	PORTC |= 0x0F;
	PORTC &= ~(1 << (position - 1));
	
	PORTD = character[number];
}