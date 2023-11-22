#include"ArithmeticExpressionEvaluator.h"
#include <cmath>
#include <sstream>

namespace DataType
{
	const static int CAPACITY = 1000;
	enum TAG
	{
		NONE,
		NUMBER,
		ALPHABET,
		SYMBOL
	};
	enum OPERATOR
	{
		PLUS,
		MINUS,
		MULTIPLY,
		DIVIDE,
		LEFT_PARENTHESES
	};

	
	typedef struct AEEitem
	{
		double value;
		TAG tag;
		AEEitem() { value = 0; tag = TAG::NONE; }
		AEEitem(double _value, TAG _tag) { value = _value; tag = _tag; }
	} Aitem; 
	ostream& operator<< (ostream& out,Aitem& _item)
	{
		cout << _item.value;
		return out;
	}

	char enumtochar(OPERATOR _operator);
	OPERATOR chartoenum(char _char);
	string arrayToString(const Aitem* _arr, int _capacity);


	// precondition : Input a well-formed infix arithmetic expression upto 1000 number of string
	//				: can cover all real valued numbers but negative number must in parentheses, i.e , (-5) + 5
	//              : and noninteger number's precision is 5. 
	// postcondition: a string for the infix expression has been returned (Example: ¡°(5.73*x +.6) / y¡± )
	string AEE::read_expression()
	{
		string input;
		char*  cinput = new char[CAPACITY + 1];
		//get Input
		cout << "Input Infix Arithmetic Expression " <<endl;
		cout << "Infix Expression : ";
		cin.getline(cinput, CAPACITY);
		//chararray to string
		input.assign(cinput);
		return input;
	}

	// precondition  : s is a well-formed infix arithmetic expression (i.e., no error checking required) 
	// postcondition : a string for well-formed postfix expression converted from s has been returne
	//				 : (Note that the operands and operators need to be separated by least one blank space in a string for well - formed postfix expression. (Example: ¡°5.73 x * .6 + y / ¡±))
	string AEE::convert_to_postfix(string s)
	{
		// want to store operand and operator into double array and transform to string.
		Aitem* coutput = new Aitem[CAPACITY];
		int len = s.length();
		int outputIndex = 0;
		
		OurDeque<OPERATOR> stack;

		bool isBeforeLeftParentheses = false;
		bool isMinusNumber = false;

		for (int i = 0; i < len; i++)
		{
			char now = s[i];
			// left parentheses - just input to stack and set isBeforeLeftParentheses true
			if (now == '(')
			{
				stack.push_back(OPERATOR::LEFT_PARENTHESES);
				isBeforeLeftParentheses = true;
				continue;
			}
			//blank - continue
			else if (now == ' ')
			{
				continue;
			}
			// number 
			else if ((now >= 48) && (now <= 57))
			{
				int t = 0;
				bool isTherePeriod = false;
				//find end of numbers s[i+t] will be end of numbers
				while (true)
				{
					if (i + t >= len)
					{
						t--;
						break;
					}
					char temp = s[i + t];
					if (((temp >= 48) && (temp <= 57)) || temp == '.')
					{
						if (temp == '.') isTherePeriod = true;
						t++;
						continue;
					}
					t--;
					break;
				}

				char* nArr = new char[t + 2];
				nArr[t + 1] = '\0';
				int location = 0;
				
				// find . and make array of number
				for (int j = 0; j <= t && i + j < len; j++)
				{
					nArr[j] = s[i + j];
					if (s[i + j] == '.') location = j;
				}
				
				double number = 0;
				if (isTherePeriod)
				{
					// make real number from char array
					for (int j = 0; j <= t; j++)
					{
						if (j < location)
						{
							number += pow(10, location - 1 - j) * (nArr[j] - 48);
						}
						else if (j > location)
						{
							number += (nArr[j] - 48) / pow(10, j - location);
						}
					}
				}
				else
				{
					// make natural number from char array
					for (int j = 0; j <= t; j++)
					{
							number += pow(10, t-j) * (nArr[j] - 48);
					}
				}


				if (isMinusNumber)
				{
					coutput[outputIndex++] = Aitem((-1) * number, TAG::NUMBER);
				}
				else
				{
					coutput[outputIndex++] =  Aitem(number,TAG::NUMBER);
				}

				isMinusNumber = false;
				i = i + t;
			}
			// alphabet - just input
			else if ((now >= 65 && now <= 90) || (now >= 97 && now <= 122))
			{
				coutput[outputIndex++] = Aitem(now,TAG::ALPHABET);
			}
			// operator + - * /
			else if ((now == '+') || (now == '-') || (now == '*') || (now == '/'))
			{
				bool temp = ((isBeforeLeftParentheses == true) && (now == '-'));
				if (temp)
				{
					isMinusNumber = true;
					continue;
				}
				OPERATOR enumOperator;
				char charOperator;
				// allocate operator enum value

				enumOperator = chartoenum(now);

				while (true)
				{
					if (stack.size() == 0) break;
					if (stack.back() == OPERATOR::LEFT_PARENTHESES) break;
					// Because + = 0, - = 1, * = 2 , / = 3, Operator/2 be Priority of calculation ex) * / 2 = 1 > - / 2 = 0
					if ((stack.back() / 2) < (enumOperator / 2)) break;

					coutput[outputIndex++] = Aitem(stack.pop_back(),TAG::SYMBOL);
				}

				stack.push_back(enumOperator);
			}
			// right parentheses
			else if (now == ')')
			{
				while (stack.back() != OPERATOR::LEFT_PARENTHESES)
				{
					coutput[outputIndex++] = Aitem(stack.pop_back(),TAG::SYMBOL);
				}
				stack.pop_back();
			}
			// error 
			else
			{
				cout << "ERROR : There is abnormal char in Input." << endl;
				return "0";
			}

			 isBeforeLeftParentheses = false;

		}

		while (stack.size() > 0)
		{
			coutput[outputIndex++] = Aitem(stack.pop_back(), TAG::SYMBOL);
		}

		string output = arrayToString(coutput, outputIndex);

		return output;
	}

	// precondition : string s is a well-formed postfix arithmetic expression (i.e., no error-checking required) in which variables are allowed
	//              : if there is unknown value, have to input value
	// postcondition: the evaluation result for s has been returne
	double AEE::evaluate_postfix(string s)
	{
		istringstream iss(s);
		OurDeque<Aitem> list;
		OurDeque<double> evaluateStack;
		string temp;

		//string to list such that element is Aitem
		while (iss >> temp)
		{
			char now = temp[0];
			int len = temp.length();

			// alphabet or opperator or one number
			if (len == 1)
			{
				//one number
				if ((now >= 48) && (now <= 57))
				{
					list.push_back(Aitem(now-48, TAG::NUMBER));
				}
				//alphabet
				else if ((now >= 65 && now <= 90) || (now >= 97 && now <= 122))
				{
					cout << "Input the " << (char)now << " Value : ";
					double input = 0;
					cin >> input;
					list.push_back(Aitem(input, TAG::NUMBER));
					cin.ignore(1);
				}
				else
				{
					list.push_back(Aitem(now, TAG::SYMBOL));
				}
			}
			//number
			else
			{
				list.push_back(Aitem(stod(temp), TAG::NUMBER));
			}

		}

		//evaluate
		while (list.getCount() != 0)
		{
			Aitem now = list.pop_front();
			//number
			if (now.tag == NUMBER)
			{
				evaluateStack.push_back(now.value);
			}
			// operator 
			else
			{
				double result = 0;
				double second = evaluateStack.pop_back();
				double first = evaluateStack.pop_back();

				switch ((int)now.value)
				{
				case '+':
					result = first + second;
					break;
				case '-':
					result = first - second;
					break;
				case '*':
					result = first * second;
					break;
				case '/':
					result = first / second;
					break;
				default:
					break;
				}
				evaluateStack.push_back(result);
			}
		}


		return evaluateStack.pop_back();
	}


	char enumtochar(OPERATOR _operator)
	{
		char charOperator = 0;
		switch (_operator)
		{
		case OPERATOR::PLUS:
			charOperator = '+';
			break;
		case OPERATOR::MINUS:
			charOperator = '-';
			break;
		case OPERATOR::MULTIPLY:
			charOperator = '*';
			break;
		case OPERATOR::DIVIDE:
			charOperator = '/';
			break;
		case OPERATOR::LEFT_PARENTHESES:
			charOperator = '(';
			break;
		default:
			break;
		}
		return charOperator;
	}
	OPERATOR chartoenum(char _char)
	{
		OPERATOR enumOperator = OPERATOR::DIVIDE;
		switch(_char)
		{
		case '+':
			enumOperator = OPERATOR::PLUS;
			break;
		case '-':
			enumOperator = OPERATOR::MINUS;
			break;
		case '*':
			enumOperator = OPERATOR::MULTIPLY;
			break;
		case '/':
			enumOperator = OPERATOR::DIVIDE;
			break;
		case '(':
			enumOperator = OPERATOR::LEFT_PARENTHESES;
			break;
		default:
			break;
		}
		return enumOperator;
	}
	// precondition: input Aitem array and capacity
	// postcondition: return string which list of Aitem's value and seperated by ' ' 
	string arrayToString(const Aitem* _arr, int _capacity)
	{
		ostringstream oss;
		for (int i = 0; i < _capacity; ++i) {
			Aitem now = _arr[i];
			// operator check
			if (now.tag == TAG::SYMBOL)
			{
				oss << enumtochar((OPERATOR)now.value);
			}
			//alphabetcheck
			else if (now.tag == TAG::ALPHABET)
			{
				oss << (char)now.value;
			}
			else if( now.tag ==TAG::NUMBER)
			{
				int decimalIndex = 0;
				oss.setf(ios::fixed);
				if (now.value < (double)(0))
				{
					now.value = (-1) * now.value;

					string temp = to_string(now.value);
					int decimal = log10(now.value) + 2;
					while (decimalIndex + decimal < temp.length())
					{
						if (temp[decimalIndex + decimal] == '0') break;
						decimalIndex++;
					}
					oss << '-';

					oss.precision(min(5, decimalIndex));
					oss << (double)now.value;
				}
				else
				{
					string temp = to_string(now.value);
					int decimal = log10(now.value)+2;
					while (decimalIndex + decimal < temp.length())
					{
						if (temp[decimalIndex + decimal] == '0') break;
						decimalIndex++;
					}

					oss.precision(min(5, decimalIndex));
					oss << (double)now.value;
				}
			}
			if (i < _capacity - 1) {
				oss << " ";
			}
		}
		oss << " ";
		return oss.str();
	}
}

//
//int main()
//{
//	// precondition : Input a well-formed infix arithmetic expression upto 1000 number of string
//	//				: can cover all real value numbers but negative number must be in parentheses and cannot use with alphabet. i.(ex , (-5) + 5 == Valid, (-A) == Not Valid)
//	//              : also, noninteger number's precision is 10. )
//	AEE calculator;
//	char input;
//
//	while (true)
//	{
//		cin.clear();
//		cout << "If you want to quit, input q" << endl;
//		string infix = calculator.read_expression();
//		if (infix == "q" || infix == "Q") break;
//		string postfix = calculator.convert_to_postfix(infix);
//
//		cout << "PostFix Expression : " << postfix << endl;
//
//		cout.setf(ios::fixed);
//		cout << "Answer : " << calculator.evaluate_postfix(postfix) << endl << endl;
//
//	}
//}
//
