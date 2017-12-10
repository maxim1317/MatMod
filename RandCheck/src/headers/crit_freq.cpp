#ifndef __CRIT_FREQ_HPP__
#define __CRIT_FREQ_HPP__

#include "randcheck.h"

bool FrequencyCriteria(int d, long long amount, std::string inpfile)
{
    std::ifstream in(inpfile.c_str(),std::ios::in);

    std::vector<long long> V;
    V.assign(d, 0);

    double buf;
    int alpha;

    int i = 0;
    while (i < amount && in >> buf ) {
        alpha = abs(static_cast<int>(buf*10))%10;
        V[alpha]++;
        i++;
    }
    // for (int i = 0; i < d; ++i)
    // {
    //     double stat = (double)V[i]/amount;
    //     printf("V[%d]/amount = %f\n", i, stat);
    // }

    double stat = 0;

    for (int i = 0; i < d; ++i)
    {
        stat += (double)std::pow(V[i]-amount*1.0/d, 2)/(amount*1.0/d);
    }

    // printf("stat = %f\n", stat);

    double chistat = ChiGen(0.95, d-1);

    // printf("chi = %f\n", chistat);

    in.close();

    printf("\n");
    printf("%s", conColor(120));
    printf("%s", conColor(0));

    printf("  Frequency criteria - ");
    if (stat < chistat)
    {
        printf("[%s", conColor(120));
        printf("   OK   ");
        printf("%s]\n", conColor(0));
        return true;
    }
    else
    {
        printf("[%s", conColor(110));
        printf(" NOT OK ");
        printf("%s]", conColor(0));
        printf("  | Statistics = %.2lf V Chi Squared = %.2lf |\n", stat, chistat);
        return false;
    }
}
#endif