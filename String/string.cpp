#include"String.h"
const size_t String::npos = -1;
void String::reserve(size_t n)
{
	if (n > _capacity)
	{
		char* tmp = new char[n + 1];
		strcpy(tmp, _str);
		delete[] _str;
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
	size_t len = strlen(str);
	if (_size + len >= _capacity)
		//大于2倍 要多少开多少，小于2倍按2倍扩
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
		//大于2倍 要多少开多少，小于2倍按2倍扩
		reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
	size_t end = _size;
	while (end > pos - len - 1)
	{
		_str[end + len] = _str[end];
		--end;
	}
	for (size_t i = 0; i < len; ++i)
		_str[pos + i] = str[i];
	_size += len;
}
void String::erase(size_t pos, size_t len)
{
	if (len >= _size - pos)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		for (size_t i = pos + len; i <= _size; ++i)
			_str[i - len] = _str[i];
		_size -= len;
	}
}
size_t String::find(char ch, size_t pos)
{
	assert(pos <= _size);
	for (size_t i = pos; i < _size; ++i)
	{
		if (_str[i] == ch)
			return i;
	}
	return npos;
}
size_t String::find(const char* str, size_t pos)
{
	assert(pos <= _size);
	const char* ptr = strstr(_str + pos, str);
	if (ptr == nullptr)
		return npos;
	return ptr - _str;
}

String String::substr(size_t pos, size_t len)
{
	assert(pos < _size);
	//len大于剩余字符长度，更新len
	if (len > _size - pos)
		len = _size - pos;
	String sub;
	sub.reserve(len);
	for (size_t i = 0; i < len; ++i)
		sub += _str[pos + i];
	return sub;
}

bool operator<(const String& s1, const String& s2)
{
    return strcmp(s1.c_str(), s2.c_str()) < 0;
}
bool operator<=(const String& s1, const String& s2)
{
	return s2 < s1;
}
bool operator>(const String& s1, const String& s2)
{
	return s2 < s1;
}
bool operator>=(const String& s1, const String& s2)
{
	return !(s1 < s2);
}
bool operator==(const String& s1, const String& s2)
{
	return strcmp(s1.c_str(), s2.c_str()) == 0;
}
bool operator!=(const String& s1, const String& s2)
{
	return !(s1 == s2);
}

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
	s1.insert(7, "&&");
	cout << s1.c_str() << endl;
	s1.erase(7);
	cout << s1.c_str() << endl;
}
void test04()
{
	String s1("hello world");
	String s2 = s1.substr(0, 5);
	cout << s2.c_str() << endl;
	s1 = s1;
	String s3("test.cpp.txt");
	int pos = s3.find('.');
	cout << pos << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}