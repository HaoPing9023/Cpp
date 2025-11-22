#include"String.h"
const size_t String::npos = -1;
void String::reserve(size_t n)
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
	if (_size == _capacity)
		reserve(_capacity == 0 ? 4 : _capacity * 2);
	_str[_size++] = ch;
	_str[_size] = '\0';
}
void String::append(const char* str)
{
	int len = strlen(str);
	if (_size + len >= _capacity)
		reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
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
void String::insert(size_t pos, char ch)
{
	assert(pos <= _size);
	if (_size == _capacity)
		reserve(_capacity == 0 ? 4 : _capacity * 2);
	size_t end = _size + 1;
	while (end > pos)
	{
		_str[end] = _str[end - 1];
		--end;
	}
	_str[pos] = ch;
	++_size;
}
void String::insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	size_t len = strlen(str);
	if (_size + len >= _capacity)
		reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
	size_t end = _size;
	while (end + len >= pos)
	{
		_str[end + len] = _str[end];
		--end;
	}
	//strcpy(_str + pos, str);
	_size += len;
}
//void erase(size_t pos, size_t len);





void test01()
{
	String s1;
	String s2("hello world");
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
}
void test02()
{
	String s1("hello world");
	s1 += '#';
	cout << s1.c_str() << endl;
	s1 += "&&&&&&";
	cout << s1.c_str() << endl;

}
void test03()
{
	String s1("hello world");
	s1.insert(0, 'x');
	cout << s1.c_str() << endl;
	/*s1.insert(7, "&&&&&&&");
	cout << s1.c_str() << endl;*/
}
int main()
{
	//test01();
	//test02();
	test03();

	return 0;
}