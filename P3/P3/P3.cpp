#include "stdafx.h"
#include <iostream>
using namespace std;

class Expression
{
public:
	virtual Expression* diff() = 0;
	virtual void print() = 0;
};

class Add : public Expression
{
private:
	Expression* sumd1_ptr;
	Expression* sumd2_ptr;
public:
	Add(Expression* sumd1, Expression* sumd2): sumd1_ptr(sumd1), sumd2_ptr(sumd2)
	{}
	Expression* diff()
	{
		Add* diff_add = new Add(sumd1_ptr->diff(), sumd2_ptr->diff());
		return diff_add;
	}
	void print()
	{
		sumd1_ptr->print();
		cout << "+";
		sumd2_ptr->print();
	}
};

class Sub : public Expression
{
private:
	Expression* sumd1_ptr;
	Expression* sumd2_ptr;
public:
	Sub(Expression* sumd1, Expression* sumd2) : sumd1_ptr(sumd1), sumd2_ptr(sumd2)
	{}
	Expression* diff()
	{
		Sub* diff_add = new Sub(sumd1_ptr->diff(), sumd2_ptr->diff());
		return diff_add;
	}
	void print()
	{
		sumd1_ptr->print();
		cout << "-";
		sumd2_ptr->print();
	}
};

class Number : public Expression
{
private:
	int value;
public:
	Number(int val): value(val)
	{}
	Expression* diff()
	{
		Expression* diff_num = new Number(0);
		return diff_num;
	}
	void print()
	{
		cout << value;
	}
};

class Variable : public Expression
{
private:
	char var;
public:
	Variable(char x): var(x)
	{}
	Expression* diff()
	{
		Expression* diff_var = new Number(1);
		return diff_var;
	}
	void print()
	{
		cout << var;
	}
};

int main()
{
	Expression* e = new Add(new Number(133), new Variable('x'));
	Expression* de = e->diff();
	de->print();
	cout << "\n";

	Expression* s = new Sub(new Variable('y'), new Number(323));
	Expression* ds = s->diff();
	ds->print();
	cout << "\n";

	return 0;
}
