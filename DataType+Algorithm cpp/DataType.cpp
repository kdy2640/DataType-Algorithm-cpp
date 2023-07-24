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
			std::cout << "ERROR : ũ�Ⱑ 5 ���� ���� �� �����ϴ�." << std::endl;
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
		//�� ���� Ȯ��
		if (iCount >= iMax)
		{
			resize();
		}

		dArr[iCount++] = _data;
	}
	template<class T>
	int DynamicArray<T>::insert(T _data, int _index)
	{
		//�ε��� ��ȿ�� �˻�
		if (_index > iCount || _index < 0)
		{
			std::cout << "ERROR : Index Out Of Range. \n";
			return -1;
		}
		//�� ���� Ȯ��
		if (iCount > iMax)
		{
			resize();
		}

		//�ڿ������� �� ĭ�� �ű�ٰ�
		//_index�������� _data �ֱ�
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
		//�ε��� ��ȿ�� �˻�
		if (_index >= iCount || _index < 0)
		{
			std::cout << "ERROR : Index Out Of Range. \n";
			return -1;
		}
		//_index�������� _index+1 ���� �����͸� ������
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
		// �����Ͱ� �ִ��� Ȯ��
		for (int i = 0; i < iCount; i++)
		{
			if (dArr[i] == _data) return i;
		}
		//����
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

		cout << " iCount �� " << iCount << " iMax �� " << iMax << endl;
		cout << "------------------------------------------------" << endl;

	}

	//////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	iNode<T>::iNode() :data(0), nextPtr(nullptr), prevPtr(nullptr) {}
	template<class T>
	iNode<T>::iNode(T _data, iNode<T>* _prevPtr, iNode<T>* _nextPtr) : data(_data), nextPtr(_nextPtr), prevPtr(_prevPtr) {}
	template<class T>
	iNode<T>::~iNode() { nextPtr = 0; prevPtr = 0; }

	// ������ ������
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



	//Ư�� �ε��� ��
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
	//�տ� �߰�
	template<class T>
	void LinkedList<T>::pushFront(T _data)
	{
		insert(_data, 0);
	}
	//�ڿ� �߰�
	template<class T>
	void LinkedList<T>::pushBack(T _data)
	{
		insert(_data, count);
	}

	//�߰��� �߰� // ���� -1 ���� 0
	template<class T>
	int LinkedList<T>::insert(T _data, int _index)
	{
		//�ε��� ��ȿ�� �˻�
		if (count < _index || _index < 0)
		{
			cout << "ERROR : Index Out Of Range. \n";
			return -1;
		}
		iNode<T>* temp;
		//�ƹ��͵� ���� ��
		if (count == 0)
		{
			temp = new iNode<T>(_data, nullptr, nullptr);
			head = temp; tail = temp;
		}
		else
		{
			//�� �տ�
			if (_index == 0)
			{
				//������ null ������ head�� ����Ű�� ��带 ����
				temp = new iNode<T>(_data, nullptr, head);
				//head �� ������尡 temp�� ����Ű�� ����
				head->setPrevPtr(temp);
				//head�� temp�� ����Ű�� ����
				head = temp;
			}
			//�� �ڿ�
			else if (count == _index)
			{
				//������ tail ������ null�� ����Ű�� ��带 ����
				temp = new iNode<T>(_data, tail, nullptr);
				//tail�� ���� ��尡 temp�� ����Ű�� ����
				tail->setNextPtr(temp);
				//tail�� temp�� ����Ű�� ����
				tail = temp;
			}
			//�߰��� 
			else
			{   //index������ �ּ� 1�̻� Count �̸�
				//�տ��� ��ȸ�ϴ°� ���� ��
				if (count / 2 > _index)
				{
					temp = head;
					for (int i = 1; i < _index; i++)
					{
						temp = temp->getNextPtr();
					}

				}
				//�ڿ��� ��ȸ�ϴ� �� ���� ��
				else
				{
					temp = tail;
					int tlen = count - _index;
					for (int i = 0; i < tlen; i++)
					{
						temp = temp->getPrevPtr();
					}
				}
				//temp�� index-1��°�� ����Ű�� �־����

				//temp�� �������� index������ �������� �ϴ� ��� ����
				temp = new iNode<T>(_data, temp, temp->getNextPtr());
				//index ���� ����� ������ temp�� ����
				temp->getNextPtr()->setPrevPtr(temp);
				//index-1 ��° ����� ������ temp�� ����
				temp->getPrevPtr()->setNextPtr(temp);
			}
		}

		count++;
		return 0;


	}

	//ã�� // ���� -1 ���� ã�� ���� index;
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

	//ã�Ƽ� �����  // ���� -1 ���� 0
	template<class T>
	int LinkedList<T>::deleteOf(T _data)
	{
		int sign = find(_data);
		if (sign == -1) return -1;
		deleteAt(sign);
		return 0;
	}
	//�ε��� ���� // ���� -1 ���� 0
	template<class T>
	int LinkedList<T>::deleteAt(int _index)
	{
		//�ε��� ��ȿ�� �˻�
		if (count <= _index || _index < 0)
		{
			cout << "ERROR : Index Out Of Range. \n";
			return -1;
		}
		iNode<T>* temp;

		//�� �տ�
		if (_index == 0)
		{
			temp = head;
			//head �� ������尡 null�� ����Ű�� ����
			head->setPrevPtr(nullptr);
			//head�� ���� head ������ ����Ű�� ����
			head = head->getNextPtr();
			free(temp);
		}
		//�� �ڿ�
		else if (count == _index)
		{
			temp = tail;
			//tail�� ���� ��尡 null�� ����Ű�� ����
			tail->setNextPtr(nullptr);
			//tail�� ���� tail ������ ����Ű�� ����
			tail = tail->getPrevPtr();
			free(temp);
		}

		else
		{   //index������ �ּ� 1�̻� Count �̸�
			//�տ��� ��ȸ�ϴ°� ���� ��
			if (count / 2 > _index)
			{
				temp = head;
				for (int i = 1; i < _index; i++)
				{
					temp = temp->getNextPtr();
				}

			}
			//�ڿ��� ��ȸ�ϴ� �� ���� ��
			else
			{
				temp = tail;
				int tlen = count - _index;
				for (int i = 0; i < tlen; i++)
				{
					temp = temp->getPrevPtr();
				}
			}
			//temp�� index-1��°�� ����Ű�� �־����
			

			//index+1 ���� ����� ������ temp�� �������� ����
			temp->getNextPtr()->getNextPtr()->setPrevPtr(temp->getPrevPtr());
			//index-1 ��° ����� ������ temp�� �������� ����
			temp->setNextPtr(temp->getNextPtr()->getNextPtr());

		}
		count--;
		return 0;
	}

	//���� ��ȯ 
	template<class T>
	int LinkedList<T>::getCount() {
		return count;
	}
	//������
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

			cout <<" count �� " << count << endl;
			cout << "------------------------------------------------" << endl;

	}
}