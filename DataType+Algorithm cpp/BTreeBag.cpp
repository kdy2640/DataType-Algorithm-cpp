#ifndef __BTreeBag__
#define __BTreeBag__
#include"BTreeNode.cpp" 

namespace DataType
{

	template<class T, int MIN>
	class BTree
	{
	public:
		// Constructor and Destructor
		BTree(bTNode<T, MIN>* _rootPtr = nullptr);  
		~BTree();
		
		// Accessor and Mutator
		void setRootPtr(bTNode<T, MIN>* _rootPtr);
		bTNode<T, MIN>* getRootPtr();

		// Basic Function 
		// 
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
		//
		bool loose_insert(T _data);
		//
		bool loose_erase_one(T _data);
		//
		bool fix_shortage();
		//
		bool fix_excess();


		bTNode<T,MIN>* rootPtr;
	};
}



#endif  __BTreeBag__
