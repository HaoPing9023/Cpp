//20.有效的括号
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//1.左括号必须用相同类型的右括号闭合。
//2.左括号必须以正确的顺序闭合。
//3.每个右括号都有一个对应的相同类型的左括号。

#include"Algorithm_150.h"

class Solution1 {
    unordered_map<char, char> mp = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

public:
    bool isValid(string s) {
        if (s.size() % 2)
            return false;
        stack<char> st;
        for (auto x : s) {
            if (x == '(' || x == '[' || x == '{')
                st.push(mp[x]);
            else {
                if (st.empty() || st.top() != x)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};


class Solution2 {
public:
    bool isValid(string s) {
        if (s.size() % 2)
            return false;
        stack<char> st;
        for (auto x : s)
        {
            if (x == '(' || x == '[' || x == '{')
                st.push(x);
            else
            {
                if (!st.empty())
                {
                    if (x == ')' && st.top() != '(') return false;
                    else if (x == ']' && st.top() != '[') return false;
                    else if (x == '}' && st.top() != '{') return false;
                    st.pop();
                }
                else
                    return false;
            }

        }
        return st.empty();
    }
};