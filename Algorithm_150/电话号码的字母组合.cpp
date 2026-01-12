//17.电话号码的字母组合
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

#include"Algorithm_150.h"

class Solution {
public:
    vector<string> v;
    string TEL[10] = { "","","abc","def","ghi","jkl",
                        "mno","pqrs","tuv","wxyz" };
    void dfs(int idx, string& digits, string str)
    {
        int n = digits.size();
        if (idx == n)
        {
            v.push_back(str);
            return;
        }
        string ans = TEL[digits[idx] - '0'];
        for (int i = 0; i < ans.size(); ++i)
        {
            str.push_back(ans[i]);
            dfs(idx + 1, digits, str);
            str.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0)
            return {};
        dfs(0, digits, "");
        return v;
    }
};