//150.逆波兰表达式求值
//给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
//请你计算该表达式。返回一个表示表达式值的整数。
//注意：
//	有效的算符为 '+'、'-'、'*' 和 '/' 。
//	每个操作数（运算对象）都可以是一个整数或者另一个表达式。
//	两个整数之间的除法总是 向零截断 。
//	表达式中不含除零运算。
//	输入是一个根据逆波兰表示法表示的算术表达式。
//	答案及所有中间计算结果可以用 32 位 整数表示。
//示例 1：
//	输入：tokens = ["2", "1", "+", "3", "*"]
//	输出：9
//	解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9


#include"Algorithm_150.h"
#include<functional>

//思路：使用栈进行解题，如果遇到数字就入栈，遇到符号就将栈顶两个元素进行计算
//C++11特性解法
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        //使用map存储，key值为符号，value值为function（包装器），内容为匿名函数
        //匿名函数在 编译时 生成 仿函数不影响 运行时 的速度
        map<string, function<int(int, int)>> opFunMap = {
            {"+", [](int x, int y) {return x + y; }},
            {"-", [](int x, int y) {return x - y; }},
            {"*", [](int x, int y) {return x * y; }},
            {"/", [](int x, int y) {return x / y; }}
        };
        for (auto& str : tokens)    //遍历vector中的元素
        {
            if (opFunMap.count(str))    //如果是符号（count(str)是对比key值，若存在则结果为1）
            {
                int right = st.top(); st.pop();     //获取栈顶的两个元素
                int left = st.top(); st.pop();

                //核心
                //匿名函数捕获值为获取的符号，在map中对应的key值执行value的匿名函数
                st.push(opFunMap[str](left, right));     
            }
            else
            {
                //若不是符号，那么就是数字，入栈
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};