//给一个长度为 n 的数组，
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组[1, 2, 3, 2, 2, 2, 5, 4, 2]。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//解法一（哈希表）
class Solution1 {
public:
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        map<int, int> mp;
        for (auto& e : numbers)
        {
            mp[e]++;
        }
        int n = numbers.size();
        for (auto& e : mp)
        {
            if (e.second > n / 2) return e.first;
        }
        return -1;
    }
};

//解法二（投票/候选人算法）
class Solution2 {
public:
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        int cond = -1, cnf = 0;
        for (auto& e : numbers)
        {
            if (cnf == 0)
            {
                cond = e;
                ++cnf;
            }
            else
                e == cond ? ++cnf : --cnf;
        }
        return cond;
    }
};

