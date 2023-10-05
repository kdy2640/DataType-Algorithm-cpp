#ifndef __DOUBLYLINKEDLISTNODE__
#define __DOUBLYLINKEDLISTNODE__
#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

namespace DataType
{
	// Node which is intenden to store int/float data
	template<class T>
	class dNode
	{
	public:
		//Constructor and Destructor
		dNode();
		dNode(T _data, dNode* _prevPtr = nullptr, dNode* _nextPtr = nullptr);
		dNode(const dNode& _dNode);
		~dNode();

		//Accessor and Mutator
		void setData(T _data);
		T getData() const;
		void setNextPtr(dNode* _nextPtr);
		dNode* getNextPtr() const;
		void setPrevPtr(dNode* _prevPtr);
		dNode* getPrevPtr() const;
		
	private:
		dNode* nextPtr;
		dNode* prevPtr;
		T data;
	};
#pragma region dNodeMemberFunction
	///////////////////////////////////////////////////////////
	//Constructor and Destructor

	template<class T>
	dNode<T>::dNode()
	{
		nextPtr = nullptr;
		prevPtr = nullptr;
		data = 0;
	}

	template<class T>
	dNode<T>::dNode(T _data, dNode* _prevPtr, dNode* _nextPtr)
	{
		nextPtr = _nextPtr;
		prevPtr = _prevPtr;
		data = _data;
	}

	template<class T>
	dNode<T>::dNode(const dNode& _dNode)
	{
		nextPtr = _dNode.nextPtr;
		prevPtr = _dNode.prevPtr;
		data = _dNode.data;
	}

	template<class T>
	dNode<T>::~dNode()
	{
		// Nothing to do.
	}

	///////////////////////////////////////////////////////////
	//Accessor and Mutator

	template<class T>
	void dNode<T>::setData(T _data)
	{
		data = _data;
	}

	template<class T>
	T dNode<T>::getData() const
	{
		return data;
	}

	template<class T>
	void dNode<T>::setNextPtr(dNode* _nextPtr)
	{
		nextPtr = _nextPtr;
	}

	template<class T>
	dNode<T>* dNode<T>::getNextPtr() const
	{
		return nextPtr;
	}

	template<class T>
	void dNode<T>::setPrevPtr(dNode* _prevPtr)
	{
		prevPtr = _prevPtr;
	}

	template<class T>
	dNode<T>* dNode<T>::getPrevPtr() const
	{
		return prevPtr;
	}
#pragma endregion dNodeMemberFunction

#pragma region dNodeFunction

	//PostCondition : return true if _dNodePtr is nullptr. 
	//                return false. if not. 
	template<class T>
	bool isNullPtr(const dNode<T>* _dNodePtr)
	{
		if (_dNodePtr == nullptr)
		{
			cout << "Error : NullPointer received. \n";
			return true;
		}
		return false;
	}


	//PreCondition  : argument must be head pointer. 
	//PostCondition : return length(Count) of LinkedList
	template<class T>
	int list_length(const dNode<T>* _headPtr)
	{

		const dNode<T>* now = _headPtr;
		int count = 0;
		// loop until now is nullptr
		while (now != nullptr)
		{
			now = now->getNextPtr();
			++count;
		}

		return count;
	}


	//PostCondition : Search forward and return pointer of dNode which data is _data. 
	//                return nullptr when cannot found _data.
	template<class T>
	const dNode<T>* list_search(const dNode<T>* _headPtr, T _data)
	{
		//NullPtr Check
		assert(!isNullPtr(_headPtr));

		const dNode<T>* now = _headPtr;

		// loop until now is nullptr
		while (now != nullptr)
		{
			if (now->getData() == _data)
			{
				break;
			}
			now = now->getNextPtr();
		}

		return now;

	}

	//PostCondition : Search forward and return pointer of dNode which data is _data. 
	//                return nullptr when cannot found _data. it is nonconst overloading
	template<class T>
	dNode<T>* list_search(dNode<T>* _headPtr, T _data)
	{
		//NullPtr Check
		assert(!isNullPtr(_headPtr));

		dNode<T>* now = _headPtr;

		// loop until now is nullptr
		while (now != nullptr)
		{
			if (now->getData() == _data)
			{
				break;
			}
			now = now->getNextPtr();
		}

		return now;

	}

	//PostCondition : Search backward and return pointer of dNode which data is _data. 
	//                return nullptr when cannot found _data.
	template<class T>
	const dNode<T>* list_search_reverse(const dNode<T>* _tailPtr, T _data)
	{
		//NullPtr Check
		assert(!isNullPtr(_tailPtr));

		const dNode<T>* now = _tailPtr;

		// loop until now is nullptr
		while (now != nullptr)
		{
			if (now->getData() == _data)
			{
				break;
			}
			now = now->getPrevPtr();
		}

		return now;

	}
	//PostCondition : Search backward and return pointer of dNode which data is _data. 
	//                return nullptr when cannot found _data. it is nonconst overloading
	template<class T>
	dNode<T>* list_search_reverse(dNode<T>* _tailPtr, T _data)
	{
		//NullPtr Check
		assert(!isNullPtr(_tailPtr));

		dNode<T>* now = _tailPtr;

		// loop until now is nullptr
		while (now != nullptr)
		{
			if (now->getData() == _data)
			{
				break;
			}
			now = now->getPrevPtr();
		}

		return now;

	}

	

	//PostCondition : return true when there is Node which data is _data
	//              : return false when there is not Node which Data is _data 
	template<class T>
	bool check_duplication(const dNode<T>* _startPtr, T _data)
	{
		// NullPtr Check
		assert(!isNullPtr(_startPtr));

		// true when there is Node which data is _data after _startPtr
		bool checkForward = list_search(_startPtr, _data) != nullptr;
		 
		// to reduce Overhead, check first.
		if (checkForward) return true;

		// true when there is Node which data is _data before _startPtr
		bool checkBackward = list_search_reverse(_startPtr, _data) != nullptr;

		if (checkBackward) return true;

		return false;
	}


	//PreCondition  : argument must be head pointer. 
	//                _index is not out of range - can handle : 0 ~ Count-1
	//PostCondition : return data of dNode which is in _index th . 
	//				  return -1 when cannnot found _data or Index out of range
	template<class T>
	dNode<T>* list_locate(dNode<T>* _headPtr, int _index)
	{
		// NullPtr Check
		assert(!isNullPtr(_headPtr));

		dNode<T>* now = _headPtr;
		int index = 0;


		// loop until now is nullptr
		while (now != nullptr)
		{
			if (index == _index)
			{
				return now();
			}
			++index;
			now = now->getNextPtr();
		}

		// Index Out of Range
		if (index <= _index)
		{
			cout << "ERROR : Index Out Of Range. \n";
		}

		return -1;

	}


	//PreCondition  : argument must be head pointer. 
	//PostCondition : change _headPtr to new node and linking node
	//				  if _HeadPtr is nullptr, change _headPtr to new Node's address.
	//                return false when there is duplication. return true when there is not.
	template<class T>
	bool list_head_insert(dNode<T>*& _headPtr, T _data)
	{
		// NullPtr Check - if null, there is no node.
		if (_headPtr == nullptr)
		{
			_headPtr = new dNode<T>(_data, nullptr, nullptr);
			return true;
		}
		// Duplication Check
		if (check_duplication(_headPtr, _data)) return false;

		// create newNode which prevptr is nullptr and nextPtr is _headPtr's next node.
		dNode<T>* newNode = new dNode<T>(_data, nullptr, _headPtr);
		// change _headPtr;
		_headPtr = newNode;
		
		// set next of newNode's prevPTr to new node
		newNode->getNextPtr()->setPrevPtr(newNode);

		return true;
	}


    //PostCondition : insert after _prevPtr and linking node.
	//                return false when there is duplication. return true when is not.
	template<class T>
	bool list_insert(dNode<T>* _prevPtr, T _data)
	{
		// NullPtr Check
		assert(!isNullPtr(_prevPtr));
		// Duplication Check
		if (check_duplication(_prevPtr, _data)) return false;
		
		// create new node which prevptr is nullptr and nextPtr is _prevPtr's next node.
		dNode<T>* newNode = new dNode<T>(_data, _prevPtr, _prevPtr->getNextPtr());
		// set _prevPtr's nextPtr to newNode
		_prevPtr->setNextPtr(newNode);

		// check for _prevPr is tail == ( newNode's nextPtr = null )
		if (newNode->getNextPtr() != nullptr)
		{
			//set prevPtr of newNode's nextPtr to newNode;
			newNode->getNextPtr()->setPrevPtr(newNode);
		}
		return true;
	}


	//PreCondition  : argument must be head pointer.
	//PostCondition : remove first Node and replace _headPtr to second Node
	//                if there is no second Node, _headPtr will be nullptr
 	template<class T>
	void list_head_remove(dNode<T>*& _headPtr)
	{
		// NullPtr Check
		assert(!isNullPtr(_headPtr));

		dNode<T>* temp = _headPtr;
		// set _headPtr to second Node
		_headPtr = _headPtr->getNextPtr();

		// Check for only one node
		if (_headPtr != nullptr)
		{
			// set first Node's prevPtr to nullptr
			_headPtr->setPrevPtr(nullptr);
		}
		// delete previous first 
		delete temp;
	}


	//PreCondition  : _prevPtr is not be Tail Node to remove _prevPtr's next Node  
	//PostCondition : remove next Node of _prevPtr and linking Node
	//                if there is no next next Node, _prevPtr's nextPtr will be nullptr
	template<class T>
	void list_remove(dNode<T>* _prevPtr)
	{
		// NullPtr Check
		assert(!isNullPtr(_prevPtr));
		assert(!isNullPtr(_prevPtr->getNextPtr()));
		
		dNode<T>* temp = _prevPtr->getNextPtr();
		// set _prevPtr's nextPtr to its next next Node
		_prevPtr->setNextPtr(temp->getNextPtr());

		// Check for only one node after _prevPtr => temp->getNextPtr == nullptr
		if (temp->getNextPtr() != nullptr)
		{
			//set _prevPtr's next next Node's prevPtr to _prevPtr
			temp->getNextPtr()->setPrevPtr(_prevPtr);
		}

		// delete _prevPtr's next Node
		delete temp;
	}

	//PreCondition  : argument must be head pointer.
	//PostCondition : remove all node 
	template<class T>
	void list_clear(dNode<T>*& _headPtr)
	{
		// NullPtr Check
		assert(!isNullPtr(_headPtr));

		while (_headPtr != nullptr)
		{
			list_head_remove(_headPtr);
		}

	}

	//PreCondition  : each argument must be sourcePtr, head pointer and tail pointer.
	//PostCondition : deep copy doubly linked list 
	template<class T>
	void list_copy(const dNode<T>* _sourcePtr, dNode<T>*& _headPtr,dNode<T>*& _tailPtr)
	{
		// NullPtr Check
		assert(!isNullPtr(_sourcePtr));

		//set _headPtr to new node which data is _sourcePtr's first node's data
		_headPtr = list_head_insert(_headPtr, _sourcePtr->getData());
		dNode<T>* now = _headPtr;
		_sourcePtr = _sourcePtr->getNextPtr();

		while (_sourcePtr != nullptr)
		{
			// insert node after now which data is _sourcePtr
			list_insert(now, _sourcePtr->getData());
			// move _sourcePtr to next ptr - if nullptr
			_sourcePtr = _sourcePtr->getNextPtr();
			// move now to tailPtr
			now = now->getNextPtr();
		}
		_tailPtr = now;
	}

	//PreCondition  : argument must be head pointer.
	//PostCondition : print linkedlist data. return true when print normally
	//                return false when there is error.
	template<class T>
	bool list_show_contents(const dNode<T>* _headPtr)
	{
		// NullPtr Check
		if (_headPtr == nullptr)
		{
			cout << "//////////////////////////////////////////////////////" << endl;
			cout << "ERROR: _headPtr is nullptr." << endl;
			cout << "//////////////////////////////////////////////////////" << endl;
		}

		const dNode<T>* now = _headPtr;
		int count = 1;
		// loop until now is tail
		while (now->getNextPtr() != nullptr)
		{
			++count;
			now = now->getNextPtr();
		}
		T* datas = new T[count];
		
		int index = 1;

		// loop until now is head
		while (now->getPrevPtr() != nullptr)
		{
			//
			datas[count - index] = now->getData();

			++index;
			now = now->getPrevPtr();
		}

		datas[count - index] = now->getData();

		cout << "//////////////////////////////////////////////////////" << endl;
		if (index != count)
		{
			cout << "ERROR : linking abnormally." << endl;
			cout << "//////////////////////////////////////////////////////" << endl;
			return false;
		}
		
		int len = *(new int((int)log10(count) + 2));
		cout << "Index : ";
		for (int i = 0; i < count; i++)
		{
			cout.width(len);
			cout << i;
			cout << " ";
		}
		cout << endl;
		cout << "Datas : ";
		for (int i = 0; i < count; i++)
		{
			cout.width(len);
			cout << datas[i];
			cout << " ";
		}
		cout << endl;
		cout << "//////////////////////////////////////////////////////" << endl;
		return true;
		

	}

	//  list_show_status 

	
#pragma endregion dNodeFunction

	template<class T>
	class OurSet
	{
	public:
		//Constructor and Destructor
		OurSet();
		OurSet(const OurSet& _ourSet);
		~OurSet();
		
		//Accessor and Mutator 
		void setCount(int _count) ;
		int getCount() const;
		void setHeadPtr(dNode<T>* _headPtr);
		dNode<T>* getHeadPtr() const;
		void setTailPtr(dNode<T>* _tailPtr);
		dNode<T>* getTailPtr() const;

		//Basic Fuction
		void insert(const T& value);
		bool erase_one(const T& value);
		void show_contents() const;

		//Operation Overloading
		OurSet<T>& operator=(const OurSet<T>& other);
		bool operator==(const OurSet<T>& other) const;
		bool operator!=(const OurSet<T>& other) const;
		OurSet<T> operator+(const OurSet<T>& other) const;
		OurSet<T>& operator+=(const OurSet<T>& other);
		
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
	}

	template<class T>
	OurSet<T>::OurSet(const OurSet<T>& _ourSet)
	{
		count = _ourSet.count;
		list_copy(_ourSet.getHeadPtr(), headPtr, tailPtr);
	}

	template<class T>
	OurSet<T>::~OurSet()
	{
		count = 0;
		list_clear(headPtr);
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

	template<class T>
	OurSet<T>& OurSet<T>::operator=(const OurSet<T>& other)
	{
		// Assignment operator implementation here
		return *this;
	}

	template<class T>
	bool OurSet<T>::operator==(const OurSet<T>& other) const
	{
		// Equality operator implementation here
		return false;
	}

	template<class T>
	bool OurSet<T>::operator!=(const OurSet<T>& other) const
	{
		// Inequality operator implementation here
		return false;
	}

	template<class T>
	OurSet<T> OurSet<T>::operator+(const OurSet<T>& other) const
	{
		// Addition operator implementation here
		return *this;
	}

	template<class T>
	OurSet<T>& OurSet<T>::operator+=(const OurSet<T>& other)
	{
		// Addition-Assignment operator implementation here
		return *this;
	}

	///////////////////////////////////////////////////////////
	// Member Functions
	template<class T>
	void OurSet<T>::insert(const T& value)
	{
		// Insert implementation here
	}

	template<class T>
	bool OurSet<T>::erase_one(const T& value)
	{
		// Erase one implementation here
		return false;
	}

	template<class T>
	void OurSet<T>::show_contents() const
	{
		// Show contents implementation here
	}
#pragma endregion OurSetMemberFunction

}

#endif