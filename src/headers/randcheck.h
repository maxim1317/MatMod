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

// Rand(m, a, c, X0, amount, filename) = filename
std::string RandGen(long long, long, int, int, long long, std::string);

double ChiGen(double, int);

bool FrequencyCriteria(long, long, std::string);

#include "chigen.hpp"
#include "randgen.hpp"
#include "crit_freq.hpp"