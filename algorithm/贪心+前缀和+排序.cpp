//在王国中，有n名士兵，这些士兵需要接受一系列特殊的训练以提升他们的战斗技能。
//对于第i名士兵来说，进行一次训练所需的成本为 pi 枚金币，
//而要想成为顶尖战士，他至少需要进行 ci 次训练。
//为了确保训练的高效性，王国推出了一种组团训练的方案。
//该方案包含每位士兵所需的一次训练，且总共只需支付 S 枚金币
//(组团训练方案可以多次购买，即士兵可以进行多次组团训练)
//作为训练指挥官，请你计算出最少需要花费多少金币，才能使得所有的士兵都成为顶尖战士 ?

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;  //因为是遍历差分数组 所以范围取c（最大）
ll diff[N], res, mx;
int main()
{
    ll n, k; cin >> n >> k;
    ll p, c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p >> c;
        //取后续diff要遍历的范围
        mx = max(mx, c);
        //差分 因为至少需要一次训练
        //从一次训练开始 到c次训练相加要的金币数
        //c+1次训练 就不需要再加上前面训练次数的金币了 就减回来
        diff[1] += p;
        diff[c + 1] -= p;
    }
    //做一次前缀和恢复原数组
    for (int i = 1; i <= mx; ++i) diff[i] += diff[i - 1];
    //每个数组代表着第i次训练单次训练的总体费用，和整体训练的费用取小
    //只加最小的金币数（整体训练只要比单独训练更便宜 就整体训练）
    for (int i = 1; i <= mx; ++i) res += min(diff[i], k);
    cout << res;
    return 0;
}