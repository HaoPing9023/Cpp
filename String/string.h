#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//#include<string>
#include<assert.h>
using namespace std;
class String
{
public:
	typedef char* iterator;

	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}
	//String()
	//	: _str(new char[1] {'\0'})
	//	, _size(0)
	//	, _capacity(0)
	//{}
	String(const char* str = "")
	{
		_size = strlen(str);
		//capacity²»°üº¬'\0'
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
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
	size_t capacity() const
	{
		return _capacity;
	}
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	const char* c_str()
	{
		return _str;
	}
	void reserve(size_t n);
	void push_back(char ch);
	void append(const char* str);
	String& operator+=(char ch);
	String& operator+=(const char* str);

	void insert(size_t pos, char ch);
	void insert(size_t pos, const char* str);
	void erase(size_t pos, size_t len = npos);
private:
	char* _str;
	size_t _size;
	size_t _capacity;
	const static size_t npos;
};