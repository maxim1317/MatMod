#ifndef __CRIT_POKER_HPP__
#define __CRIT_POKER_HPP__

#include "randcheck.h"

int Sterling (int n, int k){
    if (n == 0 || n == k) return 1;
    if (k == 0) return 0;
    return Sterling(n - 1, k - 1) + k * Sterling(n - 1, k);
}

bool PokerCriteria(int d, long long amount, std::string inpfile)
{
    std::ifstream in(inpfile.c_str(), std::ios::in);
    // printf("%s\n",inpfile.c_str());

    std::vector<long long> V, beta;
    std::vector<double> p;
    V.assign(5, 0);
    beta.assign(d, 0);

    double buf;
    int alpha = 0;
    long long count = 0;


    long long i = 0;
    while (i < amount/5) {
        count = 0;
        beta.clear();
        beta.assign(d, 0);
        for (long long j = 0; j < 5; ++j)
        {
            in>>buf;            
            alpha = abs(static_cast<int>(buf*10))%10;
            beta[alpha]++;            
        }
        // printf("beta = ");
        // for (int j = 0; j < beta.size(); ++j)
        // {
        //     printf("%d ", beta[j]);
        // }
        // printf("\n");
        for (long long j = 0; j < beta.size(); ++j)
        {
            if (beta[j])
                count++;
        }
        V[count-1]++;
        i++;
    }
    // for (int i = 0; i < V.size(); ++i)
    // {
    //     double stat = (double)V[i]/amount;
    //     printf("V[%2d]/amount = %f\n", i, stat);
    // }
    int frac = 1;
    for (long long i = 1; i <= V.size(); ++i)
    {
        frac *= d - i + 1;
        p.push_back(frac*1.0/std::pow(d, 5) * Sterling(5, i));
    }

    double stat = 0;

    for (long long i = 0; i < V.size(); ++i)
    {
        stat += (double)std::pow(V[i]-amount/5*p[i], 2)/(amount/5*p[i]);
    }

    // printf("stat = %f\n", stat);

    double chistat = ChiGen(0.95, 4);

    // printf("chi = %f\n", chistat);

    in.close();

    printf("%s", conColor(0));

    printf("  Poker     criteria - ");
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