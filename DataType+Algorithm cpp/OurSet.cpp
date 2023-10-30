#include"DoublyLinkedListNode.cpp"
namespace DataType
{

	template<class T>
	class OurSet
	{
	public:
		//Constructor and Destructor
		OurSet();
		OurSet(const OurSet& _ourSet);
		~OurSet();

		//Accessor and Mutator 
		void setCount(int _count);
		int getCount() const;
		void setHeadPtr(dNode<T>* _headPtr);
		dNode<T>* getHeadPtr() const;
		void setTailPtr(dNode<T>* _tailPtr);
		dNode<T>* getTailPtr() const;

		//Basic Fuction
		bool insert(const T _data);
		bool erase_one();
		void show_contents() const;

		//Operation Overloading
		OurSet<T>& operator=(const OurSet<T>& other);
		bool operator==(const OurSet<T>& other) const;
		bool operator!=(const OurSet<T>& other) const;
		OurSet<T> operator+(const OurSet<T>& other) const;
		OurSet<T>& operator+=(const OurSet<T>& other);

		//Operation Overloading for sort
		dNode<T>* operator[](int _index);
		void insertSort();

	private:
		int count;
		dNode<T>* headPtr;
		dNode<T>* tailPtr;
	};

#pragma region OurSetMemberFunction

	///////////////////////////////////////////////////////////
	//Constructor and Destructor

	template<class T>
	OurSet<T>::OurSet()
	{
		count = 0;
		headPtr = nullptr;
		tailPtr = nullptr;
		cout << "Default Constructor Called" << endl;
	}

	template<class T>
	OurSet<T>::OurSet(const OurSet<T>& _ourSet)
	{
		headPtr = nullptr;
		tailPtr = nullptr;
		count = _ourSet.count;
		list_copy(_ourSet.getHeadPtr(), headPtr, tailPtr);

	}

	template<class T>
	OurSet<T>::~OurSet()
	{
		count = 0;
		if (headPtr != nullptr)	list_clear(headPtr);
		cout << "Destructor Called." << endl;
	}

	///////////////////////////////////////////////////////////
	//Accessor and Mutator

	template<class T>
	void OurSet<T>::setCount(int _count)
	{
		count = _count;
	}

	template<class T>
	int OurSet<T>::getCount() const
	{
		return count;
	}

	template<class T>
	void OurSet<T>::setHeadPtr(dNode<T>* _headPtr)
	{
		headPtr = _headPtr;
	}

	template<class T>
	dNode<T>* OurSet<T>::getHeadPtr() const
	{
		return headPtr;
	}

	template<class T>
	void OurSet<T>::setTailPtr(dNode<T>* _tailPtr)
	{
		tailPtr = _tailPtr;
	}

	template<class T>
	dNode<T>* OurSet<T>::getTailPtr() const
	{
		return tailPtr;
	}

	///////////////////////////////////////////////////////////
	// Operator Overloading



	//PostCondition : Assignment
	template<class T>
	OurSet<T>& OurSet<T>::operator=(const OurSet<T>& other)
	{
		count = other.count;
		list_copy(other.headPtr, headPtr, tailPtr);
		return *this;
	}

	//PostCondition : return true if all node's data
	//                return false if there is mismatching data
	template<class T>
	bool OurSet<T>::operator==(const OurSet<T>& other) const
	{
		if (count != other.count) return false;

		dNode<T>* thisNow = headPtr;


		// loop until thisNow is tailPtr
		while (thisNow != nullptr)
		{
			// search thisNow's data in other
			if (list_search(other.headPtr, thisNow->getData()) == nullptr) return false;
			thisNow = thisNow->getNextPtr();
		}

		return true;
	}


	//PostCondition : return false if all node's data
	//                return true if there is mismatching data
	template<class T>
	bool OurSet<T>::operator!=(const OurSet<T>& other) const
	{
		return !(*this == other);
	}


	//PostCondition : return new Ourset which is summation of node of two Ourset
	template<class T>
	OurSet<T> OurSet<T>::operator+(const OurSet<T>& other) const
	{
		OurSet<T>* temp = new OurSet<T>(*this);

		*temp += other;

		return *temp;
	}


	//PostCondition : add Node which have not duplication data
	template<class T>
	OurSet<T>& OurSet<T>::operator+=(const OurSet<T>& other)
	{

		if (headPtr == nullptr) headPtr = other.headPtr;

		dNode<T>* otherNow = other.headPtr;
		while (otherNow != nullptr)
		{
			// duplication check. if there is no duplication, successfully insert and move tailPtr
			if (list_insert(tailPtr, otherNow->getData()) == true) tailPtr = tailPtr->getNextPtr();

			otherNow = otherNow->getNextPtr();
		}

		count += other.count;

		return *this;
	}

	///////////////////////////////////////////////////////////
	// Member Functions


	//PostCondition : add one data. return true when insert normal
	//                return false when there is duplication
	template<class T>
	bool OurSet<T>::insert(const T _data)
	{
		if (headPtr != nullptr)
		{
			// Duplication Check
			if (check_duplication(headPtr, _data)) return false;
		}

		if (list_head_insert(headPtr, _data))
		{
			count++;
			return true;
		}
		return false;

	}
	//PostCondition : remove one data. return true when erase normal
	//                return false when there is no data
	template<class T>
	bool OurSet<T>::erase_one()
	{
		if (count == 0) return false;

		count--;
		list_head_remove(headPtr);
		return true;
	}

	//PostCondition : show count, index, data.
	template<class T>
	void OurSet<T>::show_contents() const
	{

		list_show_contents(headPtr);
	}

	////////////////////////////////////////////////////////
	//Operator overloading for sort


	//PostCondition : return _index th of node's pointer
	//                return nullptr when index out of range
	template<class T>
	dNode<T>* OurSet<T>::operator[](int _index)
	{
		if (_index >= count) return nullptr;
		return list_locate(headPtr, _index);
	}

	template<class T>
	void OurSet<T>::insertSort()
	{
		dNode<T>* prevNode;
		dNode<T>* nowNode;
		int nowData;
		bool trigger;
		for (int i = 1; i < count; i++)
		{
			prevNode = this->operator[](i - 1);
			nowData = this->operator[](i)->getData();
			//trigger which nowData is smallest.
			trigger = true;


			for (int j = 0; j < i; j++)
			{
				// compare data index i to index 1 ~ index i-1. continue if big , insert if small
				dNode<T>* temp = this->operator[](i - 1 - j);
				if (temp->getData() > nowData) continue;
				list_remove(prevNode);
				list_insert(temp, nowData);

				trigger = false;
				break;
			}


			if (trigger)
			{
				list_remove(prevNode);
				list_head_insert(headPtr, nowData);
			}

			show_contents();
		}
	}
#pragma endregion OurSetMemberFunction


	/*
	ofstream file;
	file.open("output.txt", ios_base::out | ios_base::app);
	cout.rdbuf(file.rdbuf());
	*/

//	typedef int value_type;
//	dNode<value_type>* headPtr;
//	dNode<value_type>* copyheadPtr = nullptr;
//	dNode<value_type>* copytailPtr = nullptr;
//	headPtr = nullptr;
//
//	cout << "2020603007 김도엽 자료구조 Doubly-linked list 를 이용한 OurSet 구현" << endl << endl;
//
//	cout << "//////////////////////////////////////////////////////" << endl;
//	cout << "////////Node Function" << endl;
//	cout << "//////////////////////////////////////////////////////" << endl << endl;
//
//#pragma region Node_Function_Test
//
//	cout << "////////Checking list_head_insert" << endl;
//	for (int i = 0; i < 22; i++)
//	{
//		list_head_insert<value_type>(headPtr, i);
//	}
//
//	cout << "////////Checking list_length" << endl;
//	cout << "Doubly Linked list's length are " << list_length<value_type>(headPtr) << endl << endl;
//
//
//	cout << "////////Checking list_show_content " << endl;
//	list_show_contents<value_type>(headPtr);
//
//	cout << "////////Checking list_search " << endl;
//	dNode<value_type>* tailPtr = list_search(headPtr, 0);
//	dNode<value_type>* midPtr = list_search(headPtr, 10);
//	cout << "tail's data is " << tailPtr->getData() << endl;
//	cout << "mid's data is " << midPtr->getData() << endl << endl;
//
//	cout << "////////Checking list_locate " << endl;
//	cout << "the data of node which index is 3 is " << list_locate(headPtr, 3)->getData() << endl << endl;
//
//	cout << "////////Checking list_head_insert duplication" << endl;
//	if (list_head_insert<value_type>(headPtr, 5) == false)
//		cout << 5 << " already exists!" << endl << endl;
//	list_show_contents(headPtr);
//
//	cout << "////////Checking list_head_remove" << endl;
//	list_head_remove<value_type>(headPtr);
//	list_show_contents<value_type>(headPtr);
//
//	cout << "////////Checking list_insert in tail" << endl;
//	list_insert(tailPtr, 100);
//	list_show_contents<value_type>(headPtr);
//
//	cout << "////////Checking list_remove before tail" << endl;
//	list_remove(tailPtr);
//	list_show_contents<value_type>(headPtr);
//
//	cout << "////////Checking list_insert in mid" << endl;
//	list_insert(midPtr, 100);
//	list_show_contents<value_type>(headPtr);
//
//	cout << "////////Checking list_remove before mid" << endl;
//	list_remove(midPtr);
//	list_show_contents<value_type>(headPtr);
//
//	cout << "////////Checking list_insert duplication in tail" << endl;
//	if (list_insert<value_type>(tailPtr, 5) == false)
//		cout << 5 << " already exists!" << endl << endl;
//
//	cout << "////////Checking list_copy" << endl;
//	list_copy(headPtr, copyheadPtr, copytailPtr);
//	list_show_contents(copyheadPtr);
//
//	cout << "////////Checking list_clear" << endl;
//	list_clear(copyheadPtr);
//	list_show_contents(copyheadPtr);
//#pragma endregion Node_Function_Test
//
//	cout << endl << endl;
//	cout << "//////////////////////////////////////////////////////" << endl;
//	cout << "////////OurSet Member Function" << endl;
//	cout << "//////////////////////////////////////////////////////" << endl << endl;
//
//
//
//
//#pragma region OurSet_Member_Function_Test
//
//	cout << "////////Checking Default Constructor." << endl;
//	OurSet<value_type> Aset;
//	OurSet<value_type> Cset;
//	OurSet<value_type> Dset;
//
//	for (int i = 0; i < 11; i++)
//	{
//		Dset.insert(i + 10);
//	}
//
//	cout << "////////Checking insert function." << endl;
//	for (int i = 0; i < 11; i++)
//	{
//		Aset.insert(i);
//	}
//	Aset.show_contents();
//	Aset.insert(5);
//	Aset.show_contents();
//
//
//	cout << "////////Checking erase_one function." << endl;
//	Aset.erase_one();
//	Aset.show_contents();
//
//	cout << "////////Checking count function." << endl;
//	cout << "There are " << Aset.getCount() << " numbers of data" << endl;
//	Aset.show_contents();
//
//	cout << "////////Checking copy constructor." << endl;
//	OurSet<value_type> Bset(Aset);
//	Bset.show_contents();
//
//	cout << "////////Checking + Operator and = Operator." << endl;
//	(Aset + Dset).show_contents();
//	Cset = Aset + Dset;
//	Cset.show_contents();
//
//	cout << "////////Checking += Operator " << endl;
//	Bset.show_contents();
//	Bset += Dset;
//	Bset.show_contents();
//
//
//	cout << "////////Checking == Operator and != Operator " << endl;
//	cout << (Bset == Cset) << endl;
//	cout << (Bset == Aset) << endl;
//	cout << (Bset != Cset) << endl;
//	cout << (Bset != Aset) << endl << endl;
//
//
//
//
//	cout << "////////Checking insertSort function " << endl;
//	OurSet<value_type> Eset;
//	for (int i = 0; i < 17; i++)
//	{
//		Eset.insert((3 + 19 * i) % 17);
//	}
//	Eset.insertSort();
//
//
//	cout << "////////Checking Destructor " << endl;
//#pragma endregion OurSet_Member_Function_Test
}