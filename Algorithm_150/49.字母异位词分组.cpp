//49.字母异位词分组
//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//示例:
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]

#include"Algorithm_150.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& s : strs) {
            string key = s;
            // ranges::sort(key);   // C++20写法
            sort(key.begin(), key.end());   // 将字符串排序后存入哈希表
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(mp.size());     //可选 预留空间，减少vector扩容次数，提高效率
        for (auto& s : mp) {
            res.push_back(s.second);
        }
        return res;
    }
};