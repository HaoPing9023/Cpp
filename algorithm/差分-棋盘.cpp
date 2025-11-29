//小明拥有 n xn 大小的棋盘，一开始棋盘上全都是白子。
//小明进行了m 次操作，每次操作会将棋盘上某个范围内的所有棋子的颜色取反
//(也就是白色棋子变为黑色，黑色棋子变为白色)。
//请输出所有操作做完后棋盘上每个棋子的颜色。

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
const int N = 2e3 + 9;
int a[N][N];
void f(int xx1, int yy1, int xx2, int yy2)
{
    a[xx1][yy1]++;
    a[xx1][yy2 + 1]--;
    a[xx2 + 1][yy1]--;
    a[xx2 + 1][yy2 + 1]++;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    int xx1, yy1, xx2, yy2;
    while (m--)
    {
        cin >> xx1 >> yy1 >> xx2 >> yy2;
        f(xx1, yy1, xx2, yy2);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << (a[i][j] % 2) ? '1' : '0';
        }
        cout << '\n';
    }
    return 0;
}