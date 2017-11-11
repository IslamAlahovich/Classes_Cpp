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
	Add(Expression* sumd1, Expression* sumd2) : sumd1_ptr(sumd1), sumd2_ptr(sumd2)
	{}
	~Add()
	{
		delete sumd1_ptr;
		delete sumd2_ptr;
	}
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
	~Sub()
	{
		delete sumd1_ptr;
		delete sumd2_ptr;
	}
	Expression* diff()
	{
		Sub* diff_sub = new Sub(sumd1_ptr->diff(), sumd2_ptr->diff());
		return diff_sub;
	}
	void print()
	{
		sumd1_ptr->print();
		cout << "-";
		sumd2_ptr->print();
	}
};

class Mul : public Expression
{
private:
	Expression* sumd1_ptr;
	Expression* sumd2_ptr;
public:
	Mul(Expression* sumd1, Expression* sumd2) : sumd1_ptr(sumd1), sumd2_ptr(sumd2)
	{}
	~Mul()
	{
		delete sumd1_ptr;
		delete sumd2_ptr;
	}
	Expression* diff()
	{
		Add* diff_mul = new Add(new Mul(sumd1_ptr->diff(), sumd2_ptr), new Mul(sumd1_ptr, sumd2_ptr->diff()));
		return diff_mul;
	}
	void print()
	{
		sumd1_ptr->print();
		cout << "*";
		sumd2_ptr->print();
	}
};

class Div : public Expression
{
private:
	Expression* sumd1_ptr;
	Expression* sumd2_ptr;
public:
	Div(Expression* sumd1, Expression* sumd2) : sumd1_ptr(sumd1), sumd2_ptr(sumd2)
	{}
	~Div()
	{
		delete sumd1_ptr;
		delete sumd2_ptr;
	}
	Expression* diff()
	{
		Div* diff_div = new Div(new Sub(new Mul(sumd1_ptr->diff(), sumd2_ptr), new Mul(sumd1_ptr, sumd2_ptr->diff())), new Mul(sumd2_ptr, sumd2_ptr));
		return diff_div;
	}
	void print()
	{
		sumd1_ptr->print();
		cout << "/";
		sumd2_ptr->print();
	}
};

class Number : public Expression
{
private:
	int value;
public:
	Number(int val) : value(val)
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
	Variable(char x) : var(x)
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
	Expression* e = new Add(new Number(1337), new Variable('x'));
	Expression* de = e->diff();
	de->print();
	delete e;
	delete de;
	cout << "\n";

	Expression* s = new Sub(new Variable('y'), new Number(1488));
	Expression* ds = s->diff();
	ds->print();
	delete s;
	delete ds;
	cout << "\n";

	Expression* m = new Mul(new Number(2), new Variable('u'));
	Expression* dm = m->diff();
	dm->print();
	delete m;
	delete dm;
	cout << "\n";

	Expression* d = new Div(new Variable('u'), new Variable('v'));
	Expression* dd = d->diff();
	dd->print();
	delete d;
	delete dd;
	cout << "\n";

	return 0;
}