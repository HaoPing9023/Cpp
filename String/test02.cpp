//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//using namespace std;
//namespace haoping {
//	class String
//	{
//		typedef char* iterator;
//	public:
//		iterator begin()
//		{
//			return _str;
//		}
//		iterator end()
//		{
//			return _str + _size;
//		}
//		String(const char* str = "")
//		{
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		void swap(String& s)
//		{
//			std::swap(_str, s._str);
//			std::swap(_size, s._size);
//			std::swap(_capacity, s._capacity);
//		}
//		String(const String& s)
//			:_str(nullptr)
//		{
//			String tmp(s._str);
//			swap(tmp);
//		}
//		~String()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = _capacity = 0;
//		}
//		char* c_str() const
//		{
//			return _str;
//		}
//		size_t size()
//		{
//			return _size;
//		}
//		char& operator[](const size_t i)
//		{
//			assert(i < _size);
//			return _str[i];
//		}
//		const char& operator[](const size_t i) const
//		{
//			assert(i < _size);
//			return _str[i];
//		}
//
//		String& operator=(String s)
//		{
//			std::swap(_str, s._str);
//			return *this;
//		}
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		void push_back(char ch)
//		{
//			if (_size == _capacity)
//				reserve(_capacity == 0 ? 4 : _capacity * 2);
//			_str[_size++] = ch;
//			_str[_size] = '\0';
//		}
//		
//		void append(const char* str)
//		{
//			int len = strlen(str);
//			if (_size + len >= _capacity)
//				reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
//			strcpy(_str + _size, str);
//			_size += len;
//		}
//		String& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//		String& operator+=(const char* str)
//		{
//			append(str);
//			return *this;
//		}
//		
//		void insert(size_t pos, char ch)
//		{
//			assert(pos <= _size);
//			if (_size == _capacity)
//				reserve(_capacity == 0 ? 4 : _capacity * 2);
//			size_t end = _size + 1;
//			while (end > pos)
//			{
//				_str[end] = _str[end - 1];
//				--end;
//			}
//			_str[pos] = ch;
//			++_size;
//		}
//		void insert(size_t pos, const char* str)
//		{
//			int len = strlen(str);
//			assert(len <= _size);
//			if(_size + len >= _capacity)
//				reserve(_size + len >= 2 * _capacity ? _size + len : 2 * _capacity);
//			size_t end = _size + len;
//			while (end > pos + len - 1)
//			{
//				_str[end] = _str[end - len];
//				end--;
//			}
//			for (int i = 0; i < len; ++i)
//				_str[pos + i] = str[i];
//			_size += len;
//		}
//
//		void erase(const size_t pos, const size_t len = npos)
//		{
//			assert(pos <= _size);
//			if (len >= _size - pos)
//			{
//				_str[pos] = '\0';
//				_size = pos;
//			}
//			else
//			{
//				strcpy(_str + pos, _str + pos + len);
//				_size -= len;
//			}
//		}
//		
//		size_t find(char ch, const size_t pos = 0)
//		{
//			assert(pos < _size);
//			for (int i = pos; i < _size; ++i)
//				if (_str[i] == ch) return i;
//			return npos;
//		}
//		size_t find(const char* str, const size_t pos = 0)
//		{
//			assert(pos < _size);
//			const char* ptr = strstr(_str + pos, str);
//			if (ptr == nullptr) return npos;
//			return ptr - _str;
//		}
//
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//		const static int npos = -1;
//	};
//}
//
//
//
//
//using namespace haoping;
//void test01()
//{
//	String s1("hello world");
//	s1 = s1;
//	//s1.push_back('&');
//	//s1.append("$$$$$$");
//	//s1.insert(5, '&');
//	//s1.insert(0, '&');
//
//	//cout << s1.c_str() << endl;
//	//s1.insert(5, "&&&&&");
//	//s1.insert(0, "$$$$$");
//	//cout << s1.c_str() << endl;
//	//s1.erase(0, 5);
//	//cout << s1.c_str() << endl;
//	for (auto& ch : s1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//
//
//}
//int main()
//{
//	test01();
//
//	return 0;
//}