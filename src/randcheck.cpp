#include "headers/randcheck.h"

int main(int argc, char const *argv[])
{
    long long amount = 100000;
    int d = 10;

    // std::string randfile = "rands/rand_derive.rand";

    int option = GetOption(argc, argv);
   CheckAll(amount, d, option);
    // if (option)
    //     randfile = RandGen(d, std::pow(2, 32), 3141592653, 1, 0, amount, "derive");    
    
    // FrequencyCriteria(d, amount, randfile);
    // PairCriteria(d, amount, randfile);
    // SeriesCriteria(d, amount, m, randfile);
    // PokerCriteria(d, amount, randfile);    


    std::cout<<std::endl;
    return 0;
}