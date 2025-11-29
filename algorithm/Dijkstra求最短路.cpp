//给定一张 n 个点 m 条边的有向图，该图可以有自环与重边。
//你需要输出 1号点到 几 号点的最短路，若不存在此最短路，输出 - 1。

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>   
#include <vector>     
#include <queue>      
#include <utility>   
#include <algorithm>   
#include <functional>  

using namespace std;
using ll = long long;

const int N = 1e5 + 9;
constexpr ll inf = 1E18;

priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
vector<pair<int,ll>> v[N];
int n, m;
ll dist[N];

void dij(int start)
{
    pq.emplace(0LL, start);
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;  // 过期状态
        if (u == n) return;         // 提前结束（到达终点）

        for (auto [y, w] : v[u])
        {
            if (dist[y] > dist[u] + w)
            {
                dist[y] = dist[u] + w;
                pq.emplace(dist[y], y);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    fill(dist, dist + N, inf);

    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
    }

    dij(1);

    if (dist[n] == inf) cout << -1;
    else cout << dist[n];

    return 0;
}
