//118.杨辉三角
//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。

#include"Algorithm_150.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            ret[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j)
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
        return ret;
    }
};