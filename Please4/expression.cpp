#include "expression.h"
#include <iostream>
using namespace std;

//----ADD-METHODS-------------------------
Add::~Add()
{
    delete sumd1_ptr;
    delete sumd2_ptr;
}

Expression* Add::diff()
{
    Add* diff_add = new Add(sumd1_ptr->diff(), sumd2_ptr->diff());
    return diff_add;
}

double Add::evaluate(double x)
{
    return (sumd1_ptr->evaluate(x)) + (sumd2_ptr->evaluate(x));
}

void Add::print()
{
    sumd1_ptr->print();
    cout << "+";
    sumd2_ptr->print();
}

//----SUB-METHODS------------------------
Sub::~Sub()
{
    delete sumd1_ptr;
    delete sumd2_ptr;
}

Expression* Sub::diff()
{
    Sub* diff_sub = new Sub(sumd1_ptr->diff(), sumd2_ptr->diff());
    return diff_sub;
}

double Sub::evaluate(double x)
{
    return (sumd1_ptr->evaluate(x)) - (sumd2_ptr->evaluate(x));
}

void Sub::print()
{
    sumd1_ptr->print();
    cout << "-";
    sumd2_ptr->print();
}

//----MUL-METHODS-----------------------
Mul::~Mul()
{
    delete sumd1_ptr;
    delete sumd2_ptr;
}

Expression* Mul::diff()
{
    Add* diff_mul = new Add(new Mul(sumd1_ptr->diff(), sumd2_ptr), new Mul(sumd1_ptr, sumd2_ptr->diff()));
    return diff_mul;
}

double Mul::evaluate(double x)
{
    return (sumd1_ptr->evaluate(x))*(sumd2_ptr->evaluate(x));
}

void Mul::print()
{
    sumd1_ptr->print();
    cout << "*";
    sumd2_ptr->print();
}

//----DIV-METHODS-----------------------
Div::~Div()
{
    delete sumd1_ptr;
    delete sumd2_ptr;
}

Expression* Div::diff()
{
    Div* diff_div = new Div(new Sub(new Mul(sumd1_ptr->diff(), sumd2_ptr), new Mul(sumd1_ptr, sumd2_ptr->diff())), new Mul(sumd2_ptr, sumd2_ptr));
    return diff_div;
}

double Div::evaluate(double x)
{
    return (sumd1_ptr->evaluate(x))/(sumd2_ptr->evaluate(x));
}

void Div::print()
{
    sumd1_ptr->print();
    cout << "/";
    sumd2_ptr->print();
}

//----NUMBER-METHODS----------------
Expression* Number::diff()
{
    Expression* diff_num = new Number(0);
    return diff_num;
}

double Number::evaluate(double x)
{
    return value;
}

void Number::print()
{
    cout << value;
}

//----VARIABLE-METHODS------------------
Expression* Variable::diff()
{
    Expression* diff_var = new Number(1);
    return diff_var;
}

double Variable::evaluate(double x)
{
    return x;
}

void Variable::print()
{
    cout << var;
}
