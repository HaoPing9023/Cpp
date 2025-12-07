#define _CRT_SECURE_NO_WARNINGS 1
#include"RBTree.h"

namespace my
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
	private:
		RBTree<K, V, MapKeyOfT> _t;
	};
}