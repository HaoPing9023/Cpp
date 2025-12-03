//题目描述
//一个整数如果按从低位到高位的顺序
//奇数位（个位、百位、万位……）上的数字是奇数
//偶数位（十位、千位、十万位……）上的数字是偶数，我们就称之为“好数”。
//给定一个正整数 N，请计算从 1 到 N 一共有多少个好数。

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
bool check(int n)
{
    int s = 1;
    int flag = 1;
    while (n > 0 && flag == 1)
    {
        int sum = n % 10;
        if (s % 2 == 1) flag = (sum % 2 == 1) ? 1 : 0;
        if (s % 2 == 0) flag = (sum % 2 == 0) ? 1 : 0;
        n /= 10;
        s++;
    }
    return flag;
}
int main()
{
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (check(i)) ans++;
    }
    cout << ans;
}