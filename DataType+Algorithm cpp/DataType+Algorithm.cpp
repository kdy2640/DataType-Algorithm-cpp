#include<iostream>
#include<fstream>
#include"BTreeNode.cpp"
#include <sstream>

using namespace std; 
using namespace DataType;

int main()
{

    DataType::bTNode<int, 4> bTreeNode; // MIN 값을 2로 가정한 bTNode 인스턴스 생성

    // 데이터를 무작위 순서로 추가
    int dataToAdd[] = { 3, 1, 4, 2, 9, 5, 7, 8, 6 };
    std::cout << "Adding data in random order..." << std::endl;
    for (int i = 0; i < 9; i++) {
        bTreeNode.addData(dataToAdd[i]);
        std::cout << "Added " << dataToAdd[i] << std::endl;
    }

    // 각 데이터의 위치 확인
    std::cout << "Checking positions of data..." << std::endl;
    for (int i = 1; i <= 9; i++) {
        int index = bTreeNode.findData(i);
        std::cout << "Position of " << i << ": " << index << std::endl;
    }
}

