#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
#include<functional>

using namespace std;

struct Date {
	int _year;
	int _month;
	int _day;

	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	~Date()
	{
		cout << "~Date" << endl;
	}
};

namespace my
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{}

		template<class D>
		shared_ptr(T* ptr, D del)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _del(del)
		{}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_pcount(sp._pcount)
		{
			++(*_pcount);
		}

		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				//delete _ptr;
				_del(_ptr);
				delete _pcount;
			}
		}
		
		shared_ptr operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				if (--(*_pcount) == 0)
				{
					delete _ptr;
					delete _pcount;
				}
				
				_pcount = sp._pcount;
				_ptr = sp._ptr;
				++(*_pcount);
			}
		}

		T* operator->()
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

	private:
		T* _ptr;
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) {delete ptr; };
	};
}

class Fclose
{
public:
	void operator()(FILE* ptr)
	{
		cout << "fclose:" << ptr << endl;
		fclose(ptr);
	}
};

int main()
{
	my::shared_ptr<Date> sp1(new Date);
	my::shared_ptr<Date> sp2(sp1);
	//拷贝构造
	my::shared_ptr<Date> sp3 = sp2;

	my::shared_ptr<Date> sp4(new Date);
	
	sp4 = sp4;
	++sp1->_year;
	++sp3->_day;

	//std::shared_ptr<Date> sp1(new Date);
	//std::shared_ptr<Date[]> sp2(new Date[10]);

	//unique_ptr 和 shared_ptr 定制删除器传值方法不同
	//定制删除器
	//shared_ptr在 构造函数中传
	std::shared_ptr<Date> _sp2(new Date[10], [](Date* ptr) {delete[] ptr; });
	std::shared_ptr<FILE> sp3(fopen("test.cpp", "r"), Fclose());
	std::shared_ptr<FILE> sp4(fopen("test.cpp", "r"), [](FILE* ptr) {fclose(ptr); });

	//unique_ptr在 类声明中传
	std::unique_ptr<Date> up1(new Date);
	std::unique_ptr<Date[]> up1(new Date[10]);
	std::unique_ptr<FILE, Fclose> up1(fopen("test.cpp", "r"));
	return 0;
}





