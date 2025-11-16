#define _CRT_SECURE_NO_WARNINGS 1
#include"Date_Calc.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	//if (!CheckDay())
	//	cout << "日期不合法" << endl;
}

void Date::print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	/*_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}*/
	return tmp;
}