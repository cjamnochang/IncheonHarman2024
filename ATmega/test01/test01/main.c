/*
 * test01.c
 *
 * Created: 2024-03-20 오전 11:42:06
 * Author : SYSTEM-00
 */ 
#define F_CPU 16000000L  //CPU 클럭 주파수 16MH

#include <avr/io.h>
#include <avr/delay.h>
const int __delay_t = 500;


void TogglePinA(int n, uint32_t dl)  // n : n번째 비트, dl : delay in mlli-second
{
		char b = 1 << n;
		PORTA |= b;  // ProtA의 n번째 비트를 HIGH로 출력
		_delay_ms(500);
		PORTA &= ~ b;  //partA의 n번째 비트를 LOW로 출력
		_delay_ms(500);
}

int main(void)
{
    /* Replace with your application code */
	DDRA |= 0x07; // A Port의 0,1,2번째 비트를 출력용으로 사용, 나머지는 입력
	DDRB &= ~0x01;  //PortB의 0번째 비트를 입력용으로 사용, 나머지는 그대로 유지 
    int mode = 0;  // mode1:RED mode2:Green mode3:Blue flash
	while (1) 
	{
		//if(PINB & 0x01 == 1) //SW가 안눌렸을 때 true
		if(!(PINB & 0x01 == 1)) // SW가 눌렸을 때 true
		{
			mode++;
			if(mode>=3) mode = 0;
		}
		switch(mode)
		{
			case 0:
			TogglePinA(0,__delay_t); // PortA의 0번째 비트를 점멸
			break; 
			case 1:
			TogglePinA(1,__delay_t); // PortA의 1번째 비트를 점멸
			break;
			case 2:
			TogglePinA(2,__delay_t); // PortA의 2번째 비트를 점멸
			break;
			default: mode = 0;
		}


		}
    
}

