
#ifndef __BTREENODE__
#define __BTREENODE__

// MIN is bTree's minimal  
// Node which is intended to store int/float/double data
template <class T,int MIN>
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

	bTNode* getRootPtr(); 
	bTNode** getSubTree();  // return Ptr of SubTreePtr's array
	int getDataCount(); 
	int getSubTreCount();

	//BasicFunction
	void addData(T _data);
	bool deleteData(T _data);
	int findData(T _data);
	bool empty();

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
 

template<class T, int MIN>
bTNode<T, MIN>::bTNode(bTNode* _rootPtr)
{
}

template<class T, int MIN>
bTNode<T, MIN>::bTNode(const bTNode& _Node)
{

}

template<class T, int MIN>
bTNode<T, MIN>::~bTNode()
{
}

template<class T, int MIN>
void bTNode<T, MIN>::setRootPtr(bTNode* _rootPtr)
{
}

template<class T, int MIN>
void bTNode<T, MIN>::setDataCount(int _count)
{
}

template<class T, int MIN>
void bTNode<T, MIN>::setSubTreeCount(int _count)
{
}

template<class T, int MIN>
bTNode<T, MIN>* bTNode<T, MIN>::getRootPtr()
{ 
}

template<class T, int MIN>
bTNode<T, MIN>** bTNode<T, MIN>::getSubTree()
{ 
}

template<class T, int MIN>
int bTNode<T, MIN>::getDataCount()
{
	return 0;
}

template<class T, int MIN>
int bTNode<T, MIN>::getSubTreCount()
{
	return 0;
}

template<class T, int MIN>
void bTNode<T, MIN>::addData(T _data)
{
}

template<class T, int MIN>
bool bTNode<T, MIN>::deleteData(T _data)
{
	return false;
}

template<class T, int MIN>
int bTNode<T, MIN>::findData(T _data)
{
	return 0;
}

template<class T, int MIN>
bool bTNode<T, MIN>::empty()
{
	return false;
}



#pragma endregion bTNodeFunction


#endif // !__BTREENODE__