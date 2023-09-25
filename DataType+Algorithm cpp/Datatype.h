#ifndef __DATATYPE__
#define __DATATYPE__
#include<assert.h>
#include<iostream>
using namespace std;

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
		//
		class iterator;
		iterator begin();
		iterator end();

		class iterator
		{
		public:
			T* pDArr;           //������ ������ �ּ�
			DynamicArray* pArr; // �����迭�� �ּ�
			int index;          // �������� �ε���
		public:
			iterator() : pArr(nullptr), pDArr(nullptr), index(0)
			{
				
			}
			iterator(DynamicArray* _pArr, T* _pDArr, int _index)
			{
				pArr = _pArr;
				pDArr = _pDArr;
				index = _index;
			}
			~iterator()
			{

			}

			T& operator *()
			{
				//iterator �� �˰��ִ� �ּҶ� ������ Ȯ��
				if (pDArr != pArr->dArr || -1 == index) {
					assert(nullptr);
				}
				return pDArr[index];
			}
			//���� ++
			iterator& operator ++()
			{

				//2. end ���ͷ������� ���
				//3. �ּҰ� �ٸ� ���
				if (pDArr != pArr->dArr || -1 == index) {
					assert(nullptr);
				}

				//1.������ �������� ��� 0 ������ �ƴ�
				if (index == iCount - 1)
				{
					index = -1;
				}
				else
				{
					index++;
				}

				return *this;
			}
			//���� ++
			iterator operator ++(int)
			{
				iterator copy = *this;
				
				++(*this);

				return copy;
			}
			//���� --
			iterator& operator --()
			{
				return *this;
			}
			//���� --
			iterator& operator --(int)
			{
				return *this;
			}
			bool operator ==(const iterator& _iter)
			{
				if (pDArr == _iter.pDArr && index == _iter.index)
				{
					return true;
				}
				return false;
			}
			bool operator !=(const iterator& _iter)
			{
				if (pDArr == _iter.pDArr && index == _iter.index)
				{
					return false;
				}
				return true;
				//return !(*this == _iter);
			}
		};
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

	enum class NODE_TYPE
	{
		PARENT,
		LCHILD,
		RCHILD,
		END
	};
	template<class T1,class T2>
	class tPair
	{
	public:
		tPair() : first(), second()
		{}
		tPair(const T1 _first, const T2 _second) : first(_first), second(_second)
		{}
		T1 first;
		T2 second;
	};

	template<class T1, class T2>
	tPair<T1, T2> make_tPair(const T1& _first, const T2& _second)
	{
		return tPair<T1, T2>{_first, _second};
	} 
	
	template<class T1, class T2>
	class tNode
	{
	public:
		//�ڽ��� ������
		tPair<T1,T2> pair;
		//�α� ����� ������
		tNode* arrNode[(int)NODE_TYPE::END];
		
		tNode() : pair(),arrNode()
		{}
		tNode(const tPair<T1,T2>& _pair, tNode* _parent, tNode* _LChild, tNode* _RChild) : pair(_pair) , arrNode{_parent,_LChild,_RChild}
		{}
		bool isRoot()
		{
			if (this->arrNode[(int)NODE_TYPE::PARENT] == nullptr) return true;
			return false;
		}
		bool isLeftChild()
		{
			if (this == this->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD]) {
				return true;
			}
			return false;
		}		
		bool isRightChild()
		{
			if (this == this->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD]) {
				return true;
			}
			return false;
		}
		bool isLeaf()
		{
			if (arrNode[(int)NODE_TYPE::LCHILD] == nullptr && arrNode[(int)NODE_TYPE::RCHILD] == nullptr)
			{
				return true;
			}
			return false;
		}
		bool isFull()
		{
			if (arrNode[(int)NODE_TYPE::LCHILD] != nullptr && arrNode[(int)NODE_TYPE::RCHILD] != nullptr)
			{
				return true;
			}
			return false;
		}
	}; 
	//T1�� key, T2�� value
	template<class T1, class T2>
	class CBST
	{
	private:
		tNode<T1, T2>* root;
		int count;
		tNode<T1, T2>* deleteNode(tNode<T1,T2>* _pTargetNode)
		{
			tNode<T1, T2>* pSuccessor = getInOrderSuccessor(_pTargetNode);
			tNode<T1, T2>* temp = _pTargetNode;

			//�ڽ��� �ϳ��� ���� ���
			if (temp->isLeaf())
			{

				NODE_TYPE nType = NODE_TYPE::END;
				//�θ� ���� ��
				if (temp->isRoot())
				{
					root = nullptr;
				}
				else
				{
					if (temp->isLeftChild())
					{
						nType = NODE_TYPE::LCHILD;
					}
					if (temp->isRightChild())
					{
						nType = NODE_TYPE::RCHILD;
					}
					//�θ��� �ڽ� ���� ����
					temp->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)nType] = nullptr;
				}
				// �ڽ� ����
				delete _pTargetNode;
			}
			//�ڽ��� �� ���� ���
			else if (temp->isFull())
			{
				//������ �ڸ��� �����ļ��� ���� �״�� ����
				_pTargetNode->pair = pSuccessor->pair;

				//�����ļ��� ��� ����
				deleteNode(pSuccessor);
				++count;
				//���� �ڸ��� �����ļ����� ���� ���� �׷��� ��ȯ���� ���� 
				pSuccessor = _pTargetNode;
			}
			//�ڽ��� �� ���ΰ��
			else
			{
				NODE_TYPE pType = NODE_TYPE::END;
				NODE_TYPE cType = NODE_TYPE::END;
				//�����ʿ� �ڽ��� ������
				if (temp->arrNode[(int)NODE_TYPE::LCHILD] == nullptr)
				{
					cType = NODE_TYPE::RCHILD;
				}
				//���ʿ� �ڽ��� ������
				else
				{
					cType = NODE_TYPE::LCHILD;
				}

				//�Ѹ��ϋ� == �θ� ������
				if (temp->isRoot())
				{
					//�ڽĳ���� �θ� null�� �����
					temp->arrNode[(int)cType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
					//�ڽĳ�带 ��Ʈ�� �����.
					root = temp->arrNode[(int)cType];

					delete _pTargetNode;
				}
				//�θ� �ִٸ� ���� �������� ����������
				else
				{
					//�θ𿡰� �����ڽ�����
					if (temp->isLeftChild())
					{
						pType = NODE_TYPE::LCHILD;
					}
					//�θ𿡰� ������ �ڽ�����
					else
					{
						pType = NODE_TYPE::RCHILD;
					}


					//�θ� �ڽ��̶� ����
					temp->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)pType] = temp->arrNode[(int)cType];
					//�ڽ��� �θ�� ����
					temp->arrNode[(int)cType]->arrNode[(int)NODE_TYPE::PARENT] = temp->arrNode[(int)NODE_TYPE::PARENT];
					//�ڽ��� ����
					delete _pTargetNode;
				}
			}
			--count;
			return pSuccessor;
		}
	public:
		CBST() : root(nullptr), count(0) {}
		void insert(const tPair<T1, T2>& _pair)
		{
			tNode<T1, T2>* newNode = new tNode<T1, T2>(_pair,nullptr, nullptr, nullptr);
			newNode->pair = _pair;
			
			//�����Ͱ� �ƹ��͵� ������
			if (nullptr == root)
			{
				root = newNode;
			}
			//first ���� ���ؼ� ��ġ ����
			else
			{
				tNode<T1, T2>* iNode = root;
				NODE_TYPE node_type = NODE_TYPE::END;
				while (true)
				{

					//��Ʈ���� ũ�� ����������
					if (iNode->pair.first < newNode->pair.first)
					{
						node_type = NODE_TYPE::RCHILD;
					}
					//��Ʈ���� ������ �������� 
					else if (iNode->pair.first > newNode->pair.first)
					{
						node_type = NODE_TYPE::LCHILD;
					}
					else
					{
						return;
					}
					//�������� ��������� �ְ�
					if (nullptr == iNode->arrNode[(int)node_type])
					{
						iNode->arrNode[(int)node_type] = newNode;
						newNode->arrNode[(int)NODE_TYPE::PARENT] = iNode;
						break;
					}
					//�� ��������� �̵��ϰ�
					else
					{
						iNode = iNode->arrNode[(int)node_type];
					}
				}
			}
			++count;
		}
		tNode<T1, T2>* getInOrderSuccessor(tNode<T1, T2>* _p)
		{
			tNode<T1, T2>* temp = _p;
			//������ �ڽ��� ������ ���������� ���� �� ��������
			if (_p->arrNode[(int)NODE_TYPE::RCHILD] != nullptr)
			{
				temp = _p->arrNode[(int)NODE_TYPE::RCHILD];
				while (temp->arrNode[(int)NODE_TYPE::LCHILD] != nullptr)
				{
					temp = temp->arrNode[(int)NODE_TYPE::LCHILD];
				}
				return temp;
			}
			else
			{
				if (temp->isRoot())
					return nullptr;
				//������ �ڽ��� ������ �θ𿡰� �����ڽ��̾����� Ȯ��
				while (!temp->isLeftChild())
				{
					//������ �ڽ��̾����� �θ� �ö󰡼� ��� �ݺ�
					temp = temp->arrNode[(int)NODE_TYPE::PARENT];
					if (temp->isRoot())
						return nullptr;
				}
				//�����ڽ��̾����� �θ� �ļ�������
				return temp->arrNode[(int)NODE_TYPE::PARENT];
				
			}
		} 
		tNode<T1, T2>* getInOrderPredecessor(tNode<T1, T2> _p)
		{

		}



		class iterator;
		iterator begin();
		iterator end();
		iterator find(const T1& _t1);
		iterator erase(const iterator& _iter)
		{ 
			assert(this == _iter.iCBST);

			tNode<T1, T2>* pSuccessor = deleteNode(_iter.iNode);
			return iterator(this, pSuccessor);
		}

		class iterator
		{
		public:
			tNode<T1, T2>* iNode; // null�϶� end iterator
			CBST<T1, T2>* iCBST;
		public:
			iterator()
				:iNode(nullptr), iCBST(nullptr)
			{}
			iterator(CBST<T1, T2>* _icbst, tNode<T1, T2>* _inode)
				:iNode(_inode), iCBST(_icbst)
			{}
			bool operator ==(const iterator& _other)
			{
				if (iNode == _other.iNode && iCBST == _other.iCBST)
				{
					return true;
				}
				return false;
			}
			bool operator !=(const iterator& _other)
			{
				return !(*this == _other);
			}
			const tPair<T1, T2>& operator* ()
			{
				if (iNode == nullptr)
				{
					cout << "ERROR :END ITERATOR." << endl;
					assert(iNode);
				}
				return iNode->pair;
			}
			const tPair<T1, T2>* operator-> ()
			{
				if (iNode == nullptr)
				{
					cout << "ERROR :END ITERATOR." << endl;
					assert(iNode);

				}
				return &iNode->pair;
			}

			iterator operator++()
			{
				tNode < T1, T2>* temp = iCBST->getInOrderSuccessor(iNode);
				iNode = temp;
				return *this;
			}
			iterator& operator++(int)
			{
				tNode<T1,T2>* temp = iCBST->getInOrderSuccessor(iNode);
				iNode = temp;
				return this;
			}
			iterator operator--()
			{

			}
			iterator& operator--(int)
			{

			}
		};
	};
	
	template<class T1, class T2> // ���� ���� ù��°
	inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
	{
		tNode<T1,T2>* now = root;
		//���ʿ� �ڽ��� ������ ���� == now�� ù���� 
		while (nullptr != now->arrNode[(int)NODE_TYPE::LCHILD])
		{
			now = now->arrNode[(int)NODE_TYPE::LCHILD];
		}
		return iterator(this, now);
	}
	template<class T1, class T2> // ���� ���� ������ + 1
	inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
	{
		return iterator(this, nullptr);
	}
	template<class T1, class T2>
	inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _t1)
	{
		if (nullptr == root)
		{
			return this->end();
		}
		tNode<T1, T2>* now = root;
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{
			// _t1�� ������ 
			if (now->pair.first > _t1)
			{
				node_type = NODE_TYPE::LCHILD;
			}
			// _t1�� Ŭ ��
			else if (now->pair.first < _t1)
			{
				node_type = NODE_TYPE::RCHILD;
			}
			//ã����
			else
			{
				 cout << "ã�Ҿ�!!" << endl;
				 break;
			}
			// ��尡 ������ �̵� ������ �� ã��
			if (nullptr != now->arrNode[(int)node_type])
			{
				now = now->arrNode[(int)node_type];
				continue;
			}
			//�� ã��
			return this->end();
		}

		return iterator(this, now);
	}
}
#endif // !__DATATYPE__
