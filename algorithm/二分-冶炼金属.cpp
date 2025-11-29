//小明有一个神奇的炉子用于将普通金属 O 冶炼成为一种特殊金属X
//这个炉子有一个称作转换率的属性 V，V是一个正整数，
//这意味着消耗 V 个普通金属 O 恰好可以冶炼出一个特殊金属 X，
//当普通金属 O的数目不足 V 时，无法继续冶炼。
//现在给出了 N 条冶炼记录，每条记录中包含两个整数 A和 B，
//这表示本次投入了 A 个普通金属 O，最终冶炼出了 B 个特殊金属 X。
//每条记录都是独立的，这意味着上一次没消耗完的普通金属 0 不会累加到下一次的冶炼当中。
//根据这 N 条冶炼记录，请你推测出转换率 V 的最小值和最大值分别可能是多少，
//题目保证评测数据不存在无解的情况。
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int a[N], b[N], n;
//mid越小，a[i]/mid 越大
//所以check1是找最大值的
bool check1(int mid)
{
    for (int i = 1; i <= n; ++i)
    {
        //如果a[i]/mid 小于 的话，说明mid太大了
        //那么为false时，要使mid减小，也就是r = mid;
        if (a[i] / mid < b[i])return false;
    }
    return true;
}
bool check2(int mid)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] / mid > b[i])return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    int l = 0, r = 1e9 + 1;
    int mi = 0, mx = 0;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (check1(mid))
        {
            mx = mid;
            l = mid;
        }
        else r = mid;
    }
    l = 0, r = 1e9 + 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (check2(mid))
        {
            mi = mid;
            r = mid;
        }
        else l = mid;
    }
    cout << mi << ' ' << mx;
    return 0;
}