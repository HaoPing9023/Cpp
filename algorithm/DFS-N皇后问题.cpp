//在 N x N 的方格棋盘放置了 N 个皇后，使得它们不相互攻击
//即任意 2个皇后不允许处在同一排，同一列，也不允许处在与棋盘边框成45 角的斜线上。
//你的任务是，对于给定的 ，求出有多少种合法的放置方法。

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
const int N = 15;
int vis[N][N];
int sum, n;
void dfs(int dep)
{
    if (dep == n + 1)
    {
        sum++;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[dep][i]) continue;
        for (int _i = 1; _i <= n; ++_i) vis[_i][i]++;
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j) vis[_i][_j]++;
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j) vis[_i][_j]++;
        for (int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j) vis[_i][_j]++;
        for (int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j) vis[_i][_j]++;
        dfs(dep + 1);
        for (int _i = 1; _i <= n; ++_i) vis[_i][i]--;
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j) vis[_i][_j]--;
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j) vis[_i][_j]--;
        for (int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j) vis[_i][_j]--;
        for (int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j) vis[_i][_j]--;
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << sum;
    return 0;
}