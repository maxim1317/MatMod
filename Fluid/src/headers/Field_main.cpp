#include "fluid.h"

void Field::fieldInit() //тут нужно создать сетку и сгенерить граничные условия
{
    std::vector<double> v(numT, -1.0);
    field.assign(numX, v);
    for (int i = 0; i < numX; ++i)
    {
        for (int j = 0; j < numT; ++j)
        {
            if (!fl)
                {field[i][j] = 3.0*(i*deltaX-j*deltaT)+7;}
            else
                field[i][j] = 8.0*(i*deltaX*i*deltaX+2.0*j*deltaT)-4*i*deltaX+3;
        }
    }
}

Field::Field(double deltaT_, double deltaX_, double maxT_, double maxX_, bool fl_)
{
    deltaT = deltaT_;
    deltaX = deltaX_;
    maxT = maxT_;
    maxX = maxX_;

    numT = maxT/deltaT;
    numX = maxX/deltaX;

    fl = fl_;

    fieldInit();

    // Print();

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

    fl = obj.fl;

}
    
Field::~Field()
{

}