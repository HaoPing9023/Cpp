//题目描述
//在一个行列的方格图上有一些位置有地雷，另外一些位置为空。
//请为每个空位置标一个整数，表示周围八个相邻的方格中有多少个地雷。
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <algorithm>


#define x first
#define y second
using namespace std;
const int N = 109;
int g[N][N], dist[N][N], n, m;
typedef pair<int, int> PII;
queue<PII> q;
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
void bfs()
{
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 8; ++i)
        {
            int a = t.x + dx[i];
            int b = t.y + dy[i];
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (g[a][b] == 1) cnt++;
        }
        dist[t.x][t.y] = cnt;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> g[i][j];
            if (g[i][j] == 1) dist[i][j] = 9;
            else q.push({ i, j });
        }
    }
    bfs();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j) cout << dist[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}