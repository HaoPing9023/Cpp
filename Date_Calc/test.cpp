#define _CRT_SECURE_NO_WARNINGS 1
#include"Date_Calc.h"

int main()
{
	Date d1(2025, 11, 16);
	Date d2 = d1 + 100;
	d1.print();
	d2.print();
	return 0;
}