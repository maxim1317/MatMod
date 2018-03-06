#include "headers/fluid.h"

int main(int argc, char const *argv[])
{
    double deltaT, deltaX, maxT, maxX;
    deltaT = 0.1;
    deltaX = 0.1;
    maxT = 1.8;
    maxX = 1.8;
    bool flag = 1;
    init(deltaT, deltaX, maxT, maxX, flag);
    return 0;
}