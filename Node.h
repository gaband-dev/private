#ifndef NODE_H 
#define NODE_H

#include <string>

class Node 
{
	public:
		virtual ~Node() = default;

        virtual double Evaluate() const = 0;
};

class Number : public Node
{
    public:
        Number(double Number);

        double Evaluate() const override;

    protected:
        double Value;
};

class Operator : public Node
{
    public:
        Operator(Node* LeftChild, Node* RightChild);

        Operator(Operator const&) = delete;
        Operator(Operator&&) = delete;
        Operator& operator=(Operator const&) = delete;
        Operator& operator=(Operator &&) = delete;

        ~Operator();

    protected:
       Node* LeftChild; 
       Node* RightChild; 
};

#endif 

class Addition : public Operator 
{
    public:
        using Operator::Operator;

        double Evaluate() const override;
};