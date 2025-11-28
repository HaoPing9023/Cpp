#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

//class Person
//{
//public:
//	// 进入校园/图书馆/实验室刷二维码等身份认证
//	void identity()
//	{
//		cout << "void identity()" << _name << endl;
//		cout << _age << endl;
//	}
//protected:
//	string _name = "张三"; // 姓名
//	string _address; // 地址
//	string _tel; // 电话
//private:
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	// 学习
//	void study()
//	{
//		identity();
//		// ...
//		//cout << _age << endl;
//		cout << _tel << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//public:
//	// 授课
//	void teaching()
//	{
//		//...
//	}
//protected:
//	string title; // 职称
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//
//	s.identity();
//	t.identity();
//
//	return 0;
//}

//#define CONTAINER std::vector
//#define CONTAINER std::list
#define CONTAINER std::deque

//namespace my
//{
//	//template<class T>
//	//class vector
//	//{};
//	// stack和vector的关系，既符合is-a，也符合has-a
//	template<class T>
//	class stack : public CONTAINER<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			CONTAINER<T>::push_back(x);
//		}
//
//		void pop()
//		{
//			CONTAINER<T>::pop_back();
//		}
//
//		const T& top()
//		{
//			return CONTAINER<T>::back();
//		}
//
//		bool empty()
//		{
//			return CONTAINER<T>::empty();
//		}
//	};
//
//
//	template<class T>
//	class A
//	{
//	public:
//		A()
//		{
//			//func();
//		}
//
//		void push(const T& x)
//		{
//			x.func();
//		}
//	};
//}
//
//int main()
//{
//	my::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//
//	//my::A<int> aa;
//	//aa.push(1);
//
//	return 0;
//}

//class Person
//{
////protected:
//	virtual void func()
//	{}
//public:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};

//int main()
//{
//	Student sobj;
//
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	rp._name = "张三";
//
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//	//2.父类对象不能赋值给子类对象，这里会编译报错
//	//sobj = (Student)pobj;
//
//	Student* ps1 = dynamic_cast<Student*>(pp);
//	cout << ps1 << endl;
//
//	pp = &pobj;
//	Student* ps2 = dynamic_cast<Student*>(pp);
//	cout << ps2 << endl;
//
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//
//	Student s;
//	s.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.A::fun();
//	b.fun(1);
//
//
//	return 0;
//};

class Person
{
public:
	Person(const char* name = "xxx")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};

class Student : public Person
{
public:
	Student(const char* name, int num, const char* addrss)
		:Person(name)
		, _num(num)
		, _addrss(addrss)
	{}

	// 严格说Student拷贝构造默认生成的就够用了
	// 如果有需要深拷贝的资源，才需要自己实现
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
		, _addrss(s._addrss)
	{
		// 深拷贝
	}

	// 严格说Student赋值重载默认生成的就够用了
	// 如果有需要深拷贝的资源，才需要自己实现
	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			// 父类和子类的operator=构成隐藏关系
			Person::operator=(s);

			_num = s._num;
			_addrss = s._addrss;
		}

		return *this;
	}

	// 严格说Student析构默认生成的就够用了
	// 如果有需要显示释放的资源，才需要自己实现
	// 析构函数都会被特殊处理成destructor() 
	~Student()
	{
		// 子类的析构和父类析构函数也构成隐藏关系
		// 规定：不需要显示调用，子类析构函数之后，会自动调用父类析构
		// 这样保证析构顺序，先子后父，显示调用取决于实现的人，不能保证
		// 先子后父
		//Person::~Person();
		//delete _ptr;
	}
protected:
	int _num = 1; //学号
	string _addrss = "西安市高新区";

	int* _ptr = new int[10];
};

int main()
{
	Student s1("张三", 1, "西安市");
	Student s2(s1);

	Student s3("李四", 2, "咸阳市");
	s1 = s3;

	/*Person* ptr = new Person;
	delete ptr;*/

	return 0;
}

//class Student : public Person
//{
//public:
//	// 默认生成的构造函数的行为
//	// 1、内置类型->不确定
//	// 2、自定义类型->调用默认构造
//	// 3、继承父类成员看做一个整体对象，要求调用父类的默认构造
//protected:
//	int _num = 1; //学号
//	string _addrss = "西安市高新区";
//};
//
//int main()
//{
//	Student s;
//
//	return 0;
//}