#include "Node.h"
#include <iostream>
#include <sstream>

Number::Number(double Value) : Value{Value}
{

}

double Number::Evaluate() const
{
    return Value;
}

Operator::Operator(Node* LeftChild, Node* RightChild) : LeftChild{LeftChild}, RightChild{RightChild}
{

}

Operator::~Operator()
{
    delete LeftChild;
    delete RightChild;
}

double Addition::Evaluate() const
{
    return LeftChild->Evaluate() + RightChild->Evaluate();
}