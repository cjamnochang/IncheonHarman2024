/*#include <stdio.h>

int main()
{
	printf("���� Ű�� �Է��ϼ���. �ش��ϴ� ���ܾ �˷��帮�ڽ��ϴ�.");
	printf("���α׷��� �����÷��� 'Q'Ű�� �Է��ϼ���. \n\n");
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
	//char c = getch(); // no echo : Ű���� ������� �ʰ� ��ȯ
	//char c1 = getchar(); // [enter] �ʿ�.

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
	char* str{ ... } ` {"One ", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Zero")"; //���ڿ� ������ �迭}
	printf{ "���� Ű�� �Է��ϼ���. �ش��ϴ� ���ܾ �˷��帮�ڽ��ϴ�.");
	printf("���α׷��� �����÷��� "Q" Ű�� �Է��ϼ���.\n\n");
	int n = 1;
	while (n) { ... }
	
	{
		printf(">");
		char c = getch(); // no echo : Ű���� ������� �ʰ� ��ȯ
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
void test02(int a)	// ���ڿ��� ���ڹ迭
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