#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	void swap(String& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(tmp);
	}
	char* c_str()
	{
		return _str;
	}
	~String()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	size_t size() const
	{
		return _size;
	}

	String& operator=(String s)
	{
		std::swap(_str, s._str);
		return *this;
	}

	size_t operator[](size_t pos)
	{
		assert(pos <= _size);
		return _str[pos];
	}
	void reserve(const size_t n);
	void push_back(char ch);
	void append(const char* str);
	String& operator+=(char ch);
	String& operator+=(const char* str);
	
	void insert(const size_t pos, char ch);
	void insert(const size_t pos, const char* str);
	void erase(const size_t pos, size_t len = npos);
	
private:
	char* _str;
	size_t _size;
	size_t _capacity;
	static const int npos = -1;
};

void String::reserve(const size_t n)
{
	if (n > _capacity)
	{
		char* tmp = new char[n + 1];
		strcpy(tmp, _str);
		delete _str;
		_str = tmp;
		_capacity = n;
	}
}

void String::push_back(char ch)
{
	if (_size = _capacity)
		reserve(_capacity == 0 ? 4 : _capacity * 2);
	_str[_size++] = ch;
	_str[_size] = '\0';
}

void String::append(const char* str)
{
	int len = strlen(str);
	if (_size + len >= _capacity)
		reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
	strcpy(_str + _size, str);
	_size += len;
}

String& String::operator+=(char ch)
{
	push_back(ch);
	return *this;
}
String& String::operator+=(const char* str)
{
	append(str);
	return *this;
}

void String::insert(const size_t pos, char ch)
{
	assert(pos <= _size);
	if (_size == _capacity)
		reserve(_capacity == 0 ? 4 : 2 * _capacity);
	size_t end = _size + 1;
	while (end > pos)
	{
		_str[end] = _str[end - 1];
		--end;
	}
	_str[pos] = ch;
	++_size;
}
void String::insert(const size_t pos, const char* str)
{
	int len = strlen(str);
	assert(pos + len <= _size);
	if (_size + len >= _capacity)
		reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
	size_t end = _size + len;	//从最后开始拷贝
	while (end > pos + len - 1)
	{
		_str[end] = _str[end - len];
		--end;
	}
	for (int i = 0; i < len; ++i)
		_str[pos + i] = str[i];
	_size += len;
}
void String::erase(const size_t pos, size_t len)
{
	assert(pos <= _size);
	if(len > _size - pos)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		strcpy(_str + pos, _str + pos + len);
		_size -= len;
	}
}





void test01()
{
	String s1("hello world");
	s1 = s1;
	s1.push_back('#');
	cout << s1.c_str() << endl;
	s1.append("&&&&&&&&&");
	cout << s1.c_str() << endl;
}
void test02()
{
	String s1("hello world");
	//s1.insert(0, '#');
	//s1.insert(3, '#');
	cout << s1.c_str() << endl;
	s1.insert(0, "&&&");
	s1.insert(5, "&&&");
	cout << s1.c_str() << endl;

}
int main()
{
	//test01();
	test02();
	return 0;
}

