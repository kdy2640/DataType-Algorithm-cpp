#ifndef _AEE_
#define _AEE_
#include<string>

namespace DataType
{
	class AEE
	{
	public:
		string read_expression();
		string convert_to_postfix();
		double evaluate_postfix();

	};
}
#endif // !_AEE_
