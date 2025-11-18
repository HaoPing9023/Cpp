//描述
//求1 + 2 + 3 + ... + n
//要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
//数据范围：
//	0<n≤200 
//进阶： 空间复杂度O(1)，时间复杂度O(n)

//#include<iostream>
//using namespace std;
//
//class Sum {
//public:
//    Sum(){
//        _sum += _n;
//        _n++;
//    }
//    static int GetSum(){
//        return _sum;
//    }
//private:
//    static int _n;
//    static int _sum;
//};
//
//int Sum::_n = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        Sum *arr = new Sum[n];
//        return Sum::GetSum();
//    }
//};
//int main()
//{
//    int res = Solution().Sum_Solution(5);
//    cout << res << endl;
//    return 0;
//}