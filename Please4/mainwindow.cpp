#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "expression.h"
#include <cmath>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::myF(double x)//Функция
{
    return sin(x);
}

void MainWindow::on_pushButton_clicked()
{
    double a = 1.0; //Начало интервала по Ox
    double b =  6.28; //Конец интервала по Ox
    double h = 0.01; //Шаг

    int N=(b - a)/h + 2; //Количество точек
    QVector<double> X(N), Y(N), dY(N);

    Expression* e = new Div(new Number(3.0), new Variable('x')); // (3/x)
    Expression* de = e->diff(); // (3/x)' = (-3/x^2)

    e->print();
    cout << "\n";
    de->print();
    cout << "\n";

    int i=0;
    for (double t = a; t <= b; t += h)
    {
        X[i] = t;
        Y[i] = e->evaluate(t); //Формула нашей функции
        dY[i] = de->evaluate(t); //Формула диф.функции
        i++;
    }

    delete e;
    delete de;

    //-------ОТРИСОВКА-ГРАФИКОВ------------------
    ui->widget->clearGraphs();

    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::blue)); //График Функции
    ui->widget->addGraph();
    ui->widget->graph(1)->setPen(QPen(Qt::red)); //График Производной

    ui->widget->graph(0)->setData(X, Y);
    ui->widget->graph(1)->setData(X, dY);

    ui->widget->xAxis->setRange(a, b);

    double minY = Y[0], maxY = Y[0];
    for (int i = 1; i < Y.size(); i++)
    {
        if (Y[i] < minY) minY = Y[i];
        if(dY[i] < minY) minY = dY[i];
        if (Y[i] > maxY) maxY = Y[i];
        if(dY[i] > maxY) maxY = dY[i];
    }
    ui->widget->yAxis->setRange(minY - 1, maxY + 1);

    ui->widget->replot();
}
