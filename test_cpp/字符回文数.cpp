//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
////解法一：
////class Solution01 {
////public:
////    bool isPalindrome(string s) {
////        string str;
////        int i = 0;
////        for (auto ch : s)
////        {
////            if (isupper(ch))
////                // str.push_back(s[i] - ('a' - 'A'));
////                str.push_back(tolower(ch));
////            else if (islower(ch) || isdigit(ch))
////                str.push_back(ch);
////        }
////        int len = str.size();
////        int fast = len / 2;
////        int slow = 0;
////        reverse(str.begin(), str.begin() + fast);
////        fast = len % 2 == 0 ? fast : fast + 1;
////        while (fast < str.size())
////            if (str[slow++] != str[fast++]) return false;
////        return true;
////    }
////};
//
////解法二：双指针
//class Solution02 {
//public:
//    bool isPalindrome(string s) {
//        int l = 0;
//        int r = s.size() - 1;
//        while (l < r)
//        {
//            while (l < r && !isalnum(s[l])) l++;
//            while (l < r && !isalnum(s[r])) r--;
//            if (tolower(s[l]) != tolower(s[r])) return false;
//            l++;
//            r--;
//        }
//        return true;
//    }
//};
//
//int main()
//{
//    string s = "abba";
//    //Solution01 A;
//    Solution02 A;
//    cout << A.isPalindrome(s) << endl;
//    return 0;
//}