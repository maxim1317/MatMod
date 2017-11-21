#include "headers/randcheck.h"

int main(int argc, char const *argv[])
{
    long long amount = 100000;

    std::string test = "rands/rand_derive.rand";

    int option = GetOption(argc, argv);
    if (option)
        test = RandGen(std::pow(2, 32), 3141592653, 1, 0, amount, "derive");    
    
    bool isok = FrequencyCriteria(amount, test);
    if (isok)
        printf("kaef\n");
    else
        printf("shit happened\n");
    return 0;
}