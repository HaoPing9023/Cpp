#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	void print();
	int GetMonthDay(int year, int month)
	{
		static int MonthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((month % 4 == 0 && month % 100 != 0) || month % 400 == 0))
			return 29;
		return MonthDayArray[month];
	}
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	
	Date operator+(int day);
	Date operator+=(int day);
	Date operator-(int day);
private:
	int _year;
	int _month;
	int _day;
};
