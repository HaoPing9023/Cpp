//小明和小乔正在森林里砍柴，它们有 根长度分别为 n1, n2 ... nT 的木头。
//对于每个初始长度为 n 的木头，小明和小乔准备进行交替砍柴，小明先出手。
//每次砍柴时，若当前木头长度为 x，需要砍下一截长度为p的木头，然后换另一个人继续砍。
//其中2 <= p <= x 且p必须为质数。当轮到某一方时x = 1或x = 0，它就没法继续砍柴，它就输了。
//它们会使用最优策略进行砍柴。
//请对每根木头判断是小明赢还是小乔赢，如果小明赢请输出1(数字 1)，如果小乔赢请输出 0(数字 0)

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 9;
vector<int> f(int n)    //欧拉筛法得出n之前的所有质数 存储在vector<int> a 中
{
    vector<int> a;
    vector<bool> p(n + 1, 1);
    for (int i = 2; i <= n; ++i)
    {
        if (p[i]) a.push_back(i);
        for (int j = 0; j < a.size() && i * a[j] <= n; ++j)
        {
            p[i * a[j]] = false;
            if (i % a[j] == 0) break;
        }
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> a = f(1e5);   //存储所有最大范围中的所有质数
    vector<bool> dp(1e5 + 1, 0);   //dp存储 能否必胜
    for (int i = 2; i <= 1e5; ++i)
    {
        for (int j = 0; j < a.size() && i >= a[j]; ++j)
        {
            //枚举每一种小于i的质数，计算如果使用这个质数后 能否得到下一个人的必败态
            if (dp[i - a[j]] == 0)   //若可以，说明存在这种质数的选择 可以达到必胜态
            {
                dp[i] = 1;    //得到这种必胜态的可能，直接选，不需要再看别的了 break
                break;
            }
        }
    }
    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}