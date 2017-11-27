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
#include <algorithm>

int d=10;

int GetOption(int, char const*[]);

// Rand(m, a, c, X0, amount, filename) = filename
std::string RandGen(long long, long, int, int, long long, std::string);

double ChiGen(double, int);

bool FrequencyCriteria(long long, std::string);
bool PairCriteria(long long, std::string);
bool SeriesCriteria(long long, int, std::string);
bool PokerCriteria(long long, std::string);

const char* conColor (int);

#include "chigen.hpp"
#include "randgen.hpp"

#include "crit_freq.hpp"
#include "crit_pair.hpp"
#include "crit_series.hpp"
#include "crit_poker.hpp"

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

const char* conColor (int code)
{
    int val = 0;
    if (!val)
    {
        std::string res;
        if (code == 0)
        {   
            res = "\e[39;49m";
            return res.c_str();
        }
        res = "\033[";
        int bold = code/ 100;
        int fg = (code / 10) % 10;
        int bg = code % 10;
        res += std::to_string(bold) + ";";
        res += std::to_string(fg+30) + ";";
        res += std::to_string(49) + "m";

        return res.c_str();
    }
    return "";
}