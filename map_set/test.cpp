#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<time.h>

using namespace std;

#include"Mymap.h"
#include"Myset.h"

void Print(const my::set<int>& s)
{
	my::set<int>::const_iterator it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	my::set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	my::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	Print(s);

	my::map<string, string> dict;
	dict.insert({ "sort", "ÅÅĞò" });
	dict.insert({ "left", "×ó±ß" });
	dict.insert({ "right", "ÓÒ±ß" });

	dict["left"] = "×ó±ß£¬Ê£Óà";
	dict["insert"] = "²åÈë";
	dict["string"];

	my::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// ²»ÄÜĞŞ¸Äfirst£¬¿ÉÒÔĞŞ¸Äsecond
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	return 0;
}