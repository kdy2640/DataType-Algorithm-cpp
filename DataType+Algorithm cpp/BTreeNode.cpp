
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
		bTNode(bTNode* _rootPtr = nullptr);
		bTNode(const bTNode& _Node);
		~bTNode();

		//Accessor and Mutator - there is no mutator of subTreeArr & dataArr for improving safety
		void setRootPtr(bTNode* _rootPtr);
		void setDataCount(int _count);
		void setSubTreeCount(int _count);

		bTNode* getRootPtr() const;
		int getDataCount() const;
		int getSubTreCount() const;

		// return Ptr of SubTreePtr's array
		bTNode** getSubTree()  const;  


		//BasicFunction
		//return false when dataArray is full. return true when add successfully
		bool addData(T _data); 

		// return false when there is no _data in dataArray. return true when delete successfully
		bool deleteData(T _data); 

		// return -1 when there is no _data in dataArray. return index when there is _data in dataArray
		int findData(T _data) const;

		// return true when dataArray is empty;
		bool isEmpty() const;

		//Operator Overloading
		T operator[](int _index);   // random access to data array
		bTNode& operator = (const bTNode& _Node);

	private:

		void sort(); // dataArray must be sorted

		bTNode* rootPtr;
		bTNode** subTreeArr;
		T* dataArr;
		int dCount;
		int sCount;
	};

#pragma region bTNodeFunction

	/////////////////////////////////////////////////////////////////
	// Constructor and Destructor


	template<class T, int MIN>
	bTNode<T, MIN>::bTNode(bTNode* _rootPtr)
	{
		rootPtr = _rootPtr;
		dataArr = new T[MAX + 1];
		subTreeArr = new bTNode * [MAX + 1];
		dCount = 0; sCount = 0;
	}

	template<class T, int MIN>
	bTNode<T, MIN>::bTNode(const bTNode& _Node)
	{
		rootPtr = _Node.rootPtr;
		dCount = _Node.dCount;
		sCount = _Node.sCount;
		dataArr = new T[MAX + 1];
		subTreeArr = new bTNode * [MAX + 1];

		//dataArr deep copy
		for (int i = 0; i < dCount; i++)
		{
			dataArr[i] = _Node[i];
		}

		//subTreeArr deep copy
		for (int i = 0; i < sCount; i++)
		{
			subTreeArr[i] = new bTNode(*_Node.subTreeArr[i]);
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

		rootPtr = nullptr;
		dCount = 0;
		sCount = 0;
	}

	/////////////////////////////////////////////////////////////////
	// Accessor and Mutator

	template<class T, int MIN>
	void bTNode<T, MIN>::setRootPtr(bTNode* _rootPtr)
	{
		rootPtr = _rootPtr;
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
	bTNode<T, MIN>* bTNode<T, MIN>::getRootPtr() const
	{
		return rootPtr;
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
	int bTNode<T, MIN>::getSubTreCount() const
	{
		return sCount;
	}

	/////////////////////////////////////////////////////////////////
	// Basic Function
	// doesn't care about Rule of BTree 

	//return false when dataArray is full.
	template<class T, int MIN>
	bool bTNode<T, MIN>::addData(T _data)
	{
		if (dCount == MAX)
		{
			std::cout << "ERROR : BTreeNode's DataArray is Full." << std::endl;
			return false;
		}

		dataArr[dCount++] = _data;
		sort();
		return true;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::deleteData(T _data)
	{
		bool found = false;
		for (int i = 0; i < dCount; i++)
		{
			if (dataArr[i] == _data)
			{
				found = true;
				dataArr[i] = dataArr[dCount--];
				sort();
				break;
			}
		}

		return found;
	}

	template<class T, int MIN>
	int bTNode<T, MIN>::findData(T _data) const
	{
		int index = -1;
		for (int i = 0; i < dCount; i++)
		{
			if (dataArr[i] == _data)
			{
				index = i;
				break;
			}
		}

		return index;
	}

	template<class T, int MIN>
	bool bTNode<T, MIN>::isEmpty() const
	{
		return (dCount == 0) ? true : false;
	}

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



#pragma endregion bTNodeFunction
}

#endif // !__BTREENODE__
