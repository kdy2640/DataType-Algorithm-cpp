
#include"BTreeNode.cpp"
#include <sstream> 
#include <cassert>
#include<iostream>
#include<fstream>

using namespace std;  

using namespace DataType;

int main() {
    // [] 연산자 테스트 케이스
    bTNode<int, 2> node;
    node[0] = 10;
    node[1] = 20;
    node[2] = 30;

    // 기본 접근 테스트
    assert(node[0] == 10);
    assert(node[1] == 20);
    assert(node[2] == 30);

    //출력
    cout << node[0] << node[1] << node[2] << endl;
    // 값 수정 테스트
    node[1] = 25;
    assert(node[1] == 25);

    // = 연산자 테스트 케이스
    bTNode<int, 2> newNode;
    newNode = node; // 기본 복사 테스트

    // 복사된 값 확인
    assert(newNode[0] == 10);
    assert(newNode[1] == 25);
    assert(newNode[2] == 30);

    // 자기 대입 테스트
    node = node;
    assert(node[1] == 25); // 값이 변경되지 않았는지 확인

    std::cout << "모든 테스트가 성공적으로 완료되었습니다.\n";
    return 0;
} 
