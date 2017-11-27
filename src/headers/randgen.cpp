#ifndef __RANDGEN_HPP__
#define __RANDGEN_HPP__

#include "randcheck.h"

std::string RandGen(int d, long long m, long long a, long long c, long long x0, long long amount, std::string filename)
{
    FILE *out;
    std::string dir = "rands/";
    std::string ext = ".rand";
    filename = dir + "rand" + "_" + filename + ext;
    out = fopen(filename.c_str(), "w");

    long long cur, prev;

    prev = x0;
    fprintf(out, "%lld\n", prev/d);

    for (long long i = 0; i < amount; ++i)
    {
        cur = (a * prev + c) % m;
        double res = (double)cur/m;
        fprintf(out, "%f\n", res);
        prev = cur;
    }

    fclose(out);
    return filename;
}
#endif