#ifndef __CRIT_PAIR_HPP__
#define __CRIT_PAIR_HPP__

#include "randcheck.h"

bool PairCriteria(int d, long long amount, std::string inpfile)
{
    std::ifstream in(inpfile.c_str(),std::ios::in);

    std::vector<long long> V;
    V.assign(d*d, 0);

    double buf;
    int alpha, beta;

    int i = 0;
    while (i < amount/2 && in >> buf ) {
        alpha = abs(static_cast<int>(buf*10))%10;
        in>>buf;
        beta = abs(static_cast<int>(buf*10))%10;
        V[10*alpha+beta]++;
        i++;
    } 
    // for (int i = 0; i < d*d; ++i)
    // {
    //     double stat = (double)V[i]/amount;
    //     printf("V[%2d]/amount = %f\n", i, stat);
    // }

    double stat = 0;

    for (int i = 0; i < d*d; ++i)
    {
        stat += (double)std::pow(V[i]-amount/2*1.0/(d*d), 2)/(amount/2*1.0/(d*d));
    }

    // printf("stat = %f\n", stat);

    double chistat = ChiGen(0.95, d*d-1);

    // printf("chi = %f\n", chistat);

    in.close();

    // printf("%s", conColor(0));

    printf("  Pair      criteria - ");
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
        printf("%s]\n", conColor(0));
        return false;
    }
}
#endif