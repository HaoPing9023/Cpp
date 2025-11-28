#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<algorithm>

using namespace std;

namespace my {
	template<class T>
	struct list_node
	{
		T _date;
		list_node<T>* _next;
		list_node<T>* _prev;
		
		//构造链表参数
		list_node(const T& date = T())
			:_date(date)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};
	
	// 添加两个参数，解决冗余问题
	// Ref接收引用，作为*运算符返回值，Ptr接收指针，作为->返回值，
	template<class T, class Ref, class Ptr> 
	struct list_iterator
	{
		typedef list_node<T> Node;

		//typedef list_iterator<T> Self;
		typedef list_iterator<T, Ref, Ptr> Self;

		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{}
		
		Ref operator*()
		{
			return _node->_date;
		}
		Ptr operator->()
		{
			return &_node->_date;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->prev;
			return *this;
		}
		
		Self& operator++(int)
		{
			Self tmp(_node);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--(int)
		{
			Self tmp(_node);
			_node = _node->prev;
			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}
		bool operator==(const Self& s) const 
		{
			return _node == s._node;
		}
	};


	//太冗余
	//template<class T>
	//struct list_const_iterator
	//{
	//	typedef list_const_iterator<T> Self;
	//	typedef list_node<T> Node;
	//	Node* _node;
	//	list_const_iterator(Node* node)
	//		:_node(node)
	//	{}

	//	const T& operator*()
	//	{
	//		return _node->_date;
	//	}
	//	const T* operator->()
	//	{
	//		return &_node->_date;
	//	}

	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	Self& operator--()
	//	{
	//		_node = _node->prev;
	//		return *this;
	//	}

	//	Self& operator++(int)
	//	{
	//		Self tmp(_node);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	Self& operator--(int)
	//	{
	//		Self tmp(_node);
	//		_node = _node->prev;
	//		return tmp;
	//	}

	//	bool operator!=(const Self& s) const
	//	{
	//		return _node != s._node;
	//	}
	//	bool operator==(const Self& s) const
	//	{
	//		return _node == s._node;
	//	}
	//};

	template<class T>
	class list {
		typedef list_node<T> Node;
	public:
		//typedef list_iterator<T> iterator;
		//typedef list_const_iterator<T> const_iterator;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			//标准写法
			/*iterator it = _head->_next;
			return it;*/
			
			//匿名函数
			//return iterator(_head->_next);

			//隐式转换 单参数构造支持隐式类型转换
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}
		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list()
		{
			empty_init();
		}

		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}
	
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}
		void swap(const list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		void insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;

			++_size;
		}
		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			
			prev->_next = next;
			next->_prev = prev;
			delete cur;

			--_size;
			return next;
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}

		size_t size()
		{
			return _size;
		}
		
		bool empty()
		{
			return _size == 0;
		}
		

	private:
		Node* _head;
		size_t _size;
	};

	template<class Container>
	void print_container(const Container& con)
	{
		typename Container::const_iterator it = con.begin();
		while (it != con.end())
		{
			//*it += 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;


		/*for (auto e : con)
		{
			cout << e << " ";
		}
		cout << endl;*/
	}
	

	void test01()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		
		//list<int>::iterator it = lt.begin();
		//while (it != lt.end())
		//{
		//	cout << *it << " ";
		//	++it;
		//}
		//cout << endl;

		print_container(lt);
	}

	void test02()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();

		//insert以后 迭代器不失效
		lt.insert(it, 10);
		*it += 100;
		print_container(lt);

		// erase以后 迭代器失效
		// 删除所有偶数
		it = lt.begin();
		while (it != lt.end())
		{
			if (*it % 2 == 0)
				//lt.erase(it);
				it = lt.erase(it);
			else
				++it;
		}
		print_container(lt);
	}
}