#ifndef __BTreeBag__
#define __BTreeBag__
#include"BTreeNode.cpp" 

namespace DataType
{

	template<class T, int MIN>
	class BTreeBag
	{
	public:
		// Constructor and Destructor
		BTreeBag(bTNode<T, MIN>* _rootPtr = nullptr);  
		~BTreeBag();
		
		// Accessor and Mutator
		void setRootPtr(bTNode<T, MIN>* _rootPtr);
		bTNode<T, MIN>* getRootPtr();

		// Basic Function 
		// return 0 if not founded. return 1 if founded 
		int count(T _data) const;
		//
		bool insert(T _data);
		//
		bool erase_one(T _data);
		//
		bool remove_biggest();
		//
		bool show_contents() const;


	private:

		bTNode<T,MIN>* rootPtr;
	};

#pragma region BTreeBagMemberFunction

	///////////////////////////////////////////////////////////
	// Constructor and Destructor and Accessor and Mutator
	template<class T, int MIN>
	BTreeBag<T, MIN>::BTreeBag(bTNode<T, MIN>* _rootPtr)
	{
		if (_rootPtr == nullptr)
		{
			rootPtr = new bTNode<T, MIN>();
		}
	}
	template<class T, int MIN>
	BTreeBag<T, MIN>::~BTreeBag()
	{
		delete rootPtr;
	}
	template<class T, int MIN>
	void BTreeBag<T, MIN>::setRootPtr(bTNode<T, MIN>* _rootPtr)
	{
		rootPtr = _rootPtr
	}
	template<class T, int MIN>
	bTNode<T, MIN>* BTreeBag<T, MIN>::getRootPtr()
	{
		return rootPtr;
	}

	/////////////////////////////////////////////////////////
	// Basic Function
	template<class T, int MIN>
	int BTreeBag<T, MIN>::count(T _data) const
	{
		int rootDataCount = rootPtr->getDataCount();
		for (int i = 0; i < rootDataCount; i++)
		{

		}
	}
	template<class T, int MIN>
	bool BTreeBag<T, MIN>::insert(T _data)
	{
		return false;
	}
	template<class T, int MIN>
	bool BTreeBag<T, MIN>::erase_one(T _data)
	{
		return false;
	}
	template<class T, int MIN>
	bool BTreeBag<T, MIN>::remove_biggest()
	{
		return false;
	}
	template<class T, int MIN>
	bool BTreeBag<T, MIN>::show_contents() const
	{
		return false;
	} 

#pragma endregion BTreeBagMemberFunction


}

#endif  __BTreeBag__
