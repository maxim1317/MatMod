#include "fluid.h"

void Field::fieldInit() //тут нужно создать сетку и сгенерить граничные условия
{
    std::vector<double> v(numT, -1);
    field.assign(numX, v);
    // for (int i = 0; i < numT; ++i)
    // {
    //     field[0][i] = -3*i*deltaT+7;
    //     field[numX-1][i] = -3*i*deltaT+3*i*deltaX+7;
    // }
    // for (int i = 0; i < numX; ++i)
    // {
    //     field[i][0] = 3 * i * deltaX + 7;
    // }
    for (int i = 0; i < numX; ++i)
    {
        for (int j = 0; j < numT; ++j)
        {
            field[i][j] = 3*(i*deltaX-j*deltaT)+7;
        }
    }
}

Field::Field(double deltaT_, double deltaX_, double maxT_, double maxX_)
{
    deltaT = deltaT_;
    deltaX = deltaX_;
    maxT = maxT_;
    maxX = maxX_;

    numT = maxT/deltaT;
    numX = maxX/deltaX;

    fieldInit();

    Print();

}

Field::Field(const Field &obj)
{
    field = obj.field;

    deltaT = obj.deltaT;
    deltaX = obj.deltaX;
    maxT = obj.maxT;
    maxX = obj.maxX;

    numT = maxT/deltaT;
    numX = maxX/deltaX;

}
    
Field::~Field()
{

}