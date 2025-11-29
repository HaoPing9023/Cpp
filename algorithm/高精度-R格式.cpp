//小明最近在研究一种浮点数的表示方法: R 格式。
//对于一个大于0的浮点数 d，可以用 R 格式的整数来表示。
//给定一个转换参数 n，将浮点数转换为 R 格式整数的做法是 :
//	1.将浮点数乘以 2^n
//	2.四舍五入到最接近的整数。

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;
vector<int> a;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; string s;
    cin >> n >> s;
    int len = s.size();
    for (int i = len - 1; i >= 0; --i)
    {
        if (s[i] != '.') a.push_back(s[i] - '0');
        else x = i;
    }
    x = len - x - 1;
    for (int i = 0; i < n; ++i)
    {
        int ans = 0;
        for (int j = 0; j < a.size(); ++j)
        {
            a[j] *= 2;
            a[j] += ans;
            ans = a[j] / 10;
            a[j] %= 10;
        }
        if (ans) a.push_back(ans);
    }
    if (a[x - 1] >= 5) a[x]++;
    for (int i = a.size() - 1; i >= x; --i) cout << a[i];
    return 0;
}