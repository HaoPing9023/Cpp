//小明拥有 N 个彩灯，第之个彩灯的初始亮度为 ai。
//小明将进行 Q 次操作，每次操作可选择一段区间，并使区间内彩灯的亮度 + (可能为负数)。
//求 Q 次操作后每个彩灯的亮度(若彩灯亮度为负数则输出 0)

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
using ll = long long;
const int N = 5e5 + 9;
ll a[N], diff[N];
int main()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) diff[i] = a[i] - a[i - 1];
    while (q--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }
    for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + diff[i];
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < 0) cout << 0 << ' ';
        else cout << a[i] << ' ';
    }
    return 0;
}