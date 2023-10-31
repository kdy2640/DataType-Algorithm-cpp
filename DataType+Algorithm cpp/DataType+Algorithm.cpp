#include<iostream>
#include<fstream>
#include"OurDeque.cpp"
using namespace std;
using namespace DataType;

int main()
{
	OurDeque<char> temp;
	for (int i = 0 ;i < 20; i++)
	{
		temp.push_front(65+i);
	}
	temp.show_contents();

	temp.push_back(88);
	temp.push_back(89);
	temp.push_back(90);

	temp.show_contents();

	temp.pop_front();
	temp.pop_back();

	temp.show_contents();

	cout << temp.front() << temp.back() << endl;

}

