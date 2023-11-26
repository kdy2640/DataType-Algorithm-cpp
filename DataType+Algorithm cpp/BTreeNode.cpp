
#ifndef __BTREENODE__
#define __BTREENODE__
#include<iostream>

namespace DataType
{

	// MIN is bTree's minimal  
	// Node which is intended to store int/float/double data
	template <class T, int MIN>
	class bTNode
	{
	public:
		static const int MAX = MIN * 2;

		//Constructor and Desturctor
		bTNode(bTNode* _parentPtr = nullptr);
		bTNode(const bTNode& _node);
		~bTNode();

		//Accessor and Mutator - there is no mutator of subTreeArr & dataArr for improving safety
		void setParentPtr(bTNode* _parentPtr);
		void setDataCount(int _count);
		void setSubTreeCount(int _count);

		bTNode* getParentPtr() const;
		int getDataCount() const;
		int getSubTreeCount() const;

		// return Ptr of SubTreePtr's array
		bTNode** getSubTree()  const;  


		// BasicFunction 
 
		// return 0 when there is no _data. if there are _data, return its count;  
		int node_count(T _data) const;
		//
		bool node_insert(T _data);
		//
		bool node_erase_one(T _data);
		//
		bool node_remove_biggest();
		//
		bool node_show_contents() const; 


		//Operator Overloading
		T& operator[](int _index);   // random access to data array
		T& operator[](int _index) const;   // random access to data array for const 
		bTNode& operator = (const bTNode& _node);
		
		// these operator intend to check dataArr and subtree's data for _data
		bool operator < (T _data);
		bool operator > (T _data);
		bool operator <= (T _data);
		bool operator >= (T _data);

		// depth + 1 , depth - 1
		void operator ++ (int); 
		void operator--(int);
		 
		int depth;
	private:

		void sort(); // dataArray must be sorted


		//
		bool loose_insert(T _data);
		//
		bool loose_erase_one(T _data);
		//
		bool fix_shortage();
		//
		bool fix_excess();


		bTNode* parentPtr;
		bTNode** subTreeArr;
		T* dataArr;
		int dCount;
		int sCount;
	};

#pragma region bTNodeFunction

	/////////////////////////////////////////////////////////////////
	// Constructor and Destructor


	template<class T, int MIN>
	bTNode<T, MIN>::bTNode(bTNode* _parentPtr)
	{
		parentPtr = _parentPtr;
		dataArr = new T[MAX + 1];
		subTreeArr = new bTNode * [MAX + 1];
		dCount = 0; sCount = 0; depth = 0;
	}

	template<class T, int MIN>
	bTNode<T, MIN>::bTNode(const bTNode& _node)
	{
		parentPtr = _node.parentPtr;
		dCount = _node.dCount;
		sCount = _node.sCount;
		depth = _node.depth;
		dataArr = new T[MAX + 1];
		subTreeArr = new bTNode * [MAX + 1];

		//dataArr deep copy
		for (int i = 0; i < dCount; i++)
		{
			dataArr[i] = _node[i];
		}

		//subTreeArr deep copy
		for (int i = 0; i < sCount; i++)
		{
			subTreeArr[i] = new bTNode(*_node.subTreeArr[i]);
		}
	}

	template<class T, int MIN>
	bTNode<T, MIN>::~bTNode()
	{
		delete[] dataArr;
		for (int i = 0; i < sCount; i++)
		{
			delete subTreeArr[i];
		}

		delete[] subTreeArr;

		parentPtr = nullptr;
		dCount = 0;
		sCount = 0;
		depth = 0;
	}

	/////////////////////////////////////////////////////////////////
	// Accessor and Mutator

	template<class T, int MIN>
	void bTNode<T, MIN>::setParentPtr(bTNode* _parentPtr)
	{
		parentPtr = _parentPtr;
	}

	template<class T, int MIN>
	void bTNode<T, MIN>::setDataCount(int _count)
	{
		dCount = (_count < 0) ? 0 : _count;

	}

	template<class T, int MIN>
	void bTNode<T, MIN>::setSubTreeCount(int _count)
	{
		sCount = (_count < 0) ? 0 : _count;
	}

	template<class T, int MIN>
	bTNode<T, MIN>* bTNode<T, MIN>::getParentPtr() const
	{
		return parentPtr;
	}

	template<class T, int MIN>
	bTNode<T, MIN>** bTNode<T, MIN>::getSubTree() const
	{
		return subTreeArr;
	}

	

	template<class T, int MIN>
	int bTNode<T, MIN>::getDataCount() const
	{
		return dCount;
	}

	template<class T, int MIN>
	int bTNode<T, MIN>::getSubTreeCount() const
	{
		return sCount;
	}

	/////////////////////////////////////////////////////////////////
	// Basic Function 

	template<class T, int MIN>
	void bTNode<T, MIN>::sort()
	{
		//1번과제에서 삽입정렬을 사용했으므로 3번 과제에서는 선택 정렬을 사용하였습니다.
		bool trigger = true;
		int min = 0; int minindex = 0;
		int index = 0;
		
		while (true)
		{
			min = dataArr[index];
			minindex = index;
			// index 번째부터 dCount -1 까지 최소를 탐색합니다.
			for (int i = index; i < dCount ; i++)
			{
				if (dataArr[i] < min)
				{
					min = dataArr[i];
					minindex = i;
				}
			}

			int temp = dataArr[minindex];
			dataArr[minindex] = dataArr[index];
			dataArr[index] = temp;

			if (index == dCount - 1) break;
			++index;
		}

	}
	 
#ifdef SetVersion
	template<class T, int MIN>
	int bTNode<T, MIN>::node_count(T _data) const
	{ // Bag Version

		int dataCount = 0;
		// add 1 to dataCount when _data is in dataArray
		for (int i = 0; i < dCount; i++)
		{
			if (dataArr[i] == _data) ++dataCount;
		}

		// add subTree's count of _data to dataCount 
		for (int i = 0; i < sCount; i++)
		{
			dataCount += subTreeArr[i]->node_count(_data);
		}


		return dataCount;
	}
#endif SetVersion   
	template<class T, int MIN>
	int bTNode<T, MIN>::node_count(T _data) const
	{ // Set Version

		// return 1 when _data is in dataArray
		for (int i = 0; i < dCount; i++)
		{
			if (dataArr[i] == _data) return 1;
		}

		// when subtree has _data, return 1
		for (int i = 0; i < sCount; i++)
		{
			if (subTreeArr[i]->node_count(_data) == 1) return 1;
		}

		// when there is no _data, return 0
		return 0;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::node_insert(T _data)
	{
		return false;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::node_erase_one(T _data)
	{
		return false;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::node_remove_biggest()
	{
		return false;
	}



	template<class T, int MIN>
	bool bTNode<T, MIN>::node_show_contents() const
	{
		return false;
	}


	template<class T, int MIN>
	bool bTNode<T, MIN>::loose_insert(T _data)
	{ // Set Version
		int index = 0;
		for (int i = 0; i <= dCount; i++)
		{
			if (dataArr[i] >= _data)
			{
				// Check for duplication
				if (dataArr[i] == _data) return false;
				index = i;
			}
			// if _data is biggest
			if (i == dCount)
			{
				index = dCount;
			}
		}

		if (sCount == 0)
		{ 
			//insert dataArr index th index - move each one to back
			for (int i = dCount; i > index; i--)
			{
				dataArr[i] = dataArr[i - 1];
			}
			dataArr[index] = _data;
			return true;
		}

		// Recursive Call
		bool b = subTreeArr[index]->loose_insert(_data);
		if (subTreeArr[index]->getDataCount() > MAX)
		{
			subTreeArr[index]->fix_excess();
		}


		return b;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::loose_erase_one(T _data)
	{
		return false;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::fix_shortage()
	{
		return false;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::fix_excess()
	{
		// when dataArr is excess, it must be leaf and 2 * MIN + 1 count of data
		
		bTNode<T, MIN>* leftNode = new bTNode<T, MIN>(); leftNode->depth = depth + 1; leftNode->setParentPtr(this);
		bTNode<T, MIN>* rightNode = new bTNode<T, MIN>(); rightNode->depth = depth + 1; rightNode->setParentPtr(this);

		for (int i = 0; i < MIN; i++)
		{

		}


		// if root == leaf, pick middle node and middle node be new root node
		if (parentPtr == nullptr)
		{
			
		}
		else
		{

		}
		// if root != leaf, pick middle node and middle node move upward to parent.

		return false;
	}



	/////////////////////////////////////////////////////////////////
	// Operator Overloading

	template<class T, int MIN>
	T& bTNode<T, MIN>::operator[](int _index)
	{
		if (_index > dCount && _index < 0)
		{
			std::cout << "ERROR : Index Out Of Range. \n";
		}
		return dataArr[_index];
	}

	template<class T, int MIN>
	T& bTNode<T, MIN>::operator[](int _index) const
	{
		if (_index > dCount && _index < 0)
		{
			std::cout << "ERROR : Index Out Of Range. \n";
		}
		return dataArr[_index];
	}

	template<class T, int MIN>
	bTNode<T, MIN>& bTNode<T, MIN>::operator=(const bTNode& _node)
	{
		// Check Self-assignment
		if (this == &_node) { return *this; }

		parentPtr = _node.getParentPtr();
		depth = _node.depth;
		sCount = _node.getSubTreeCount();
		dCount = _node.getDataCount();

		//data copy
		for (int i = 0; i < dCount; i++)
		{
			dataArr[i] = _node.operator[](i);
		}
		//subtree deepcopy
		for (int i = 0; i < sCount; i++)
		{
			delete subTreeArr[i];
			subTreeArr[i] = new bTNode<T, MIN>();
			*(subTreeArr[i]) = *(_node.getSubTree()[i]);
		}
		return *this;

	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::operator<(T _data)
	{
		for (int i = 0; i < dCount; i++)
		{
			if (dataArr[i] >= _data) return false;
		}
		for (int i = 0; i < sCount; i++)
		{
			if ((*subTreeArr[i] < _data) == false) return false;
		}

		return true;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::operator>(T _data)
	{
		for (int i = 0; i < dCount; i++)
		{
			if (dataArr[i] <= _data) return false;
		}
		for (int i = 0; i < sCount; i++)
		{
			if ((*subTreeArr[i] > _data) == false) return false;
		}
		return true;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::operator<=(T _data)
	{
		for (int i = 0; i < dCount; i++)
		{
			if (dataArr[i] > _data) return false;
		}
		for (int i = 0; i < sCount; i++)
		{
			if ((*subTreeArr[i] <= _data) == false) return false;
		}

		return true;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::operator>=(T _data)
	{
		for (int i = 0; i < dCount; i++)
		{
			if (dataArr[i] < _data) return false;
		}
		for (int i = 0; i < sCount; i++)
		{
			if ((*subTreeArr[i] >= _data) == false) return false;
		}

		return true;
	}

	template<class T, int MIN>
	void bTNode<T, MIN>::operator++(int)
	{
		depth++;
		for (int i = 0; i < sCount; i++)
		{
			(*subTreeArr[i])++;
		}
	}	
	template<class T, int MIN>
	void bTNode<T, MIN>::operator--(int)
	{
		depth--;
		for (int i = 0; i < sCount; i++)
		{
			(*subTreeArr[i])--;
		}
	}


#pragma endregion bTNodeFunction
}

#endif // !__BTREENODE__
