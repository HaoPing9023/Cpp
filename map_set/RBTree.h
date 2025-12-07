#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col; //新增颜色属性

	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};

template<class K, class T, class KeyOfT>
class RBTree
{
public:
	using Node = RBTreeNode<T>;

	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK; //根节点必须是黑色
			return true;
		}

		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false; //键已存在，插入失败
			}
		}

		cur = new Node(data);
		cur->_col = RED; //新插入的节点默认是红色

		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		//链接父亲节点
		cur->_parent = parent;

		while (parent && parent->_col == RED) //只有父亲是红色才需要处理，如果父亲是黑色则满足红黑树性质
		{
			Node* grandfather = parent->_parent; //如果parent是红色，它一定不是根，所以一定有祖父
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)	//uncle节点存在且为红
				{
					//情况1：叔叔存在且为红 -> 变色
					//  g
					//p	  u
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上处理
					cur = grandfather; //将祖父当成新插入的节点，继续向上调整
					parent = grandfather->_parent;
				}
				else	//uncle节点不存在 或 颜色为黑
				{
					//情况2：叔叔不存在或为黑 -> 旋转+变色
					if (cur == parent->_left)	//如果插入节点是在左边，需要右单旋
					{
						//     g
						//   p	  u
						// c
						RotateR(grandfather);
						parent->_col = BLACK; //旋转后的根变黑
						grandfather->_col = RED; //原祖父变红
					}
					else	//如果插入节点是在右边边，需要左右双旋
					{
						//      g
						//   p	  u
						//     c
						RotateL(parent); //先左旋变成上面的情况
						RotateR(grandfather);
						cur->_col = BLACK; //双旋后的根变黑
						grandfather->_col = RED;
					}

					break; //旋转后子树根变为黑色，无需继续往上调整
				}
			}
			else //parent是grandfather的右孩子
			{
				//  g
				//u	  p
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//情况1的对称情况
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//情况2的对称情况
					if (cur == parent->_right)
					{
						//  g
						//u	  p
						//		c
						RotateL(grandfather); //左单旋
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//  g
						//u	   p
						//   c
						RotateR(parent); //右左双旋
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
			}
		}
		_root->_col = BLACK; //无论如何，根节点最后必须染黑
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent; //更新subLR的父指针

		Node* pParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL; //更新parent的父指针

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (pParent->_left == parent)
			{
				pParent->_left = subL;
			}
			else
			{
				pParent->_right = subL;
			}

			subL->_parent = pParent; //更新subL的父指针
		}

	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent; //更新subRL的父指针

		Node* pParent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR; //更新parent的父指针

		if (pParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (pParent->_left == parent)
			{
				pParent->_left = subR;
			}
			else
			{
				pParent->_right = subR;
			}
			subR->_parent = pParent; //更新subR的父指针
		}

	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int Height()
	{
		return _Height(_root);
	}

	int Size()
	{
		return _Size(_root);
	}


private:

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		//cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int LeftHeight = _Height(root->_left);
		int RightHeight = _Height(root->_right);

		return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
	}

	int _Size(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		return _Size(root->_left) + _Size(root->_right) + 1;
	}
	Node* _root = nullptr;
};