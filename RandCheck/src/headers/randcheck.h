#ifndef __RANDCHECK_H__
#define __RANDCHECK_H__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>

int GetOption(int, char const*[]);

// Rand(m, a, c, X0, amount, filename) = filename
std::string RandGen(int, long long, long long, long long, long long, long long, std::string);
void CheckAll(long long, int, int);

double ChiGen(double, int);

bool AllCriteria      (int, long long, std::string);
bool FrequencyCriteria(int, long long, std::string);
bool PairCriteria     (int, long long, std::string);
bool SeriesCriteria   (int, long long, std::string);
bool PokerCriteria    (int, long long, std::string);

const char* conColor (int);

// #include "chigen.hpp"
// #include "randgen.hpp"

// #include "crit_freq.hpp"
// #include "crit_pair.hpp"
// #include "crit_series.hpp"
// #include "crit_poker.hpp"


#endif 