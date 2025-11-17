#define _CRT_SECURE_NO_WARNINGS 1
#include"Date_Calc.h"

void test01()
{
	Date d1(2025, 5, 7);
	Date d2 = d1 + 10000;
	d1.print();
	d2.print();

	Date d3(2025, 11, 17);
	Date d4 = d3 - 10000;
	d3.print();
	d4.print();
	
	d3 += -10000;
	d3.print();
}

void test02()
{
	Date d1(2025, 11, 17);
	Date d2(2025, 5, 7);
	int n = d1 - d2;
	cout << n << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}