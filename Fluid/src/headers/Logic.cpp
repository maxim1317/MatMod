#include "fluid.h"

void init(double deltaT, double deltaX, double maxT, double maxX, bool flag)
{
    Field fluid(deltaT, deltaX, maxT, maxX, flag);
    Field diff = fluid;

            // printf("!");
    for (int i = 1; i <= fluid.numT/2; ++i)
    {
        for (int j = 1; j < fluid.numX-1; ++j)
        {
            fluid.field[j][i] = ODE(fluid, j, i, 1);
        }
    }
    for (int i = fluid.numT-2; i >= fluid.numT/2; --i)
    {
        for (int j = 1; j < fluid.numX-1; ++j)
        {
            fluid.field[j][i] = ODE(fluid, j, i, 2);
        }
    }
    // printf("---------------------------------------------------------------------> time\n");
    // fluid.Print();
    
    fluid.Export("plots/after.txt");
    Field before(deltaT, deltaX, maxT, maxX, flag);
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
    printf("");
    printf("%s", conColor(130));
    printf("                                Accurate                                ");
    printf("%s\n", conColor(0));
    before.Print(diff);
    printf("\n");
    printf("");
    printf("%s", conColor(130));
    printf("                                 Approx                                 ");
    printf("%s\n", conColor(0));
    fluid.Print(diff);
}

double ODE(Field &f, int x, int t, int opt)
{
    if (t!=1 && t!=f.field[x].size()-2)
        opt+=2;

    if (!f.fl)
        return (f.field[x-1][t-1]-f.field[x+1][t-1])*f.deltaT/(2*f.deltaX)+f.field[x][t-1];

    if (opt == 1)
        return ((f.field[x-1][t-1]-2*f.field[x][t-1]+f.field[x+1][t-1])/(f.deltaX*f.deltaX))*f.deltaT+f.field[x][t-1];   
    else if (opt == 2)
        return ((-f.field[x-1][t+1]+2*f.field[x][t+1]-f.field[x+1][t+1])/(f.deltaX*f.deltaX))*f.deltaT+f.field[x][t+1];
    else if (opt == 3){
        double a = 2*f.deltaT*(f.field[x-1][t-1]-2*f.field[x][t-1]+f.field[x+1][t-1])/(f.deltaX*f.deltaX)+f.field[x][t-2];
        double b = ((f.field[x-1][t-1]-2*f.field[x][t-1]+f.field[x+1][t-1])/(f.deltaX*f.deltaX))*f.deltaT+f.field[x][t-1];   
        return (a+b)/2;
    }
    else if (opt == 4){
        double a = 2*f.deltaT*((-f.field[x-1][t+1]+2*f.field[x][t+1]-f.field[x+1][t+1])/(f.deltaX*f.deltaX))+f.field[x][t+2];;
        double b = ((-f.field[x-1][t+1]+2*f.field[x][t+1]-f.field[x+1][t+1])/(f.deltaX*f.deltaX))*f.deltaT+f.field[x][t+1];;
        return (a+b)/2;
    }

    else return -1;
}
