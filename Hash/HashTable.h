#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

enum State
{
	EXIST,
	EMPTY,
	DELETE
};

inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] = {
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string s)
	{
		size_t hash = 0;
		for (auto& e : s)
		{
			hash += e;
			hash *= 131;
		}

		return hash;
	}
};

namespace open_address
{
	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_tables(__stl_next_prime(0))
			, _n(0)
		{}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;
			//负载因子
			// n / 容量 要 >= 0.7
			if (_n * 10 / _tables.size() >= 7)
			{
				//vector<HashTable<K, V>> newtables(_tables.size() * 2);
				//for (auto& data : _tables)
				//{
				//	if (data._state == EXIST)
				//	{
				//		size_t Hash0 = kv.first % _tables.size();
				//		//......	冗余
				//	}
				//}
				//_tables.swap(newtables);

				HashTable<K, V, Hash> newht;
				newht._tables.resize(__stl_next_prime(_tables.size() + 1));
				for (auto& data : _tables)
				{
					//旧表的数据映射到新表
					if (data._state == EXIST)
					{
						newht.Insert(data._kv);
					}
				}

				_tables.swap(newht._tables);
			}

			size_t Hash0 = kv.first % _tables.size();
			size_t Hashi = Hash0;
			size_t i = 1;

			while (_tables[Hashi]._state == EXIST)
			{
				//线性探测
				Hashi = (Hash0 + i) % _tables.size();
				++i;
			}

			_tables[Hashi]._kv = kv;
			_tables[Hashi]._state = EXIST;

			++_n;
			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			size_t Hash0 = key % _tables.size();
			size_t Hashi = Hash0;
			size_t i = 1;
			int flag = 1;

			while (_tables[Hashi]._state != EMPTY)
			{
				if (_tables[Hashi]._state == EXIST
					&& _tables[Hashi]._kv.first == key)
				{
					return &_tables[Hashi];
				}

				//线性探测
				Hashi = (Hash0 + i) % _tables.size();
				++i;

				////二次探测
				//Hashi = (Hash0 + (i * i * flag)) % _tables.size();
				//
				//if (Hashi < _tables.size())
				//	Hashi += _tables.size();

				//if (flag == 1)
				//{
				//	flag = -1;
				//}
				//else
				//{
				//	flag = 1;
				//	++i;
				//}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				return true;
			}
			else
			{
				return false;
			}

		}
	private:
		vector<HashData<K, V>> _tables;
		size_t _n;
	};
}

namespace hash_bucket
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V> kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		HashTable()
			:_tables(11)
			, _n(0)
		{}

		bool Insert(const pair<K, V>& kv)
		{
			if (_n == _tables.size())
			{
				vector<Node*> newTables(_tables.size() * 2);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						//头插到新表
						size_t hashi = cur->_kv.first % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			size_t hashi = kv.first % _tables.size();
			
			//头插
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;
			
			return true;
		}

	private:
		vector<Node*> _tables;	// 指针数组
		size_t _n = 0;	// 表中存储数据个数
	};
}

