#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<time.h>

using namespace std;

#include"Mymap.h"
#include"Myset.h"

int main()
{
	my::set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	return 0;
}