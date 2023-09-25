#ifndef __DOUBLYLINKEDLISTNODE__
#define __DOUBLYLINKEDLISTNODE__
#include<iostream>
using namespace std;

namespace DataType
{
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
		// Constructor implementation here
	}

	template<class T>
	dNode<T>::dNode(T _data, dNode* _prevPtr, dNode* _nextPtr)
	{
		// Constructor implementation here
	}

	template<class T>
	dNode<T>::dNode(const dNode& _dNode)
	{
		// Constructor implementation here
	}

	template<class T>
	dNode<T>::~dNode()
	{
		// Destructor implementation here
	}

	///////////////////////////////////////////////////////////
	//Accessor and Mutator

	template<class T>
	void dNode<T>::setData(T _data)
	{
		// Implementation for setData
	}

	template<class T>
	T dNode<T>::getData() const
	{
		// Implementation for getData
	}

	template<class T>
	void dNode<T>::setNextPtr(dNode* _nextPtr)
	{
		// Implementation for setNextPtr
	}

	template<class T>
	dNode<T>* dNode<T>::getNextPtr() const
	{
		// Implementation for getNextPtr
	}

	template<class T>
	void dNode<T>::setPrevPtr(dNode* _prevPtr)
	{
		// Implementation for setPrevPtr
	}

	template<class T>
	dNode<T>* dNode<T>::getPrevPtr() const
	{
		// Implementation for getPrevPtr
	}
#pragma endregion dNodeMemberFunction

#pragma region dNodeFunction

	//PostCondition : return true if _dNodePtr is nullptr. 
	//                return false. if not. 
	bool isNullPtr(dNode<T>* _dNodePtr)
	{
		if (_dNodePtr == nullptr)
			cout << "Error : NullPointer received. \n" << endl;
			return true;
		return false;
	}

	//PostCondition : return length(Count) of LinkedList
	template<class T>
	int list_length(dNode<T>* _headPtr)
	{

	}

	//PostCondition : return pointer of dNode which data is _data. 
	//                return nullptr when cannot found _data
	template<class T>
	dNode<T>* list_search(dNode<T>* _headPtr, T _data)
	{

	}
	
	//PreCondition  : _index is not out of range - can handle : 0 ~ Count-1
	//PostCondition : return data of dNode which is in _index th . 
	template<class T>
	T list_locate(dNode<T>* _headPtr, int _index)
	{

	}
	
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
		// Constructor implementation here
	}

	template<class T>
	OurSet<T>::OurSet(const OurSet<T>& _ourSet)
	{
		// Constructor implementation here
	}

	template<class T>
	OurSet<T>::~OurSet()
	{
		// Destructor implementation here
	}

	///////////////////////////////////////////////////////////
	//Accessor and Mutator

	template<class T>
	void OurSet<T>::setCount(int _count)
	{
		// Implementation for setCount
	}

	template<class T>
	int OurSet<T>::getCount() const
	{
		// Implementation for getCount
	}

	template<class T>
	void OurSet<T>::setHeadPtr(dNode<T>* _headPtr)
	{
		// Implementation for setHeadPtr
	}

	template<class T>
	dNode<T>* OurSet<T>::getHeadPtr() const
	{
		// Implementation for getHeadPtr
	}

	template<class T>
	void OurSet<T>::setTailPtr(dNode<T>* _tailPtr)
	{
		// Implementation for setTailPtr
	}

	template<class T>
	dNode<T>* OurSet<T>::getTailPtr() const
	{
		// Implementation for getTailPtr
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