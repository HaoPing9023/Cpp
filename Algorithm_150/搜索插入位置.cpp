//35.搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。

#include"Algorithm_150.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;
        int mid = 0;
        while (l + 1 < r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid;
            else r = mid;
        }
        return l + 1;
    }
};