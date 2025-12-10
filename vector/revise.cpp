//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//#include<algorithm>
//
//using namespace std;
//
//namespace my
//{
//	template<class T>
//	class vector {
//	public:
//		typedef T* iterator;
//		typedef const T* const_iterator;
//
//		iterator begin()
//		{
//			return _start;
//		}
//		iterator end()
//		{
//			return _finish;
//		}
//		const_iterator begin() const
//		{
//			return _start;
//		}
//		const_iterator end() const
//		{
//			return _finish;
//		}
//
//
//		template<class InputIterator>
//		vector(InputIterator frist, InputIterator last)
//		{
//			while (first != last)
//			{
//				push_back(*first);
//				++first;
//			}
//		}
//		
//		vector(size_t n, const T& val = T())
//		{
//			reserve(n);
//			for (int i = 0; i < n; ++i)
//			{
//				push_back(val);
//			}
//		}
//		vector(int n, const T& val = T())
//		{
//			reserve(n);
//			for (int i = 0; i < n; ++i)
//			{
//				push_back(val);
//			}
//		}
//
//
//		/*vector()
//		{}*/
//		vector(const vector<T>& v)
//		{
//			reserve(v.size());
//			for (auto& e : v)
//			{
//				push_back(e);
//			}
//		}
//
//		size_t size()
//		{
//			return _finish - _start;
//		}
//		
//		size_t capacity()
//		{
//			return _end_of_storage - _start;
//		}
//		
//		bool empty()
//		{
//			return _start == _finish;
//		}
//
//		void clear()
//		{
//			_finish = _start;
//		}
//		
//		void swap(vector<T> v)
//		{
//			std::swap(_start, v._start);
//			std::swap(_finish, v._finish);
//			std::swap(_end_of_storage, v._end_of_storage);
//		}
//		T& operator=(vector<T> v)
//		{
//			swap(v);
//			return *this;
//		}
//		
//		T& operator[](const size_t i)
//		{
//			assert(i < size());
//			return _start[i];
//		}
//		const T& operator[](const size_t i) const 
//		{
//			assert(i < size());
//			return _start[i];
//		}
//		
//		void reserve(const size_t n)
//		{
//			if (n > capacity())
//			{
//				size_t old_size = size();
//				T* tmp = new T[n];
//				for (size_t i = 0; i < old_size; ++i)
//				{
//					tmp[i] = _start[i];
//				}
//				delete[] _start;
//				_start = tmp;
//				_finish = tmp + old_size;
//				_end_of_storage = tmp + n;
//			}
//		}
//		void push_back(const T& x)
//		{
//			if (_finish == _end_of_storage)
//			{
//				reserve(capacity() == 0 ? 4 : 2 * capacity());
//			}
//			*_finish = x;
//			++_finish;
//		}
//
//		void pop_back()
//		{
//			assert(!empty());
//			--_finish;
//		}
//
//		iterator insert(iterator pos, const T& x)
//		{
//			if (_finish == _end_of_storage)
//			{
//				size_t len = pos - _start;
//				reserve(capacity() == 0 ? 4 : 2 * capacity());
//				pos = _start + len;
//			}
//			iterator end = _finish;
//			while (end > pos)
//			{
//				*end = *(end - 1);
//				--end;
//			}
//			*pos = x;
//			++_finish;
//			return pos;
//		}
//
//		iterator erase(iterator pos)
//		{
//			assert(pos >= _start && pos < _finish);
//			iterator it = pos + 1;
//			while (it != end())
//			{
//				*(it - 1) = *it;
//				++it;
//			}
//			--_finish;
//			return pos;
//		}
//
//
//	private:
//		iterator _start = nullptr;
//		iterator _finish = nullptr;
//		iterator _end_of_storage = nullptr;
//	};
//
//	template<class Container>
//	void print_container(const Container& con)
//	{
//		typename Container::const_iterator it = con.begin();
//		while (it != con.end())
//		{
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//
//	void test01()
//	{
//		vector<int> v;
//		v.insert(v.begin(), 1);
//		v.insert(v.begin(), 2);
//		v.insert(v.begin(), 3);
//		v.insert(v.begin(), 4);
//		v.insert(v.begin(), 5);
//
//		print_container(v);
//		
//		v.insert(v.begin() + 2, 99);
//		print_container(v);
//
//		v.erase(v.begin() + 5);
//		print_container(v);
//	}
//}
//
//
//int main()
//{
//	my::test01();
//	return 0;
//}