//小明发现 49 很有趣，首先，它是个平方数。它可以拆分为 4 和 9，拆分出来的部分也是平方数。
//169 也有这个性质，我们权且称它们为：拼接平方数。
//100 可拆分 1, 00，这有点勉强，我们规定，0, 00, 000 等都不算平方数。
//小明想：还有哪些数字是这样的呢？
//你的任务出现了：找到某个区间的所有拼接平方数。

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;
const int N = 1e6 + 9;
bool a[N];
string s;
bool cmp(int x)
{
    int tmp = sqrt(x);
    if (tmp * tmp == x)
        return true;
    return false;
}
int main()
{
    int l, r; cin >> l >> r;
    for (int i = 1; i <= r; ++i)
    {
        a[i] = cmp(i) ? 1 : 0;
        // if(cmp(i))
        //     a[i] = 1;
    }
    for (int i = l; i <= r; ++i)
    {
        if (a[i])
        {
            s = to_string(i);
            int len = s.size();
            for (int j = 1; j < len; ++j)
            {
                int x = stoi(s.substr(0, j));
                int y = stoi(s.substr(j));
                if (a[x] && a[y])
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}