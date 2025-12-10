#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<assert.h>
using namespace std;
namespace my {
	template<class T>
	class vector {
	public:

		//迭代器
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

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
				push_back(val);
		}

		//在vector<int> v(10,1) 的形式中，不这样写参数将被识别成两个迭代器，执行InputIterator类构造
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
				push_back(val);
		}

		// 默认构造	不写默认构造，因为类中有拷贝构造，
		// 编译器认为也有构造函数，将不会默认生成默认构造，会报错
		/*vector()
		{}*/

		//C++11 强制生成默认构造
		vector() = default;

		//拷贝构造	
		vector(const vector<T>& v)
		{
			reserve(v.size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		void clear()
		{
			_finish = _start;
		}
		//传统写法
		//vector<int> operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		clear();
		//		reserve(v.size());
		//		for (auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

		//现代写法
		void swap(vector<T> v)
		{
			std::swap(_start, v._star);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector<int> operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		bool empty()
		{
			return _start == _finish;
		}
		void reserve(const size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				// 若是需要深拷贝类型(自定义类型)如vector<string>/vector<vector<int>>，memcpy就会失败
				// memcpy只把_start内存的字节拷贝到tmp,不会调用拷贝构造
				// 新旧两个对象的指针会指向同一块堆内存，析构时二次释放 就报错
				//memcpy(tmp, _start, sizeof(T) * old_size);

				for (size_t i = 0; i < old_size; ++i)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = tmp + n;
			}
		}

		void resize(const size_t n, const T& val = T())
		{
			if (_finish > _start + n)
				_finish = _start + n;
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
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

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
	template<class T>
	void print_vector(const vector<T>& v)
	{
		//规定：没有实例化的类模板中取东西，编译器不能判断const_iterator
		//是类型还是静态成员变量
		//typename vector<T>::const_iterator it = v.begin();
		auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		//for (auto& x : v)
		//	cout << x << " ";
		//cout << endl;
	}

	//通用模版
	template<class Container>
	void print_container(const Container& v)
	{
		auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		//for (auto& x : v)
		//	cout << x << " ";
		//cout << endl;
	}

	void test01()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		//for (int i = 0; i < v.size(); ++i)
		//	cout << v[i] << " ";
		//cout << endl;
		print_vector(v);

		v.insert(v.begin() + 3, 99);
		print_vector(v);
		int x; cin >> x;
		//typename vector<int>::iterator p = find(v.begin(), v.end(), x);
		auto p = find(v.begin(), v.end(), x);

		if (p != v.end())
		{
			//insert以后p就失效，不要直接访问，要访问就需要更新这个失效的迭代器的值
			/*v.insert(p, 40);
			(*p) *= 10;*/

			p = v.insert(p, 40);
			*(p + 1) *= 10;
		}
	}
	void test02()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.push_back(4);

		//2v.push_back(5);

		print_vector(v);

		//typename vector<int>::iterator it = v.begin();
		auto it = v.begin();

		while (it != v.end())
		{
			if (*it % 2 == 0)
				//v.erase(it);
				it = v.erase(it);
			else
				++it;
		}
		print_vector(v);
	}
	void test03()
	{
		vector<int> v;
		v.resize(5, 1);
		print_vector(v);

	}

	void test04()
	{
		vector<string> v1(10, "1111111111");
		print_container(v1);

		vector<int> v2(10);
		print_container(v2);

		//需要参数更匹配的拷贝构造，如第一个参数为int n
		vector<int> v3(10, 1);
		print_container(v3);

	}

	void test05()
	{
		vector<string> v;
		v.push_back("1111111111111");
		v.push_back("1111111111111");
		v.push_back("1111111111111");
		v.push_back("1111111111111");
		print_container(v);		//没扩容

		v.push_back("1111111111111");
		print_container(v);		//扩容，检查扩容不能使用memcpy
	}

}