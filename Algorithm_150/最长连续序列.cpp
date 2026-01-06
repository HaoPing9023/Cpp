//给定一个未排序的整数数组 nums 
//找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

#include"Algorithm_150.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int res = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int cur = num;
                int streak = 1;

                while (num_set.count(cur + 1)) {
                    cur += 1;
                    streak += 1;
                }

                res = max(res, streak);
            }
        }

        return res;
    }
};
