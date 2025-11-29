//小明是王国的骑士，他喜欢不断突破自我。
//这天国王给他安排了N 个对手，他们的战力值分别为a1​, a2​ ... an，
//且按顺序阻挡在小明的前方。对于这些对手小明可以选择挑战，也可以选择避战。
//身为高傲的骑士，小明从不走回头路，且只愿意挑战战力值越来越高的对手。
//请你算算小明最多会挑战多少名对手。

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 3e5 + 9;
int a[N], f[N];
int main()
{
    // int n; cin >> n;
    // for(int i = 1; i <= n; ++i) cin >> a[i];
    // for(int i = 1; i <= n; ++i)
    // {
    //   f[i] = 1;
    //   for(int j = 1; j <= n; ++j)
    //   {
    //     if(a[j] < a[i])
    //       f[i] = max(f[i], f[j] + 1);
    //   }
    // }
    // cout << f[n];
    // return 0;
    int n; cin >> n;
    vector<int> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (s.empty() || a[i] > s.back())
            s.push_back(a[i]);
        else
        {
            int pos = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
            s[pos] = a[i];
        }
    }
    cout << s.size();
    return 0;
}