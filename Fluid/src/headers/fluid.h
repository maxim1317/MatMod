#ifndef __DUMBBELLIES_H__
#define __DUMBBELLIES_H__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cmath>

class Point
{
private:
    double x, y, val;

public:
    Point(double, double, double);
};

class Field
{
public:
    double deltaTime, deltaSpace, maxTime, maxSpace;

    void fieldInit();

    void Export();

    Field(double, double, double, double);
    ~Field();
    
};

void init();

double IODE(Field, Point);
double IIODE(Field, Point);

#endif 
