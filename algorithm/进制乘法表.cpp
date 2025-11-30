//题目描述
//九九乘法表是学习乘法时必须要掌握的。在不同进制数下，需要不同的乘法表。
//例如, 四进制下的乘法表如下所示：
//1 * 1 = 1
//2 * 1 = 2 2 * 2 = 10
//3 * 1 = 3 3 * 2 = 12 3 * 3 = 21
//请注意，乘法表中两个数相乘的顺序必须为样例中所示的顺序，不能随意交换两个乘数。
//给定 P，请输出 P 进制下的乘法表。

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
using namespace std;

string jz(int x, int y)
{
    string res;
    while (x)
    {
        int add = x % y;
        if (add >= 10)
            res += add - 10 + 'A';
        else
            res += add + '0';
        x /= y;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n; cin >> n;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << jz(i, n) << '*' << jz(j, n) << '=' << jz(i * j, n) << " ";
        }
        cout << '\n';
    }
    return 0;
}