#include "headers/randcheck.h"

int main(int argc, char const *argv[])
{
    // printf("%f\n", ChiGen(0.95, 4));
    long long amount = 100000;
    std::string test = RandGen(std::pow(2, 32), 3141592653, 1, 0, amount, "test");
    // printf("%s\n", test.c_str());
    bool isok = FrequencyCriteria(amount, test);
    if (isok)
        printf("kaef\n");
    else
        printf("shit happened\n");
    return 0;
}