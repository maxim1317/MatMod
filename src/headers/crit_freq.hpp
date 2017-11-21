#ifndef __CRIT_FREQ_HPP__
#define __CRIT_FREQ_HPP__
#endif

bool FrequencyCriteria(long long amount, std::string inpfile)
{
    std::ifstream in(inpfile.c_str(),std::ios::in);

    std::vector<int> V;
    V.assign(d, 0);

    double buf;
    int alpha;

    int i = 0;
    while (i < amount && in >> buf ) {
        alpha = abs(static_cast<int>(buf*10))%10;
        V[alpha]++;
        i++;
    }
    for (int i = 0; i < d; ++i)
    {
        double stat = (double)V[i]/amount;
        printf("%f\n", stat);
    }

    double stat = 0;

    for (int i = 0; i < d; ++i)
    {
        stat += (double)std::pow(V[i]-amount*1.0/d, 2)/(amount*1.0/d);
    }

    printf("stat = %f\n", stat);

    double chistat = ChiGen(0.95, d-1);

    printf("chi = %f\n", chistat);

    in.close();
    return true;
    in.close();
    return false;
}