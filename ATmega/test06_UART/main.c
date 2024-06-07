/*
 * test06_UART.c
 *
 * Created: 2024-06-07 오전 11:01:46
 * Author : KangHeeJun
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/delay.h>

void initUART0() //UART 초기화 작업
{	//	9600N81
	UBRR0H = 0;
	UBRR0L = 207;	//Baud rate : 9600

	UCSR0A |= (1 << 1);	//   0000 0010b 2배속 설정
	
	UCSR0B |= ( 1<< RXEN0)| (1 << TXEN0);	//Rx/Tx Enable	
	UCSR0C |= 0x06;	// Data bit : 8	x11x		0000 0110b	N81
					// Stop bit : 1 0xxx
}

void uPutc(char c)  //문자만 출력
{
	//while(1)
	//{
		//if(UCSR0A & (1<<UDRE0)) == 1) break;	//Wait until data empty bit test 1
	//}
	while(!(UCSR0A & (1<<UDRE0)));	//Wait until data empty bit test 1
	UDR0 = c; // send
}
void uPuts(char *str) //문자열
{
	while(*str) uPutc(*str++);
	
	/*while(1)
	{
		if(*str == 0) break;
		uPutc(*str);  // *str : value
		str++;		  // str++: pointer 연산
	}
	*/
}
unsigned char buf[1024];
void bPrint()
{
	uPuts(buf);
}

int main(void)
{
	/* Replace with your application code */
	initUART0();
	char a = '0';
	int i = 0;
	uPuts("안녕하세요....^^..\r\n");
	while (1)
	{
		//uPutc(a++);
		sprintf(buf, "ATmega128 터미널 출력 테스트...#%d\r\n", i++); bPrint();
		_delay_ms(1000);
		//if(a > '9') a = '0';
	}
}

