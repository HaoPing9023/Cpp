#define _CRT_SECURE_NO_WARNINGS 1
#include"BinarySearch.h"

 int main()
{
	key::BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 1, 6, 4, 7, 14, 13};
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrder();

	t.Insert(16);
	t.Insert(3);
	t.InOrder();

	t.Erase(3);
	t.InOrder();

	t.Erase(8);
	t.InOrder();

	for (auto e : a)
	{
		t.Erase(e);
		t.InOrder();
	}

	return 0;
}
