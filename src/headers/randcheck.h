#ifndef __RANDCHECK_H__
#define __RANDCHECK_H__
#endif

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cmath>

int d=10;

int GetOption(int, char const*[]);

// Rand(m, a, c, X0, amount, filename) = filename
std::string RandGen(long long, long, int, int, long long, std::string);

double ChiGen(double, int);

bool FrequencyCriteria(long long, std::string);
bool PairCriteria(long long, std::string);


#include "chigen.hpp"
#include "randgen.hpp"
#include "crit_freq.hpp"
#include "crit_pair.hpp"

int GetOption(int argc, char const *argv[])
{
    int option = 0;

    if (argc > 1)
    {
        if (argv[1][1] == 'n')
            option = 1;
    }

    return option;
}