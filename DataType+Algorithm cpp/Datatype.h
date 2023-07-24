#ifndef __DATATYPE__
#define __DATATYPE__

namespace DataType
{
	template<class T>
	class DynamicArray
	{
	private:
		T* dArr;
		int iCount;
		int iMax;

		void resize();

	public:
		DynamicArray(int iMax = 10);
		DynamicArray(const T* _Arr, int _size);
		DynamicArray(const DynamicArray& _dArr);
		DynamicArray& operator= (const DynamicArray& _dArr);
		T& operator[](int _index) const;
		T& operator[](int _index);
		~DynamicArray();

		void pushBack(T _data);
		// Ư�� �ε����� ����  - ���� ���� 0 ���� -1
		int insert(T _data , int _index);
		// Ư�� �ε��� ���� ���� - ���� ���� 0 ���� -1
		int deleteat(int _index);
		//Ư�� ���� ���� - ���� ���� index �� ���� -1
		int deleteof(T _data);
		//Ư�� ���� �˻� - ���� ���� index �� ���� -1
		int find(T _data);

		// ����, ������
		int getCount();
		void setCount(int _iCount);
		int getMax();
		void setMax(int _iMax);
		// ������
		void showInfo();
	};

	template<class T>
	class iNode
	{
	private:
		T data;
		iNode<T>* nextPtr;
		iNode<T>* prevPtr;
	public:
		iNode();
		iNode(T _data, iNode<T>* _prevPtr, iNode<T>* _nextPtr);
		~iNode();
		// ������ ������
		void setData(T _data);
		T getData();
		void setNextPtr(iNode<T>* _nextPtr);
		iNode<T>* getNextPtr();
		void setPrevPtr(iNode<T>* prevPtr);
		iNode<T>* getPrevPtr();
	};
	template<class T>
	class LinkedList 
	{
	private:
		int count;
		iNode<T>* head;
		iNode<T>* tail;
	public:
		LinkedList() :count(0), head(nullptr), tail(nullptr){}
		~LinkedList();
		//Ư�� �ε��� ��
		T operator[](int _index);

		//�տ� �߰�
		void pushFront(T _data);
		//�ڿ� �߰�
		void pushBack(T _data);
		//�߰��� �߰� // ���� -1 ���� 0
		int insert(T _data, int _index);
		//ã�� // ���� -1 ���� 0
		int find(T _data);
		//ã�Ƽ� �����  // ���� -1 ���� 0
		int deleteOf(T _data);
		//�ε��� ���� // ���� -1 ���� 0
		int deleteAt(int _index);
		//���� ��ȯ 
		int getCount();

		//����� ��
		void showInfo();
	};

}
#endif // !__DATATYPE__
