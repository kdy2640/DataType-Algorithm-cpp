#include<iostream>
#include<fstream>
#include"DoublyLinkedListNode.cpp"
using namespace std;
using namespace DataType;

int main()
{
	ofstream file;
	file.open("log.txt", ios_base::out | ios_base::app);
	cout.rdbuf(file.rdbuf());

	typedef int value_type;
	dNode<value_type>* headPtr;
	dNode<value_type>* copyheadPtr = nullptr;
	dNode<value_type>* copytailPtr = nullptr;
	headPtr = nullptr;

	cout << "2020603007 김도엽 자료구조 Doubly-linked list 를 이용한 OurSet 구현" << endl << endl;

	cout << "//////////////////////////////////////////////////////" << endl;
	cout << "////////Node Function" << endl;
	cout << "//////////////////////////////////////////////////////" << endl << endl;

#pragma region Node_Function_Test

	cout << "////////Checking list_head_insert" << endl; 
	for (int i = 0; i < 22; i++)
	{
		list_head_insert<value_type>(headPtr, i);
	}

	cout << "////////Checking list_length" << endl;
	cout << "Doubly Linked list's length are " << list_length<value_type>(headPtr) << endl << endl;


	cout << "////////Checking list_show_content " << endl;
	list_show_contents<value_type>(headPtr);

	cout << "////////Checking list_search " << endl;
	dNode<value_type>* tailPtr = list_search(headPtr,0);
	dNode<value_type>* midPtr = list_search(headPtr,10);
	cout << "tail's data is " << tailPtr->getData() << endl;
	cout << "mid's data is " << midPtr->getData() << endl << endl;

	cout << "////////Checking list_locate " << endl;
	cout << "the data of node which index is 3 is " << list_locate(headPtr, 3)->getData() << endl << endl;

	cout << "////////Checking list_head_insert duplication" << endl;
	if (list_head_insert<value_type>(headPtr, 5) == false)
		cout << 5 << " already exists!" << endl << endl;

	cout << "////////Checking list_head_remove" << endl;
	list_head_remove<value_type>(headPtr);
	list_show_contents<value_type>(headPtr);

	cout << "////////Checking list_insert in tail" << endl;
	list_insert(tailPtr, 100);
	list_show_contents<value_type>(headPtr);
	
	cout << "////////Checking list_remove before tail" << endl;
	list_remove(tailPtr);
	list_show_contents<value_type>(headPtr);

	cout << "////////Checking list_insert in mid" << endl;
	list_insert(midPtr, 100);
	list_show_contents<value_type>(headPtr);

	cout << "////////Checking list_remove before mid" << endl;
	list_remove(midPtr);
	list_show_contents<value_type>(headPtr);

	cout << "////////Checking list_insert duplication in tail" << endl;
	if (list_insert<value_type>(tailPtr, 5) == false)
		cout << 5 << " already exists!" << endl << endl;

	cout << "////////Checking list_copy" << endl;
	list_copy(headPtr, copyheadPtr, copytailPtr);
	list_show_contents(copyheadPtr);

	cout << "////////Checking list_clear" << endl;
	list_clear(copyheadPtr);
	list_show_contents(copyheadPtr);
#pragma endregion Node_Function_Test

	cout << endl << endl;
	cout << "//////////////////////////////////////////////////////" << endl;
	cout << "////////OurSet Member Function" << endl;
	cout << "//////////////////////////////////////////////////////" << endl << endl	;




#pragma region OurSet_Member_Function_Test

	cout << "////////Checking Default Constructor." << endl;
	OurSet<value_type> Aset;
	OurSet<value_type> Cset;
	OurSet<value_type> Dset;

	for (int i = 0; i < 11; i++)
	{
		Dset.insert(i + 10);
	}

	cout << "////////Checking insert function." << endl;
	for (int i = 0; i < 11; i++)
	{
		Aset.insert(i);
	}
	Aset.show_contents();



	cout << "////////Checking erase_one function." << endl;
	Aset.erase_one();
	Aset.show_contents();

	cout << "////////Checking count function." << endl;
	cout << "There are " << Aset.getCount() << " numbers of data" << endl;
	Aset.show_contents();

	cout << "////////Checking copy constructor." << endl;
	OurSet<value_type> Bset(Aset);
	Bset.show_contents();

	cout << "////////Checking + Operator and = Operator." << endl;
	(Aset + Dset).show_contents();
	Cset = Aset + Dset;
	Cset.show_contents();

	cout << "////////Checking += Operator " << endl;
	Bset.show_contents();
	Bset += Dset;
	Bset.show_contents();


	cout << "////////Checking == Operator and != Operator " << endl;
	cout << (Bset == Cset) << endl;
	cout << (Bset == Aset) << endl;
	cout << (Bset != Cset) << endl;
	cout << (Bset != Aset) << endl << endl;




	cout << "////////Checking insertSort function " << endl;
	OurSet<value_type> Eset;
	for (int i = 0; i < 17; i++)
	{
		Eset.insert((3 + 19 * i) % 17);
	}
	Eset.insertSort();


	cout << "////////Checking Destructor " << endl;
#pragma endregion OurSet_Member_Function_Test


}

