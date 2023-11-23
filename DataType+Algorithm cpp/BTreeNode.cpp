
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
		bTNode(const bTNode& _Node);
		~bTNode();

		//Accessor and Mutator - there is no mutator of subTreeArr & dataArr for improving safety
		void setRootPtr(bTNode* _parentPtr);
		void setDataCount(int _count);
		void setSubTreeCount(int _count);

		bTNode* getRootPtr() const;
		int getDataCount() const;
		int getSubTreCount() const;

		// return Ptr of SubTreePtr's array
		bTNode** getSubTree()  const;  


		// BasicFunction
		
		// return 0 if not founded. return 1 if founded 
		int node_count(T _data) const;
		//
		bool node_insert(T _data);
		//
		bool node_erase_one(T _data);
		//
		bool node_remove_biggest();
		//
		bool node_show_contents() const;
		//
		bool node_remove_biggest();


		//Operator Overloading
		T operator[](int _index);   // random access to data array
		bTNode& operator = (const bTNode& _Node);
		
		// these operator intend to check dataArr and subtree's data for _data
		bool operator < (T _data);
		bool operator > (T _data);

		bool operator <= (T _data);
		bool operator >= (T _data);
		 
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
	bTNode<T, MIN>::bTNode(const bTNode& _Node)
	{
		parentPtr = _Node.parentPtr;
		dCount = _Node.dCount;
		sCount = _Node.sCount;
		depth = _Node.depth;
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

		parentPtr = nullptr;
		dCount = 0;
		sCount = 0;
		depth = 0;
	}

	/////////////////////////////////////////////////////////////////
	// Accessor and Mutator

	template<class T, int MIN>
	void bTNode<T, MIN>::setRootPtr(bTNode* _parentPtr)
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
	bTNode<T, MIN>* bTNode<T, MIN>::getRootPtr() const
	{
		return parentPtr;
	}

	template<class T, int MIN>
	bTNode<T, MIN>** bTNode<T, MIN>::getSubTree() const
	{
		return subTreeArr;
	}

	template<class T, int MIN>
	int bTNode<T, MIN>::node_count(T _data) const
	{
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

	template<class T, int MIN>
	bool bTNode<T, MIN>::loose_insert(T _data)
	{
		return false;
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
		return false;
	}



	/////////////////////////////////////////////////////////////////
	// Operator Overloading

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


#pragma endregion bTNodeFunction
}

#endif // !__BTREENODE__
