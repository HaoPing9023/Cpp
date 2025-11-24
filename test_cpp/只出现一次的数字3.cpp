//#define _CRT_SECURE_NO_WARNINGS 1
////给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 
////找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
////你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//
////解法一：异或
//class Solution1 {
//public:
//    vector<int> singleNumber(vector<int>& nums) {
//        unsigned int xor_all = 0;
//        for (auto x : nums)
//            xor_all ^= x;
//        vector<int> ans(2);
//        int lowbit = xor_all & (-xor_all);
//        for (auto x : nums)
//            ans[(x & lowbit) != 0] ^= x;
//        return ans;
//    }
//};
//
////解法二：哈希表
//class Solution2 {
//public:
//    vector<int> singleNumber(vector<int>& nums) {
//        map<int, int> mp;
//        for (auto& x : nums)
//            mp[x]++;
//        vector<int> res;
//        for (auto& x : mp)
//            if (x.second == 1) res.push_back(x.first);
//        return res;
//    }
//};