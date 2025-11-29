//N 架飞机准备降落到某个只有一条跑道的机场。
//其中第架飞机在 i 时刻到达机场上空，到达时它的剩余油料还可以继续盘旋 Di 个单位时间，
//即它最早可以于 Ti 时刻开始降落，最晚可以于 Ti + D; 时刻开始降落。降落过程需要 Li 个单位时间。
//一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，但是不能在前一架飞机完成降落前开始降落。
//请你判断 N 架飞机是否可以全部安全降落

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
const int N = 20;
int n, t[N], d[N], l[N];
bool vis[N];
//u: 已经降落的飞机个数，time:上一架飞机降落到地面的时间
bool dfs(int u, int time)
{
    //如果所有飞机都成功降落，返回 true
    if (u >= n) return true;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])   //没搜索过（没降落）的飞机
        {
            vis[i] = true;    //标记为已经降落了
            if (time > t[i] + d[i])    //如果上一架飞机降落的时间 比 这一架飞机最久能盘旋的时间还要久
            {
                vis[i] = false;     //那么说明不能成功降落，不合法，回溯
                return false;       //已经有不能降落的了，后面不用看了
            }
            //找目前这一架飞机最少需要的降落时间
            //虽然最好是在刚到就起飞，但是可能到的时候，前一架飞机还没有落完，所以取max
            int min_time = max(time, t[i]) + l[i];  //这次需要降落的时间就是 最少要预留的时间+降落时间
            //往下搜，能成功降落的数量+1，把这次要降落的时间也传进去
            if (dfs(u + 1, min_time)) return true;  //如果搜到所有的飞机都能成功降落 就返回true
            vis[i] = false;   //回溯，找不同顺序降落
        }
    }
    //如果在上面循环中都没有达到true说明没法成功降落 返回false
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--)
    {
        //memset(vis, 0, sizeof(vis));
        fill(vis, vis + N, 0);    //每次初始化vis数组，不能影响到下一次数据
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> t[i] >> d[i] >> l[i];
        if (dfs(0, 0)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}