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

void Field::Export(const char *s)
{
    FILE *out;
    out = fopen(s, "w");
    if (!out)
    {
        printf("Broken lines, broken strings\nBroken threads, broken springs\nBroken idols, broken heads\nPeople sleeping in broken beds\nAin't no use jiving\nAin't no use joking\nEVERYTHING IS BROKEN\n\n\n\nSeriously though, this error shoulong double never be shown\nIf you are a user, god speed\nẺ̵͎͓̕x̸̛̜̯͑i̴̳̇̕t̸̻̦̊̃ ̵͈͈̂w̸͔̍h̵̭͌ͅĩ̷̠̽l̷̻̠͌̒ë̴̻́ ̸̺̮̒̾y̵͉̌ȯ̷͉̻ü̴͍̟ ̸͓̬̂͋c̶̛̖ȧ̵̀͜n̵̓̒͜\n");
    }
    for (int i = numX-1; i >= 0; --i)
    {
        for (int j = 0; j < numT; ++j)
        {

            fprintf(out, "%lf %lf %lf\n", i*deltaX, j*deltaT, field[j][i]);
        }
        // printf("\n");
    }
    fclose(out);
}

void GenerateGNU(Field f, char* title, char* to, char* file)
{
    FILE *out;
    out = fopen(to, "w");
    fprintf(out, "set title \"%s\"\n", title);
    fprintf(out, "set xlabel \"x\"\n");
    fprintf(out, "set ylabel \"time\"\n");
    fprintf(out, "set zlabel \"f(x,t);\"\n");

    fprintf(out, "set autoscale\n");

    fprintf(out, "splot \"plots/diff.txt\" u 1:2:3, ");
    fprintf(out, "\"%s\" u 1:2:3\n", file);
    fprintf(out, "set style data lines\n");
    fprintf(out, "set hidden3d\n");
    fprintf(out, "set dgrid3d %d,%d qnorm 2\n", f.numX, f.numT);
    fprintf(out, "splot \"plots/diff.txt\" u 1:2:3, ");
    fprintf(out, "\"%s\" u 1:2:3 with lines \n", file);

    fclose(out);
}