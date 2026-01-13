//33.搜索旋转排序数组
//整数数组 nums 按升序排列，数组中的值 互不相同 。
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）
//上进行了 向左旋转，使数组变为[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], 
//nums[1], ..., nums[k - 1]]（下标 从 0 开始 计数）。
//例如，[0, 1, 2, 4, 5, 6, 7] 下标 3 上向左旋转后可能变为[4, 5, 6, 7, 0, 1, 2] 。
//给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，
//则返回它的下标，否则返回 - 1 。
//你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

#include"Algorithm_150.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;
        int mid = 0;
        while (l + 1 < r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid])
            {
                if (target < nums[mid] && target >= nums[0])
                    r = mid;
                else l = mid;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r - 1])
                    l = mid;
                else r = mid;
            }

        }
        return -1;
    }
};