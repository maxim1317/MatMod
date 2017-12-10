#include "fluid.h"

void init(double deltaT, double deltaX, double maxT, double maxX)
{
    Field fluid(deltaT, deltaX, maxT, maxX);
    Field diff = fluid;

            // printf("!");
    for (int i = 1; i < fluid.numT; ++i)
    {
        for (int j = 1; j < fluid.numX-1; ++j)
        {
            fluid.field[j][i] = ODE(fluid, j, i);
        }
    }
    // printf("---------------------------------------------------------------------> time\n");
    // fluid.Print();
    
    fluid.Export("plots/after.txt");
    Field before(deltaT, deltaX, maxT, maxX);
    before.Export("plots/before.txt");
    for (int i = 0; i < fluid.numT; ++i)
    {
        for (int j = 0; j < fluid.numX; ++j)
        {
            diff.field[j][i] = (fluid.field[j][i] - before.field[j][i]);
        }
    }
    diff.Export("plots/diff.txt");
    char* title = (char*)"Approximate";
    char* to = (char*)"plots/approx.gnu";
    char* file = (char*)"plots/after.txt";
    GenerateGNU(fluid, title, to, file);
    title = (char*)"Accurate";
    to = (char*)"plots/accur.gnu";
    file = (char*)"plots/before.txt";
    GenerateGNU(before, title, to, file);
    fluid.Print(diff);
}

double ODE(Field &f, int x, int t)
{
    return (f.field[x-1][t-1]-f.field[x+1][t-1])*f.deltaT/(2*f.deltaX)+f.field[x][t-1];
}
