#include "headers/randcheck.h"

int main(int argc, char const *argv[])
{
    printf("%f\n", ChiGen(0.95, 4));
    RandGen(std::pow(2, 32), 3141592653, 1, 0, 10000,"test");
    return 0;
}