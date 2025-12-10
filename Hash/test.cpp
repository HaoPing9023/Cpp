#define _CRT_SECURE_NO_WARNINGS 1
#include"HashTable.h"

void test01()
{
	int a[] = { 19,30,5,36,13,20,21,12 };
	HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert({ e,e });
	}
}

int main()
{
	test01();
	return 0;
}