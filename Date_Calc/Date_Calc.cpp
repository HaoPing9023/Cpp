#define _CRT_SECURE_NO_WARNINGS 1
#include"Date_Calc.h"

bool Date::CheckDate()
{
	if (_month < 1 || _month > 12
		|| _day< 1 || _day > GetMonthDay(_year, _month))
		return false;
	else
		return true;

}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!CheckDate())
		cout << "日期不合法" << endl;
}

void Date::print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date& Date::operator+=(int day)
{
	if (day < 0) return *this -= -day;
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

	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0) return *this += -day;
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day) 
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

bool Date::operator<(const Date& d)const
{
	if (_year < d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month < d._month)
			return true;
		else if (_month == d._month)
			return _day < d._day;
	}
	return false;
}
bool Date::operator<=(const Date& d)const
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d)const
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d)const
{
	return !(*this < d);
}
bool Date::operator==(const Date& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

int Date::operator-(const Date& d)const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	}
	return flag * n;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	cout << "请依次输入年月日：" << endl;

	while (1)
	{
		in >> d._year >> d._month >> d._day;
		if (!d.CheckDate())
			cout << "日期非法" << endl;
		else break;
	}
	return in;
}