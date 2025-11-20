//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//    Date(int year = 0, int month = 0, int day = 0)
//        : _year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    int GetMonthDay(int year, int month)
//    {
//        static int MonthArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//            return 29;
//        return MonthArray[month];
//    }
//    bool operator<(const Date& d) const;
//    bool operator==(const Date& d) const;
//    bool operator!=(const Date& d) const;
//    Date& operator+=(int day);
//    Date& operator++();
//    Date& operator-=(int day);
//    int operator-(const Date& d) const;
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//bool Date::operator<(const Date& d) const
//{
//    if (_year < d._year)
//        return true;
//    else if (_year == d._year)
//    {
//        if (_month < d._month)
//            return true;
//        else if (_month == d._month)
//            return _day < d._day;
//    }
//    return false;
//}
//
//bool Date::operator==(const Date& d) const
//{
//    return _year == d._year
//        && _month == d._month
//        && _day == d._day;
//}
//
//bool Date::operator!=(const Date& d) const
//{
//    return !(*this == d);
//}
//
//Date& Date::operator-=(int day)
//{
//    if (day < 0) day += -day;
//    
//}
//Date& Date::operator+=(int day)
//{
//    if (day < 0) return *this-= -day;
//    _day += day;
//    while (_day > GetMonthDay(_year, _month))
//    {
//        _day -= GetMonthDay(_year, _month);
//        _month++;
//        if (_month == 13)
//        {
//            _year++;
//            _month = 1;
//        }
//    }
//    return *this;
//}
//
//Date& Date::operator++()
//{
//    *this += 1;
//    return *this;
//}
//
//
//
//int Date::operator-(const Date& d) const
//{
//    Date max = *this;
//    Date min = d;
//    int flag = 1;
//    if (*this < d)
//    {
//        max = d;
//        min = *this;
//        flag = -1;
//    }
//    int res = 0;
//    while (min != max)
//    {
//        ++min;
//        ++res;
//    }
//    return res * flag;
//}
//
//
//int main() {
//    int a, b;
//    while (cin >> a >> b) { // 注意 while 处理多个 case
//        Date s1(a / 10000, (a / 100) % 100, a % 100);
//        Date s2(b / 10000, (b / 100) % 100, b % 100);
//        cout << s1 - s2 << endl;
//    }
//    return 0;
//}
//// 64 位输出请用 printf("%lld")