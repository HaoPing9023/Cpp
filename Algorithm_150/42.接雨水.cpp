//42.接雨水
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

#include "Algorithm_150.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;

        // leftMax[i] 表示第 i 个柱子左侧（包括自己）出现的最高高度
        // rightMax[i] 表示第 i 个柱子右侧（包括自己）出现的最高高度
        vector<int> leftMax(n), rightMax(n);

        // 核心逻辑：对于位置 i，它能接多少水取决于：
        // min(左边最高, 右边最高) - 当前柱子的高度

        // 从左向右遍历，计算并记录每个位置左侧的最大高度
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            // 当前左侧最大值是（前一个位置左侧最大值）与（当前高度）的较大者
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // 从右向左遍历，计算并记录每个位置右侧的最大高度
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            // 当前右侧最大值是（后一个位置右侧最大值）与（当前高度）的较大者
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int res = 0;
        // 遍历整个高度数组，计算每一列能积攒的水量并累加
        for (int i = 0; i < n; ++i) {
            // 木桶原理：水的深度由左右两侧较矮的那块挡板决定
            // 该公式计算的是第 i 列上方垂直方向积累的水单位
            res += min(leftMax[i], rightMax[i]) - height[i];
        }

        return res;
    }
};