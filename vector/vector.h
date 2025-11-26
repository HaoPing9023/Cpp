#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
namespace my {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		//构建和销毁
		vector()
		{}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		void reserve(const size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * size());
				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = tmp + n;
			}
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			*_finish = x;
			++_finish;
		}
		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}
		const T& operator[](size_t n) const
		{
			assert(n < size());
			return _start[n];
		}
	private:
		iterator _start = nullptr;;
		iterator _finish = nullptr;;
		iterator _end_of_storage = nullptr;
	};
	template<class T>
	void print_vector(const vector<T>& v)
	{
		//规定：没有实例化的类模板中取东西，编译器不能判断const_iterator
		//是类型还是静态成员变量
		typename vector<T>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto& x : v)
			cout << x << " ";
		cout << endl;
	}

	void test01()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << endl;
		print_vector(v);
	}
}