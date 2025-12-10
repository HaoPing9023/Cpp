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

template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K, class V>
class HashTable
{
public:
	HashTable()
		:_tables(11)
		, _n(0)
	{}
	bool Insert(const pair<K, V>& kv)
	{
		size_t Hash0 = kv.first % _tables.size();
		size_t Hashi = Hash0;
		size_t i = 1;

		while (_tables[Hashi]._state == EXIST)
		{
			//œﬂ–‘ÃΩ≤‚
			Hashi = (Hash0 + i) % _tables.size();
			++i;
		}
		
		_tables[Hashi]._kv = kv;
		_tables[Hashi]._state = EXIST;

		++_n;
		return true;
	}
private:
	vector<HashData<K, V>> _tables;
	size_t _n;
};