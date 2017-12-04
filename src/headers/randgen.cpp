#ifndef __RANDGEN_HPP__
#define __RANDGEN_HPP__

#include "randcheck.h"

std::string RandGen(int d, long long m, long long a, long long c, long long x0, long long amount, std::string filename)
{
    FILE *out;
    std::string ret;
    std::string dir = "rands/";
    std::string ext = ".rand";
    ret = dir + "rand" + "_" + filename + ext;
    out = fopen(ret.c_str(), "w");

    if (!out)
    {
        printf("Broken lines, broken strings\nBroken threads, broken springs\nBroken idols, broken heads\nPeople sleeping in broken beds\nAin't no use jiving\nAin't no use joking\nEVERYTHING IS BROKEN\n\n\n\nSeriously though, this error should never be shown\nIf you are a user, god speed\nẺ̵͎͓̕x̸̛̜̯͑i̴̳̇̕t̸̻̦̊̃ ̵͈͈̂w̸͔̍h̵̭͌ͅĩ̷̠̽l̷̻̠͌̒ë̴̻́ ̸̺̮̒̾y̵͉̌ȯ̷͉̻ü̴͍̟ ̸͓̬̂͋c̶̛̖ȧ̵̀͜n̵̓̒͜\n");
    }

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
    return ret;
}
#endif