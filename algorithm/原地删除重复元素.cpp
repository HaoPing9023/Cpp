//给你一个 非严格递增排列 的数组 nums 
//，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
//返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
//
//考虑 nums 的唯一元素的数量为 k。去重后，返回唯一元素的数量 k。
//
//nums 的前 k 个元素应包含 排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略。
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//解法一（内部函数）sort + unique + erase
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto new_end = unique(nums.begin(), nums.end());
        nums.erase(new_end, nums.end());
        return nums.size();
    }
};

//解法二（双指针）
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int fast = 1, slow = 1;
        while (fast != n)
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};