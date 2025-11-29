//小明正在数轴上挖矿，数轴上一共有n个矿洞，第i个矿洞的坐标为ai。
//小明从0出发，每次可以向左或向右移动 1的距离，当路过一个矿洞时，就会进行挖矿作业，
//获得1单位矿石，但一个矿洞不能被多次挖掘。
//小明想知道在移动距离不超过 m 的前提下，最多能获得多少单位矿石 ?

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
const int N = 1e7 + 9;
int l[N], r[N], zero;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        if (x < 0) l[abs(x)]++;
        else if (x > 0) r[x]++;
        else zero++;
    }
    for (int i = 1; i <= m; ++i)
    {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }
    int res = 0;
    for (int i = 1; i <= m; ++i)
    {
        int ans = m - (i * 2);
        int sum1 = l[i];
        int sum2 = r[i];
        if (ans > 0)
        {
            sum1 += r[ans];
            sum2 += l[ans];
        }
        res = max({ res,sum1,sum2 });
    }
    cout << res + zero;
    return 0;
}