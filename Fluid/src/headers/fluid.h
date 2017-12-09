#ifndef __FLUID_H__
#define __FLUID_H__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

class Point
{
public:
    double x, t, val;

    Point(double, double, double);
};

class Field // сетка
{
public:
    int numX, numT;
    double deltaT, deltaX, maxT, maxX;
    std::vector<std::vector<double>> field;

    void fieldInit(); // создает сетку и генерит граничные условия

    void Print();
    void Export(const char*); // вывод в файлы

    Field(double, double, double, double);
    Field(const Field&);
    ~Field();
    
};

void init(double, double, double, double); // запуск вычислений

double ODE(Field, int, int);

#endif 
