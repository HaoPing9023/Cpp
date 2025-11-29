//小明是学校里的一名老师，他带的班级共有几名同学，第之名同学力量值为 ai。
//在闲暇之余，小明决定在班级里组织一场拔河比赛。
//为了保证比赛的双方实力尽可能相近，需要在这n 名同学中挑选出两个队伍，
//队伍内的同学编号连续 : {al1, al1 + 1, .., ar1 - 1, ar1}和{ al2,al2 + 1,...,ar2 - 1,ar2 }，
//其中 l1 <= r1 < l2 < r2.
//两个队伍的人数不必相同，但是需要让队伍内的同学们的力量值之和尽可能相近。
//请计算出力量值之和差距最小的挑选队伍的方式。
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int N = 1e3 + 9;
ll n, a[N], pre[N], res[N * N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];   //先做一次前缀和表示把所有人都上的话值都为多少
    int ans = 1;
    for (int i = 1; i <= n; ++i)   //因为不是必须上全部同学 所以j 从 i 开始
        for (int j = i; j <= n; ++j) res[ans++] = pre[j] - pre[i - 1];   //枚举所有可能 保存在res数组中
    sort(res + 1, res + 1 + ans);  //为了找最小差 需要排序
    ll mi = 1e10;
    // res 必须 从第 2 开始
    for (int i = 2; i <= ans; ++i) mi = min(mi, res[i] - res[i - 1]);
    cout << mi;
    return 0;
}