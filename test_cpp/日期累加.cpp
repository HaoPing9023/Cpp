//#include <climits>
//#include <iostream>
//#include <string>
//#include <ostream>
//using namespace std;
//
//class Date {
//    friend ostream& operator<<(ostream& out, const Date& d);
//public:
//    Date(int year = 0, int month = 0, int day = 0)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    static int GetMonthDay(int year, int month)
//    {
//        static int MonthArrar[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if (month == 2 && ((year % 4 == 0 && year % 100 != 100) && year % 400 == 0))
//            return 29;
//        return MonthArrar[month];
//    }
//    Date& operator-=(int day);
//    Date& operator+=(int day);
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//Date& Date::operator-=(int day)
//{
//    _day -= day;
//    while (_day <= 0)
//    {
//        _month--;
//        if (_month == 0)
//        {
//            _year--;
//            _month = 12;
//        }
//        _day += GetMonthDay(_year, _month);
//    }
//    return *this;
//}
//
//Date& Date::operator+=(int day)
//{
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
//ostream& operator<<(ostream& out, const Date& d)
//{
//
//    out << d._year << "-" << d._month << "-" << d._day << endl;
//    return out;
//}
//int main() {
//    int year, month, day, sum;
//    while (cin >> year >> month >> day >> sum) { // 注意 while 处理多个 case
//        Date s1(year, month, day);
//        Date s2 = s1 += sum;
//        cout << s2;
//    }
//}
//// 64 位输出请用 printf("%lld")