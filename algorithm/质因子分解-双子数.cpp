//若一个正整数 x 可以被表示为 p’x q”，
//其中 p、q为质数且p≠q，则 x 是一个双子数。
//请计算区间[2333, 233333333333 内有多少个双子数 ?

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int N = 1e7 + 9;

//欧拉筛法求质数
vector<ll> f(ll n)
{
    vector<ll> s;
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for (ll i = 2; i <= n; ++i)
    {
        if (p[i]) s.push_back(i);
        for (ll j = 0; j < s.size() && i * s[j] <= n; ++j)
        {
            p[i * s[j]] = false;
            if (i % s[j] == 0) break;
        }
    }
    return s;
}
int main()
{
    ll ans = 0;
    auto a = f(N);
    for (int i = 0; i < a.size(); ++i)
    {
        ll pp = (ll)a[i] * a[i];
        if (pp > sqrt(23333333333333)) break;
        for (int j = i + 1; j < a.size(); ++j)
        {
            ll qq = (ll)a[j] * a[j];
            if (qq * pp > 23333333333333) break;
            if (qq * pp < 2333) continue;
            ans++;
        }
    }
    cout << ans;
    return 0;
}