/*#include <stdio.h>

int main()
{
	printf("숫자 키를 입력하세요. 해당하는 영단어를 알려드리겠습니다.");
	printf("프로그램을 끝내시려면 'Q'키를 입력하세요. \n\n");
	while (1)
	{
		char c = getch();
		//printf("%c", c);if (c == '1') printf("%c : One\n", c);
		else if (c == '2') printf("%c : Two\n", c);
		else if (c == '3') printf("%c : Three\n", c);
		else if (c | 0x20 == 'q') break; //40H 60H
	}

	/*
while (n)

{
	//printf(">");
	//char c = getch(); // no echo : 키값을 출력하지 않고 반환
	//char c1 = getchar(); // [enter] 필요.

	//if (c == '1') printf("%c : One\n", c);
	//else if (c == '2') printf("%c : Two\n", c);
	//else if (c == '3') printf("%c : Three\n", c);
	//else if (c | 0x20 == 'q') break; //40H 60H
}


switch(c)
{
case '1': printf("%c : One\n", c); break;
case '2': printf("%c : Two\n", c); break;
case '3': printf("%c : Three\n", c); break;
case 'q':
case 'Q': n = 0; break;
}
*/
}
/*
int main()
{
	char* str{ ... } ` {"One ", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Zero")"; //문자열 포인터 배열}
	printf{ "숫자 키를 입력하세요. 해당하는 영단어를 알려드리겠습니다.");
	printf("프로그램을 끝내시려면 "Q" 키를 입력하세요.\n\n");
	int n = 1;
	while (n) { ... }
	
	{
		printf(">");
		char c = getch(); // no echo : 키값을 출력하지 않고 반환
		/*_*/
		/*
		int m = c - 0x30; // ASCII --> num
		printf("%c, : %s\n", c, str[c - 0x30]);

}
*/
#include <stdio.h>
#include <conio.h>
	{
		//test01();
		test02(1);
	}

int test01();
void test02(int a)	// 문자열과 문자배열
{
	char ca[] = "Hello"; //ca[0]:'H' ... ca[4]:'o' ca [5]:\0
	for (int i = 0; i < 10; i++) // 0~5
	{
		printf("ca[%d] : %c(%02x)\n", i, ca[i], ca[i]);
	}
	ca[2] -= 1;
	ca[3] -= 1;
	for (int i = 0; i < 10; i++) // 0~5
	{
		printf("ca[%d] : %c (%02x)\n", i, ca[i], ca[i]);
	}
}
