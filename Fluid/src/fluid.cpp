#include "headers/fluid.h"

int main(int argc, char const *argv[])
{
    double deltaT, deltaX, maxT, maxX;
    deltaT = 0.2;
    deltaX = 0.2;
    maxT = 2;
    maxX = 2;
    init(deltaT, deltaX, maxT, maxX);
    return 0;
}