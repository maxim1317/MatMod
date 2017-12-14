#ifndef __FLUID_H__
#define __FLUID_H__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
// #include <string>
#include <cmath>

class Field // сетка
{
public:
    bool fl;
    int numX, numT;
    double deltaT, deltaX, maxT, maxX;
    std::vector<std::vector<double>> field;

    void fieldInit(); // создает сетку и генерит граничные условия

    void Print(Field &);
    void Export(const char*); // вывод в файлы

    Field(double, double, double, double, bool);
    Field(const Field&);
    ~Field();
    
};

void init(double, double, double, double, bool); // запуск вычислений

double ODE(Field &, int, int, int);

void GenerateGNU(Field &, char*, char*, char*);

const char* conColor(int);

#endif 
