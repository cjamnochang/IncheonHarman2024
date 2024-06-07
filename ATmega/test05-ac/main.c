/*
 * test05-ac.c
 *
 * Created: 2024-05-31 오후 4:34:03
 * Author : KangHeeJun
 */ 

#include <avr/io.h>
#include "myHeader.h"
#include <avr/interrupt.h>
#include <util/delay.h>

void SegPort(char *p1, char *p2);

int cnt = 0, tcnt = 0;

int read_ADC(void)
{
	while(!(ADCSRA & (1 << ADIF)));

	return ADC;
}
void initADC(int ch)
{
	
	ADMUX |= 1 << REFS0;	// 기준전압 0100 0000
	
	ADCSRA |= 0x07;			// Pre-scaler 분주비 설정
	ADCSRA |= 1 << ADEN;	// ADC 활성화
	ADCSRA |= 1 << ADFR;	// free=running mode 설정
	ADMUX  |= (ADMUX & 0xE0) | ch;
	ADCSRA |= (1 << ADSC);	// ADC 시작
}
int main(void)
{
	DDRD = 0xff;
	DDRC = 0x0f;
	DDRF = 0x00;
	DDRF = 0x04;
	SegPort(&PORTD, &PORTC);
	unsigned int read;
	
	initADC(0); // 1: ch number
	while(1)
	{
		read = read_ADC();
		SegDisp(read);
		_delay_ms(5);
	}
}
