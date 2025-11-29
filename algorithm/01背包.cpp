//小明有一个容量为 V 的背包。
//这天他去商场购物，商场一共有 N 件物品，第 i 件物品的体积为 wi​，价值为vi。
//小明想知道在购买的物品总体积不超过 V 的情况下所能获得的最大价值为多少，请你帮他算算。
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1009;
struct s {
    int w, v;
}a[N];
int f[N];
int main()
{
    int n, s; cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i].w >> a[i].v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = s; j >= a[i].w; --j)
        {
            f[j] = max(f[j], f[j - a[i].w] + a[i].v);
        }
    }
    cout << f[s];
    return 0;
}