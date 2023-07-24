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
		// 특정 인덱스에 삽입  - 정상 종료 0 오류 -1
		int insert(T _data , int _index);
		// 특정 인덱스 값을 삭제 - 정상 종료 0 오류 -1
		int deleteat(int _index);
		//특정 값을 삭제 - 정상 종료 index 값 오류 -1
		int deleteof(T _data);
		//특정 값을 검색 - 정상 종료 index 값 오류 -1
		int find(T _data);

		// 접근, 변형자
		int getCount();
		void setCount(int _iCount);
		int getMax();
		void setMax(int _iMax);
		// 디버깅용
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
		// 접근자 변형자
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
		//특정 인덱스 값
		T operator[](int _index);

		//앞에 추가
		void pushFront(T _data);
		//뒤에 추가
		void pushBack(T _data);
		//중간에 추가 // 오류 -1 정상 0
		int insert(T _data, int _index);
		//찾기 // 오류 -1 정상 0
		int find(T _data);
		//찾아서 지우기  // 오류 -1 정상 0
		int deleteOf(T _data);
		//인덱스 삭제 // 오류 -1 정상 0
		int deleteAt(int _index);
		//개수 반환 
		int getCount();

		//디버깅 용
		void showInfo();
	};

}
#endif // !__DATATYPE__
