#ifndef _AEE_
#define _AEE_
#include<string>
#include<iostream>
#include"OurDeque.cpp"

namespace DataType
{
	class AEE
	{
	public:
		string read_expression();
		string convert_to_postfix(string s);
		double evaluate_postfix(string s);

	};
}
#endif // !_AEE_
