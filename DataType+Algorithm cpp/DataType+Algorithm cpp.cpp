
#include <iostream>
#include"Datatype.h"
#include"Datatype.cpp"
#include <map>
#include <set>
using namespace std;
using namespace DataType;
int main()
{
	set<int> setInt;
	setInt.insert(100);
	 
	CBST<int, int> bstint;
	tPair<int, int> pair;
	bstint.insert(make_tPair(100, 100));
	bstint.insert(make_tPair(150, 100)); 
	bstint.insert(make_tPair(50, 100));
	bstint.insert(make_tPair(25, 100));
	bstint.insert(make_tPair(75, 100));
	bstint.insert(make_tPair(125, 100));
	bstint.insert(make_tPair(175, 100));

	CBST<int, int>::iterator Iter = bstint.begin();
	cout << endl;
	(*Iter).first;
	Iter->first;

	(*Iter).second;
	Iter->second;
	
	for (Iter = bstint.begin(); Iter != bstint.end();++Iter)
	{
		cout << "first is " << Iter->first << ". Second is " << Iter->second << endl;
	}

	Iter = bstint.begin();
	Iter = bstint.find(150);
	Iter = bstint.erase(Iter);


	Iter = bstint.find(100);
	Iter = bstint.erase(Iter);

	cout << endl;
	for (Iter = bstint.begin(); Iter != bstint.end(); ++Iter)
	{
		cout << "first is " << Iter->first << ". Second is " << Iter->second << endl;
	}
	cout << endl;
		
}

