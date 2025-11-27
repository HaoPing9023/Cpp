//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//#include<algorithm>
//using namespace std;
//
//
//template<class T>
//struct list_node
//{
//	T _date;
//	list_node* _next;
//	list_node* _prev;
//
//	list_node(const T& date)
//		:_date(date)
//		, _next(nullptr)
//		, _prev(nullptr)
//	{}
//};
//
//template<class T, class Ref, class Ptr>
//struct list_iterator
//{
//	typedef list_node<T> Node;
//	typedef list_iterator<T, Ref, Ptr> Self;
//	
//	Node* _node;
//	list_iterator(Node* node)
//		:_node(node)
//	{}
//	
//	Ref operator*()
//	{
//		return _node->_date;
//	}
//
//	Ptr operator*()
//	{
//		return &_node->_date;
//	}
//
//	Self& operator++()
//	{
//		_node = _node->next;
//		return *this;
//	}
//	
//	Self& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//
//	Self& operator++(int)
//	{
//		Self tmp(_node)
//		_node = _node->next;
//		return tmp;
//	}
//
//	Self& operator--(int)
//	{
//		Self tmp(_node)
//		_node = _node->_prev;
//		return tmp;
//	}
//	
//	// it1 != it2
//	bool operator!=(const Self& s) const
//	{
//		return _node != s._node
//	}
//
//	bool operator==(const Self& s) const
//	{
//		return _node == s._node
//	}
//};
//
//template<class T>
//class list {
//	typedef list_node<T> Node;
//public:
//	typedef list_iterator<T, T&, T*> iterator;
//	typedef list_iterator<T, const T&, const T*> const_iterator;
//
//	iterator begin()
//	{
//		return _head->_next;
//	}
//	iterator end()
//	{
//		return _head;
//	}
//	const_iterator begin() const
//	{
//		return _head->_next;
//	}
//	const_iterator end() const
//	{
//		return _head;
//	}
//	
//	void empty_init()
//	{
//		_head = new Node;
//		_head->_next = _head;
//		_head->_prev = _head;
//		_size = 0;
//	}
//	list()
//	{
//		empty_init();
//	}
//
//	list(const list<T>& lt)
//	{
//		empty_init();
//		for (auto& e : lt)
//		{
//			push_back(e);
//		}
//	}
//
//	~list()
//	{
//		clear();
//		delete _head;
//		_head = nullptr;
//		_size = 0;
//	}
//
//	list<T>& operator=(list<T> lt)
//	{
//		swap(lt);
//		return *this;
//	}
//
//	void swap(list<T>& lt)
//	{
//		std::swap(_head, lt._head);
//		std::swap(_size, lt._size);
//	}
//
//	void clear()
//	{
//		auto it = begin();
//		while (it != end())
//		{
//			it = erase(it);
//		}
//	}
//
//	void insert(iterator pos, const T& x)
//	{
//		Node* newnode = new Node(x);
//		Node* cur = pos._node;
//		Node* prev = cur->_prev;
//
//		newnode->next = cur;
//		cur->_prev = newnode;
//		newnode->_prev = prev;
//		prev->_next = newnode;
//		
//		++_size;
//	}
//
//	void push_back(const T& x)
//	{
//		insert(end(), x);
//	}
//	void push_front(const T& x)
//	{
//		insert(begin(), x);
//	}
//
//	iterator erase(iterator pos)
//	{
//		assert(pos != end());
//
//		Node* cur = pos._node;
//		Node* next = cur->_next;
//		Node* prev = cur->_prev;
//
//		prev->_next = next;
//		next->_prev = prev;
//		
//		--_size;
//		return next;
//	}
//
//	void pop_back()
//	{
//		erase(--end());
//	}
//	void pop_front()
//	{
//		erase(begin());
//	}
//
//	size_t size()
//	{
//		return _size;
//	}
//
//	bool empty()
//	{
//		return _size == 0;
//	}
//	
//private:
//	Node* _head;
//	size_t _size;
//};
//
//
//
//int main()
//{
//	return 0;
//}