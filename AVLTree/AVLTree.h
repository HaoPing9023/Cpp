#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<algorithm>

using namespace std;

template<class K, class V>
struct AVLTreeNode 
{
	//需要parent指针，后续更新平衡因子可以看到
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	
	int _bf;	//balance factor
	
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	using Node = AVLTreeNode<K, V>;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
			
			cur = new Node(kv);
			if (parent->_kv.first < kv.first)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			
			//链接父亲节点
			cur->_parent = parent;

			while(parent)
			{
				if (parent->_left == cur)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}
				
				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == -1 || parent->_bf == 1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == -2 || parent->_bf == 2)
				{
					//旋转
					if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
					}

					break;
				}
				else
				{
					assert(false);
				}
			}
		}
	}
	
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->parent = parent;

		Node* pParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

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

			subL->_parent = pParent;
		}

		subL->_bf = 0;
		parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		
		Node* pParent = parent->_parent;
		
		subR->_left = parent;
		parent->_parent = subR;

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
			subR->_parent = pParent;
		}

		subR->_bf = parent->_bf = 0;
	}
	

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	Node* _root;
};