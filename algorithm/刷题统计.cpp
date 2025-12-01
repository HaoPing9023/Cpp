//小明决定从下周一开始努力刷题。
//他计划周一至周五每天做 a 道题目，周六和周日每天做 b 道题目。
//请你帮小明计算，按照计划他将在第几天实现做题数大于等于 n 题 ?
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
using ll = long long;
using namespace std;

int main()
{
    ll a, b; cin >> a >> b;
    ll n; cin >> n;
    ll week = a * 5 + b * 2;
    ll count = (n / week) * 7;
    n %= week;
    for (int i = 0; i < 5; ++i)
    {
        n -= a;
        ++count;
        if (n <= 0)
        {
            cout << count << endl;
            return 0;

        }
    }
    for (int i = 0; i < 2; ++i)
    {
        n -= b;
        ++count;
        if (n <= 0)
        {
            cout << count << endl;
            return 0;
        }
    }
    return 0;
}