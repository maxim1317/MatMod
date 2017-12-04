#ifndef __CRIT_ALL_HPP__
#define __CRIT_ALL_HPP__

#include "randcheck.h"

bool AllCriteria(int d, long long amount, std::string inpfile)
{
    bool flag = 1;
    flag *= FrequencyCriteria(d, amount, inpfile);
    flag *= PairCriteria(d, amount, inpfile);
    flag *= SeriesCriteria(d, amount, inpfile);
    flag *= PokerCriteria(d, amount, inpfile);

    return flag;
}

#endif