//#define _CRT_SECURE_NO_WARNINGS 1
////给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，
////同时仍保留空格和单词的初始顺序。
//#include<iostream>
//using namespace std;
//
////find找空格
//class Solution {
//public:
//    string reverseWords(string s) {
//        int pos = 0;
//        while (pos < s.size())
//        {
//            int sub = s.find_first_of(" ", pos);
//            if (sub == string::npos)
//            {
//                reverse(s.begin() + pos, s.end());
//                break;
//            }
//            reverse(s.begin() + pos, s.begin() + sub);
//            pos = sub + 1;
//        }
//        return s;
//    }
//};
//
