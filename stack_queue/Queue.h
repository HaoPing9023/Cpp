#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
using namespace std;


namespace my
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front() const
		{
			return _con.front();
		}

		const T& back() const
		{
			return _con.back();
		}
		
		size_t size() const
		{
			return _con.size();
		}
		
		bool empty() const 
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}