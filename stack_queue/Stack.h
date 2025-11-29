#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
using namespace std;

namespace my
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top() const
		{
			return _con.back();
		}
		
		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
		
	private:
		Container _con;
	};
}