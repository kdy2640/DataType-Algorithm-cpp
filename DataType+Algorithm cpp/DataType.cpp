#include "Datatype.h"
#include<iostream>
using std::left;
using std::cout;
using std::endl;
namespace DataType
{
	template<class T>
	DynamicArray<T>::DynamicArray(int _max)
		: dArr(nullptr), iCount(0), iMax(_max)
	{
		if (_max < 5) {
			std::cout << "ERROR : 크기가 5 보다 작을 수 없습니다." << std::endl;
		}
		dArr = new T[_max];
	}
	template<class T>
	DynamicArray<T>::DynamicArray(const T* _Arr, int _size)
	{
		dArr = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			dArr[i] = _Arr[i];
		}
		iCount = _size;
		iMax = _size;

	}
	template<class T>
	DynamicArray<T>::DynamicArray(const DynamicArray& _dArr)
	{
		dArr = new T[_dArr.iMax];
		for (int i = 0; i < _dArr.iMax; i++)
		{
			dArr[i] = _dArr[i];
		}
		iCount = _dArr.iCount;
		iMax = _dArr.iMax;

	}
	template<class T>
	DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& _dArr)
	{
		free(dArr);
		dArr = new T[_dArr.iMax];
		for (int i = 0; i < _dArr.iMax; i++)
		{
			dArr[i] = _dArr[i];
		}
		iCount = _dArr.iCount;
		iMax = _dArr.iMax;
		return *this;
	}
	template<class T>
	T& DynamicArray<T>::operator[](int _index) const
	{
		return dArr[_index];
	}
	template<class T>
	T& DynamicArray<T>::operator[](int _index)
	{
		return dArr[_index];
	}
	template<class T>
	DynamicArray<T>::~DynamicArray()
	{
		delete[] dArr;
	}

	template<class T>
	void DynamicArray<T>::pushBack(T _data)
	{
		//빈 공간 확인
		if (iCount >= iMax)
		{
			resize();
		}

		dArr[iCount++] = _data;
	}
	template<class T>
	int DynamicArray<T>::insert(T _data, int _index)
	{
		//인덱스 유효성 검사
		if (_index > iCount || _index < 0)
		{
			std::cout << "ERROR : Index Out Of Range. \n";
			return -1;
		}
		//빈 공간 확인
		if (iCount > iMax)
		{
			resize();
		}

		//뒤에서부터 한 칸씩 옮기다가
		//_index번쨰에서 _data 넣기
		int tempIndex = 0;
		for (int i = 0; i < iCount; i++)
		{
			tempIndex = iCount - i;
			dArr[tempIndex + 1] = dArr[tempIndex];
			if (tempIndex == _index)
			{
				dArr[tempIndex] = _data;
				break;
			}
		}
		iCount++;
		return 0;


	}
	template<class T>
	void DynamicArray<T>::resize()
	{
		T* temp = new T[iMax * 2];
		for (int i = 0; i < iCount; i++)
		{
			temp[i] = dArr[i];
		}
		delete[] dArr;
		dArr = temp;
		iMax *= 2;
	}
	template<class T>
	int DynamicArray<T>::deleteat(int _index)
	{
		//인덱스 유효성 검사
		if (_index >= iCount || _index < 0)
		{
			std::cout << "ERROR : Index Out Of Range. \n";
			return -1;
		}
		//_index번쨰부터 _index+1 번쨰 데이터를 가져옴
		for (int i = _index; i < iCount - 1; i++)
		{
			dArr[i] = dArr[i + 1];
		}
		dArr[iCount - 1] = -1;
		iCount--;
		return 0;
	}
	template<class T>
	int DynamicArray<T>::deleteof(T _data)
	{
		int temp = find(_data);
		if (temp == -1) return -1;
		deleteat(temp);
		return 0;
	}
	template<class T>
	int DynamicArray<T>::find(T _data)
	{
		// 데이터가 있는지 확인
		for (int i = 0; i < iCount; i++)
		{
			if (dArr[i] == _data) return i;
		}
		//없음
		return -1;
	}

	template<class T>
	int DynamicArray<T>::getCount()
	{
		return iCount;
	}
	template<class T>
	void DynamicArray<T>::setCount(int _iCount)
	{
		iCount = _iCount;
	}
	template<class T>
	int DynamicArray<T>::getMax()
	{
		return iMax;
	}
	template<class T>
	void DynamicArray<T>::setMax(int _iMax)
	{
		iMax = _iMax;
	}
	template<class T>
	void DynamicArray<T>::showInfo()
	{
		cout << "------------------------------------------------" << endl;
		for (int i = 0; i < iMax; i++)
		{
			cout.width(3);
			cout << i;
		}
		cout << "" << endl;
		for (int i = 0; i < iMax; i++)
		{
			cout.width(3);
			if (dArr[i] < 0) cout << -1;
			else
			{
				cout << dArr[i];
			}
		}
		cout << "" << endl;

		cout << " iCount 는 " << iCount << " iMax 는 " << iMax << endl;
		cout << "------------------------------------------------" << endl;

	}

	//////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	iNode<T>::iNode() :data(0), nextPtr(nullptr), prevPtr(nullptr) {}
	template<class T>
	iNode<T>::iNode(T _data, iNode<T>* _prevPtr, iNode<T>* _nextPtr) : data(_data), nextPtr(_nextPtr), prevPtr(_prevPtr) {}
	template<class T>
	iNode<T>::~iNode() { nextPtr = 0; prevPtr = 0; }

	// 접근자 변형자
	template<class T>
	void iNode<T>::setData(T _data) { data = _data; }
	template<class T>
	T iNode<T>::getData() { return data; }
	template<class T>
	void iNode<T>::setNextPtr(iNode<T>* _nextPtr) { nextPtr = _nextPtr; }
	template<class T>
	iNode<T>* iNode<T>::getNextPtr() { return nextPtr; }
	template<class T>
	void iNode<T>::setPrevPtr(iNode<T>* prevPtr) { prevPtr = prevPtr; }
	template<class T>
	iNode<T>* iNode<T>::getPrevPtr() { return prevPtr; }



	//특정 인덱스 값
	template<class T>
	T LinkedList<T>::operator[](int _index)
	{
		if (_index == 0)
		{
			return head->getData();
		}
		iNode<T>* temp = head;
		for (int i = 0; i < _index; i++)
		{
			temp = temp->getNextPtr();
		}
		return temp->getData();
	}

	template<class T>
	LinkedList<T>::~LinkedList()
	{

	}
	//앞에 추가
	template<class T>
	void LinkedList<T>::pushFront(T _data)
	{
		insert(_data, 0);
	}
	//뒤에 추가
	template<class T>
	void LinkedList<T>::pushBack(T _data)
	{
		insert(_data, count);
	}

	//중간에 추가 // 오류 -1 정상 0
	template<class T>
	int LinkedList<T>::insert(T _data, int _index)
	{
		//인덱스 유효성 검사
		if (count < _index || _index < 0)
		{
			cout << "ERROR : Index Out Of Range. \n";
			return -1;
		}
		iNode<T>* temp;
		//아무것도 없을 때
		if (count == 0)
		{
			temp = new iNode<T>(_data, nullptr, nullptr);
			head = temp; tail = temp;
		}
		else
		{
			//맨 앞에
			if (_index == 0)
			{
				//이전은 null 다음은 head를 가리키는 노드를 생성
				temp = new iNode<T>(_data, nullptr, head);
				//head 의 이전노드가 temp를 가리키게 수정
				head->setPrevPtr(temp);
				//head가 temp를 가리키게 수정
				head = temp;
			}
			//맨 뒤에
			else if (count == _index)
			{
				//이전은 tail 다음은 null을 가리키는 노드를 생성
				temp = new iNode<T>(_data, tail, nullptr);
				//tail의 다음 노드가 temp를 가리키게 수정
				tail->setNextPtr(temp);
				//tail이 temp를 가리키게 수정
				tail = temp;
			}
			//중간에 
			else
			{   //index번쨰는 최소 1이상 Count 미만
				//앞에서 순회하는게 빠를 떄
				if (count / 2 > _index)
				{
					temp = head;
					for (int i = 1; i < _index; i++)
					{
						temp = temp->getNextPtr();
					}

				}
				//뒤에서 순회하는 게 빠를 때
				else
				{
					temp = tail;
					int tlen = count - _index;
					for (int i = 0; i < tlen; i++)
					{
						temp = temp->getPrevPtr();
					}
				}
				//temp는 index-1번째를 가리키고 있어야함

				//temp를 이전으로 index번쨰를 다음으로 하는 노드 생성
				temp = new iNode<T>(_data, temp, temp->getNextPtr());
				//index 번쨰 노드의 이전을 temp로 수정
				temp->getNextPtr()->setPrevPtr(temp);
				//index-1 번째 노드의 다음을 temp로 수정
				temp->getPrevPtr()->setNextPtr(temp);
			}
		}

		count++;
		return 0;


	}

	//찾기 // 오류 -1 정상 찾는 값의 index;
	template<class T>
	int LinkedList<T>::find(T _data)
	{
		iNode<T>* temp = head;
		int index = 0;
		while (temp != nullptr)
		{
			if (temp->getData() == _data) return index;
			index++;
			temp = temp->getNextPtr();
		}
		return -1;
	}

	//찾아서 지우기  // 오류 -1 정상 0
	template<class T>
	int LinkedList<T>::deleteOf(T _data)
	{
		int sign = find(_data);
		if (sign == -1) return -1;
		deleteAt(sign);
		return 0;
	}
	//인덱스 삭제 // 오류 -1 정상 0
	template<class T>
	int LinkedList<T>::deleteAt(int _index)
	{
		//인덱스 유효성 검사
		if (count <= _index || _index < 0)
		{
			cout << "ERROR : Index Out Of Range. \n";
			return -1;
		}
		iNode<T>* temp;

		//맨 앞에
		if (_index == 0)
		{
			temp = head;
			//head 의 이전노드가 null을 가리키게 수정
			head->setPrevPtr(nullptr);
			//head가 기존 head 다음을 가리키게 수정
			head = head->getNextPtr();
			free(temp);
		}
		//맨 뒤에
		else if (count == _index)
		{
			temp = tail;
			//tail의 다음 노드가 null를 가리키게 수정
			tail->setNextPtr(nullptr);
			//tail이 기존 tail 이전을 가리키게 수정
			tail = tail->getPrevPtr();
			free(temp);
		}

		else
		{   //index번쨰는 최소 1이상 Count 미만
			//앞에서 순회하는게 빠를 떄
			if (count / 2 > _index)
			{
				temp = head;
				for (int i = 1; i < _index; i++)
				{
					temp = temp->getNextPtr();
				}

			}
			//뒤에서 순회하는 게 빠를 때
			else
			{
				temp = tail;
				int tlen = count - _index;
				for (int i = 0; i < tlen; i++)
				{
					temp = temp->getPrevPtr();
				}
			}
			//temp는 index-1번째를 가리키고 있어야함
			

			//index+1 번쨰 노드의 이전을 temp의 이전으로 수정
			temp->getNextPtr()->getNextPtr()->setPrevPtr(temp->getPrevPtr());
			//index-1 번째 노드의 다음을 temp의 다음으로 수정
			temp->setNextPtr(temp->getNextPtr()->getNextPtr());

		}
		count--;
		return 0;
	}

	//개수 반환 
	template<class T>
	int LinkedList<T>::getCount() {
		return count;
	}
	//디버깅용
	template<class T>
	void LinkedList<T>::showInfo()
	{
			cout << "------------------------------------------------" << endl;
			for (int i = 0; i < count; i++)
			{
				cout.width(3);
				cout << i;
			}
			cout << "" << endl;
			for (int i = 0; i < count; i++)
			{
				cout.width(3);
				cout << operator[](i);
			}
			cout << "" << endl;

			cout <<" count 는 " << count << endl;
			cout << "------------------------------------------------" << endl;

	}
}