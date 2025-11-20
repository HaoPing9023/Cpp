//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int s1 = num1.size() - 1;
//        int s2 = num2.size() - 1;
//        int next = 0;
//        string s;
//        while (s1 >= 0 || s2 >= 0 || next != 0)
//        {
//            int x = s1 >= 0 ? num1[s1] - '0' : 0;
//            int y = s2 >= 0 ? num2[s2] - '0' : 0;
//            int res = x + y + next;
//            s.push_back(res % 10 + '0');
//            next = res / 10;
//            s1--;
//            s2--;
//        }
//        reverse(s.begin(), s.end());
//        return s;
//    }
//};
//int main()
//{
//    string num1 = "456";
//    string num2 = "77";
//    Solution s;
//    string str = s.addStrings(num1, num2);
//    cout << str << endl;
//    return 0;
//}