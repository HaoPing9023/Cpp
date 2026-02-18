//#include<iostream>
//using namespace std;
//
////int main()
////{
////	//暴力
////	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
////	int n = 6;
////	for (int i = 0; i < n; ++i)
////	{
////		for (int j = 0; j < n - i - 1; ++j)
////			cout << " ";
////		cout << "*";
////		if (i > 0)
////		{
////			for (int j = 0; j < 2 * i - 1; ++j)
////				cout << " ";
////			cout << "*";
////		}
////		cout << '\n';
////	}
////	for (int i = n - 1; i > 0; --i)
////	{
////		for (int j = 0; j < n - i; ++j)
////			cout << " ";
////		cout << "*";
////		for (int j = 0; j < (i - 1) * 2 - 1; ++j)
////			cout << " ";
////		if (i != 1) cout << "*";
////		cout << '\n';
////	}
////	return 0;
////}
//
//const int N = 9; //高度
//int main()
//{
//	//双指针
//	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
//	int mid = N / 2;
//	int l = mid, r = mid;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j <= r; ++j)
//		{
//			if (j == l || j == r) cout << "*";
//			else cout << " ";
//		}
//		cout << '\n';
//
//		if (i < mid)
//		{
//			l--;
//			r++;
//		}
//		else
//		{
//			l++;
//			r--;
//		}
//	}
//	return 0;
//}
//
