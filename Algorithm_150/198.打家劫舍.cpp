//198.打家劫舍
//你是一个专业的小偷，计划偷窃沿街的房屋。
//每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组
//计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额

#include"Algorithm_150.h"

class Solution {
public:
    // dfs写法
    // int res = 0;
    // int mem[405];
    // int dfs(vector<int>& nums,int x)
    // {   
    //     if(x >= nums.size()) return 0;
    //     if(mem[x]) return mem[x];
    //     res = max(dfs(nums,x + 1),dfs(nums,x + 2) + nums[x]);
    //     mem[x] = res;
    //     return res;
    // }

    // 动态规划写法
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 2);
        for (int i = 0; i < n; ++i)
        {
            f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        }
        return f[n + 1];
    }
};