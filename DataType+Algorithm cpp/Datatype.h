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
		//
		class iterator;
		iterator begin();
		iterator end();

		class iterator
		{
		public:
			T* pDArr;           //데이터 시작의 주소
			DynamicArray* pArr; // 가변배열의 주소
			int index;          // 데이터의 인덱스
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
				//iterator 가 알고있는 주소랑 같은지 확인
				if (pDArr != pArr->dArr || -1 == index) {
					assert(nullptr);
				}
				return pDArr[index];
			}
			//전위 ++
			iterator& operator ++()
			{

				//2. end 이터레이터일 경우
				//3. 주소가 다른 경우
				if (pDArr != pArr->dArr || -1 == index) {
					assert(nullptr);
				}

				//1.마지막 데이터일 경우 0 오류는 아님
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
			//후위 ++
			iterator operator ++(int)
			{
				iterator copy = *this;
				
				++(*this);

				return copy;
			}
			//전위 --
			iterator& operator --()
			{
				return *this;
			}
			//후위 --
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
		//자신의 데이터
		tPair<T1,T2> pair;
		//인근 노드의 데이터
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
	//T1은 key, T2는 value
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

			//자식이 하나도 없는 경우
			if (temp->isLeaf())
			{

				NODE_TYPE nType = NODE_TYPE::END;
				//부모가 없을 때
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
					//부모의 자식 정보 삭제
					temp->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)nType] = nullptr;
				}
				// 자식 삭제
				delete _pTargetNode;
			}
			//자식이 두 개인 경우
			else if (temp->isFull())
			{
				//삭제될 자리에 중위후속자 값을 그대로 넣음
				_pTargetNode->pair = pSuccessor->pair;

				//중위후속자 노드 삭제
				deleteNode(pSuccessor);
				++count;
				//삭제 자리에 중위후속자의 값을 넣음 그래서 반환값도 본인 
				pSuccessor = _pTargetNode;
			}
			//자식이 한 개인경우
			else
			{
				NODE_TYPE pType = NODE_TYPE::END;
				NODE_TYPE cType = NODE_TYPE::END;
				//오른쪽에 자식이 있을때
				if (temp->arrNode[(int)NODE_TYPE::LCHILD] == nullptr)
				{
					cType = NODE_TYPE::RCHILD;
				}
				//왼쪽에 자식이 있을때
				else
				{
					cType = NODE_TYPE::LCHILD;
				}

				//뿌리일떄 == 부모가 없을때
				if (temp->isRoot())
				{
					//자식노드의 부모를 null로 만든다
					temp->arrNode[(int)cType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
					//자식노드를 루트로 만든다.
					root = temp->arrNode[(int)cType];

					delete _pTargetNode;
				}
				//부모가 있다면 내가 왼쪽인지 오른쪽인지
				else
				{
					//부모에게 왼쪽자식인지
					if (temp->isLeftChild())
					{
						pType = NODE_TYPE::LCHILD;
					}
					//부모에게 오른쪽 자식인지
					else
					{
						pType = NODE_TYPE::RCHILD;
					}


					//부모를 자식이랑 이음
					temp->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)pType] = temp->arrNode[(int)cType];
					//자식을 부모랑 이음
					temp->arrNode[(int)cType]->arrNode[(int)NODE_TYPE::PARENT] = temp->arrNode[(int)NODE_TYPE::PARENT];
					//자신을 삭제
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
			
			//데이터가 아무것도 없으면
			if (nullptr == root)
			{
				root = newNode;
			}
			//first 끼리 비교해서 위치 지정
			else
			{
				tNode<T1, T2>* iNode = root;
				NODE_TYPE node_type = NODE_TYPE::END;
				while (true)
				{

					//루트보다 크면 오른쪽으로
					if (iNode->pair.first < newNode->pair.first)
					{
						node_type = NODE_TYPE::RCHILD;
					}
					//루트보다 작으면 왼쪽으로 
					else if (iNode->pair.first > newNode->pair.first)
					{
						node_type = NODE_TYPE::LCHILD;
					}
					else
					{
						return;
					}
					//방향이이 비어있으면 넣고
					if (nullptr == iNode->arrNode[(int)node_type])
					{
						iNode->arrNode[(int)node_type] = newNode;
						newNode->arrNode[(int)NODE_TYPE::PARENT] = iNode;
						break;
					}
					//안 비어있으면 이동하고
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
			//오른쪽 자식이 있으면 오른쪽으로 가서 맨 왼쪽으로
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
				//오른쪽 자식이 없으면 부모에게 왼쪽자식이었는지 확인
				while (!temp->isLeftChild())
				{
					//오른쪽 자식이었으면 부모 올라가서 계속 반복
					temp = temp->arrNode[(int)NODE_TYPE::PARENT];
					if (temp->isRoot())
						return nullptr;
				}
				//왼쪽자식이었으면 부모가 후속진행자
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
			tNode<T1, T2>* iNode; // null일때 end iterator
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
	
	template<class T1, class T2> // 중위 기준 첫번째
	inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
	{
		tNode<T1,T2>* now = root;
		//왼쪽에 자식이 없을때 까지 == now가 첫번쨰 
		while (nullptr != now->arrNode[(int)NODE_TYPE::LCHILD])
		{
			now = now->arrNode[(int)NODE_TYPE::LCHILD];
		}
		return iterator(this, now);
	}
	template<class T1, class T2> // 중위 기준 마지막 + 1
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
			// _t1이 작을떄 
			if (now->pair.first > _t1)
			{
				node_type = NODE_TYPE::LCHILD;
			}
			// _t1이 클 때
			else if (now->pair.first < _t1)
			{
				node_type = NODE_TYPE::RCHILD;
			}
			//찾았음
			else
			{
				 cout << "찾았어!!" << endl;
				 break;
			}
			// 노드가 있으면 이동 없으면 못 찾음
			if (nullptr != now->arrNode[(int)node_type])
			{
				now = now->arrNode[(int)node_type];
				continue;
			}
			//못 찾음
			return this->end();
		}

		return iterator(this, now);
	}
}
#endif // !__DATATYPE__
