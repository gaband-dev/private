#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <stack>

void Calculator::ParseInput(const std::string& Input, std::stack<double>& Operands, std::stack<char>& Operators)
{
	std::string number;

	for (auto &ch : Input)
	{
		if (ch == '+')
		{
			Operands.push(std::stod(number));
			number = "";
			Operators.push(ch);
		}
		else 
		{
			number.push_back(ch);
		} 
	}
			
	Operands.push(std::stod(number));
}

Node* Calculator::GetExpression(const double& Lhs, const double& Rhs, const char& Operator)
{
	Number* LeftNode  = new Number(Lhs);
	Number* RightNode = new Number(Rhs);

	(void) Operator;

	return new Addition(LeftNode, RightNode);
}

Node* Calculator::BuildExpressionTree(std::stack<double>& Operands, std::stack<char>& Operators)
{
	double Lhs = Operands.top();
	Operands.pop();

	if (Operands.empty())
	{
		return new Number(Lhs);
	}
	else if((Operands.size() == 1))
	{
		double Rhs = Operands.top();
		Operands.pop();

		// char Operator = Operators.top();
		Operators.pop();

		return Calculator::GetExpression(Lhs, Rhs, '+'); 
	}
	else 
	{
		double Rhs = Operands.top();
		Operands.pop();

		// char Operator = Operators.top();
		Operators.pop();

		return new Addition(Calculator::GetExpression(Lhs, Rhs, '+'), Calculator::BuildExpressionTree(Operands, Operators));
	}
}

void Calculator::BuildExpression(std::stack<double>& Operands, std::stack<char>& Operators)
{
	this->root = Calculator::BuildExpressionTree(Operands, Operators);
}

double Calculator::Evaluate()
{
	return root->Evaluate();
}

// Node* Calculator::GetNode(const char& Input)
// {
// 	if(Input == '+')
// 	{
// 		return new 
// 	}
// }

