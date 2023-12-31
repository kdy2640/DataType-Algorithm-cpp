#include"DoublyLinkedListNode.cpp"

namespace DataType
{
	template<class T>
	class OurDeque
	{
	public:

		//Constructor and Destructor
		OurDeque();
		OurDeque(const OurDeque& _ourDeque);
		~OurDeque();

		//Accessor and Mutator 
		void setCount(int _count);
		int getCount() const;
		void setHeadPtr(dNode<T>* _headPtr);
		dNode<T>* getHeadPtr() const;
		void setTailPtr(dNode<T>* _tailPtr);
		dNode<T>* getTailPtr() const;

		//Basic Fuction for Deque
		void push_front(T _data);
		void push_back(T _data);
		T pop_front();
		T pop_back();
		T front() const;
		T back() const;
		
		bool empty() const;
		int size() const;
		void show_contents() const;


		//Operation Overloading
		OurDeque<T>& operator=(const OurDeque<T>& other);

	private:
		// head is first, tail is last
		dNode<T>* headPtr;
		dNode<T>* tailPtr;
		int count;
	};


#pragma region OurDequeMemberFunction

	///////////////////////////////////////////////////////////
	//Constructor and Destructor

	template<class T>
	OurDeque<T>::OurDeque()
	{
		count = 0;
		headPtr = nullptr;
		tailPtr = nullptr;
	}

	template<class T>
	OurDeque<T>::OurDeque(const OurDeque<T>& _ourDeque)
	{
		headPtr = nullptr;
		tailPtr = nullptr;
		count = _ourDeque.count;
		list_copy(_ourDeque.getHeadPtr(), headPtr, tailPtr);

	}

	template<class T>
	OurDeque<T>::~OurDeque()
	{
		count = 0;
		if (headPtr != nullptr)	list_clear(headPtr);
	}

	///////////////////////////////////////////////////////////
	//Accessor and Mutator

	template<class T>
	void OurDeque<T>::setCount(int _count)
	{
		count = _count;
	}

	template<class T>
	int OurDeque<T>::getCount() const
	{
		return count;
	}

	template<class T>
	void OurDeque<T>::setHeadPtr(dNode<T>* _headPtr)
	{
		headPtr = _headPtr;
	}

	template<class T>
	dNode<T>* OurDeque<T>::getHeadPtr() const
	{
		return headPtr;
	}

	template<class T>
	void OurDeque<T>::setTailPtr(dNode<T>* _tailPtr)
	{
		tailPtr = _tailPtr;
	}

	template<class T>
	dNode<T>* OurDeque<T>::getTailPtr() const
	{
		return tailPtr;
	}


	///////////////////////////////////////////////////////////
	// Operator Overloading

	//PostCondition : Assignment
	template<class T>
	OurDeque<T>& OurDeque<T>::operator=(const OurDeque<T>& other)
	{
		count = other.count;
		list_copy(other.headPtr, headPtr, tailPtr);
		return *this;
	}

	///////////////////////////////////////////////////////////
	// Member Functions



	template<class T>
	void OurDeque<T>::push_front(T _data)
	{

		list_head_insert(headPtr, _data);
		if (count == 0)
		{
			tailPtr = headPtr;
		}
		count++;
	}

	template<class T>
	void OurDeque<T>::push_back(T _data)
	{
		if (count == 0)
		{
			tailPtr = new dNode<T>(_data);
			headPtr = tailPtr;
		}
		else
		{
			// create new node which prevPtr is tailPtr Ptr and nexPtr is nullptr
			dNode<T>* temp = new dNode<T>(_data, tailPtr, nullptr);
			//set tailPtr's nextPtr to temp
			tailPtr->setNextPtr(temp);
			tailPtr = temp;
		}
		count++;
	}

	template<class T>
	T OurDeque<T>::pop_front()
	{
		assert(!empty());
		T tempdata = headPtr->getData();
		list_head_remove(headPtr);
		if (count == 1) tailPtr = nullptr;
		count--;
		return tempdata;
	}

	template<class T>
	T OurDeque<T>::pop_back()
	{
		assert(!empty());
		// save return value and delete pointer
		T tempdata = tailPtr->getData();
		dNode<T>* temp = tailPtr;

		if (count == 1)
		{
			tailPtr = nullptr;
			headPtr = nullptr;
		}
		else
		{
			// move tailPtr to its prevPTr
			tailPtr = tailPtr->getPrevPtr();
			// set tailPtr's nextPtr to nullPtr
			tailPtr->setNextPtr(nullptr);
		}
		
		count--;
		delete temp;
		return tempdata;
	}

	template<class T>
	T OurDeque<T>::front() const
	{
		return headPtr->getData();
	}

	template<class T>
	T OurDeque<T>::back() const
	{
		return tailPtr->getData();
	}

	template<class T>
	bool OurDeque<T>::empty() const
	{
		if (count == 0) return true;

		return false;
	}

	template<class T>
	int OurDeque<T>::size() const
	{
		return count;
	}

	//PostCondition : show count, index, data.
	template<class T>
	void OurDeque<T>::show_contents() const
	{
		list_show_contents(headPtr);
	}

	
#pragma endregion OurDequeMemberFunction


}