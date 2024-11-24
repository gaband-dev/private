#include <iostream>
#include <sstream>
#include "Calculator.h"

int main()
{
	std::string line;
	std::string number;
	Calculator mycalc;
	std::stack<double> Operands;
	std::stack<char> Operators;

	while(true)
	{
		std::getline(std::cin, line);

		mycalc.ParseInput(line, Operands, Operators);

		mycalc.BuildExpression(Operands, Operators);

		std::cout << mycalc.Evaluate() << std::endl;
	}

	return 0;
}
