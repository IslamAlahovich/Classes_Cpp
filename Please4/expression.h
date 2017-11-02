#ifndef EXPRESSION_H
#define EXPRESSION_H


class Expression
{
public:
    virtual Expression* diff() = 0;
    virtual double evaluate(double x) = 0;
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
    ~Add();
    Expression* diff();
    double evaluate(double x);
    void print();
};

class Sub : public Expression
{
private:
    Expression* sumd1_ptr;
    Expression* sumd2_ptr;
public:
    Sub(Expression* sumd1, Expression* sumd2) : sumd1_ptr(sumd1), sumd2_ptr(sumd2)
    {}
    ~Sub();
    Expression* diff();
    double evaluate(double x);
    void print();
};

class Mul : public Expression
{
private:
    Expression* sumd1_ptr;
    Expression* sumd2_ptr;
public:
    Mul(Expression* sumd1, Expression* sumd2) : sumd1_ptr(sumd1), sumd2_ptr(sumd2)
    {}
    ~Mul();
    Expression* diff();
    double evaluate(double x);
    void print();
};

class Div : public Expression
{
private:
    Expression* sumd1_ptr;
    Expression* sumd2_ptr;
public:
    Div(Expression* sumd1, Expression* sumd2) : sumd1_ptr(sumd1), sumd2_ptr(sumd2)
    {}
    ~Div();
    Expression* diff();
    double evaluate(double x);
    void print();
};

class Number : public Expression
{
private:
    double value;
public:
    Number(double val): value(val)
    {}
    Expression* diff();
    double evaluate(double x);
    void print();
};

class Variable : public Expression
{
private:
    char var;
public:
    Variable(char x): var(x)
    {}
    Expression* diff();
    double evaluate(double x);
    void print();
};

#endif // EXPRESSION_H
