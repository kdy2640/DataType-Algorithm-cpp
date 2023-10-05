#include <iostream>
#include"DoublyLinkedListNode.cpp"
using namespace std;
using namespace DataType;

int main()
{
	typedef int value_type;
	dNode<value_type>* headPtr;
	headPtr = nullptr;

	cout << "Checking list_head_insert" << endl;
	for (int i = 0; i < 20; i++)
	{
		list_head_insert<value_type>(headPtr, i);
	}

	cout << "Checking list_length" << endl;
	cout << "Doubly Linked list's length are " << list_length<value_type>(headPtr) << endl;


	cout << "Checking list_show_content " << endl;
	list_show_contents<value_type>(headPtr);

	cout << "Checking list_head_insert duplication" << endl;
	if (list_head_insert<value_type>(headPtr, 5) == false)
		cout << 5 << " already exists!" << endl;


	for (int i = 0; i < 10; i++)
	{
		list_head_remove<value_type>(headPtr);
	}
	list_show_contents<value_type>(headPtr);
}

