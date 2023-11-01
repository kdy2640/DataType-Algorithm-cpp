#include<iostream>
#include<fstream>
#include "ArithmeticExpressionEvaluator.h"
using namespace std;
using namespace DataType;

int main()
{
	AEE evaluator;
	cout << evaluator.read_expression();

}

