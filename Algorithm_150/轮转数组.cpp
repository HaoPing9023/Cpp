//189.轮转数组
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
#include"Algorithm_150.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = (int)nums.size();
        if (len == 0) return;
        k %= len;
        if (k == 0) return;

        reverse(nums.begin(), nums.begin() + (len - k));
        reverse(nums.begin() + (len - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};