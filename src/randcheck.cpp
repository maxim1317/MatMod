#include "headers/randcheck.h"

int main(int argc, char const *argv[])
{
    long long amount = 100000;
    int m = 5;

    std::string randfile = "rands/rand_derive.rand";

    int option = GetOption(argc, argv);
    if (option)
        randfile = RandGen(std::pow(2, 32), 3141592653, 1, 0, amount, "derive");    
    
    FrequencyCriteria(amount, randfile);
    PairCriteria(amount, randfile);
    SeriesCriteria(amount, m, randfile);
    PokerCriteria(amount, randfile);    


    std::cout<<std::endl;
    return 0;
}