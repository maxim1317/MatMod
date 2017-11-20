#ifndef __RANDGEN_HPP__
#define __RANDGEN_HPP__
#endif

std::string RandGen(long long m, long a, int c, int x0, long long amount, std::string filename)
{
    FILE *out;
    std::string dir = "rands/";
    std::string ext = ".txt";
    filename = dir + "rand" + "_" + filename + ext;
    out = fopen(filename.c_str(), "w");

    long long cur, prev;

    prev = x0;
    fprintf(out, "%lld\n", prev);

    for (long long i = 0; i < amount; ++i)
    {
        cur = (a * prev + c) % m;
        fprintf(out, "%lld\n", cur);
        prev = cur;
    }

    fclose(out);
    return filename;
}