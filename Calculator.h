#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>
#include "Node.h"

class Calculator
{
	public:
		Calculator() {}

		void ParseInput(const std::string& Input, std::stack<double>& Operands, std::stack<char>& Operators);
		Node* GetExpression(const double& Lhs, const double& Rhs, const char& Operator);
		Node* BuildExpressionTree(std::stack<double>& Operands, std::stack<char>& Operators);
		void BuildExpression(std::stack<double>& Operands, std::stack<char>& Operators);
		double Evaluate();

	private: 
		Node* root;
};

#endif 
