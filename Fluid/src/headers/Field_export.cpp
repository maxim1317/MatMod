#include "fluid.h"

void Field::Print()
{
    for (int i = numX-1; i >= 0; --i)
    {
        for (int j = 0; j < numT; ++j)
        {
            printf("%6.2lf ", field[j][i]);
        }
        printf("\n");
    }
}

void Field::Export()
{

}