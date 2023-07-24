
#include <iostream>
#include"Datatype.h"
#include"Datatype.cpp"

using namespace DataType;
int main()
{
	LinkedList<int> temp;
	for (int i = 0; i < 25; i++)
	{
		temp.pushBack(i);
		temp.showInfo();
	}
	for (int i = 0; i < 5; i++)
	{
		temp.deleteAt(6);
		temp.showInfo();
	}
}
