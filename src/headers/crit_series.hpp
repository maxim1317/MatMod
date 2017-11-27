#ifndef __CRIT_SERIES_HPP__
#define __CRIT_SERIES_HPP__
#endif

bool SeriesCriteria(long long amount, int m, std::string inpfile)
{
    std::ifstream in(inpfile.c_str(),std::ios::in);

    long long count=0;
    std::vector<int> V;
    std::vector<double> p;

    for (int i = 0; i < m; ++i)
    {
        // printf("10^i = %lf\n", std::pow(10, i));
        p.push_back(9*1.0/std::pow(10, i+1));
    }
    p.push_back(1/std::pow(10, m));
    
    V.assign(m+1, 0);

    double buf;
    int alpha, beta;

    int l = 0;
    int i = 0;

    while (i < amount/2 && in >> buf ) {
        alpha = abs(static_cast<int>(buf*10))%10;
        in>>buf;
        beta = abs(static_cast<int>(buf*10))%10;
        
        if (alpha != beta)
        {
            V[l]++;
            l = 0;
        }
        else
            l = std::min(l + 1, m + 1);

        i++;
    }
    if (l > 0)
        V[l]++;
    for (int i = 0; i < V.size(); ++i)
    {
        double stat = (double)V[i]/amount;
        // printf("V[%2d]/amount = %f\n", i, stat);
        // printf("p[%2d] = %f\n", i, p[i]);

        count += V[i];
    }
    // printf("count = %lld\n", count);

    double stat = 0;

    for (int i = 0; i < V.size(); ++i)
    {
        stat += (double)std::pow(V[i]-count*p[i], 2)/(count*p[i]);
    }


    // printf("stat = %f\n", stat);

    double chistat = ChiGen(0.95, m);

    // printf("chi = %f\n", chistat);

    in.close();

    printf("%s", conColor(0));

    printf("  Series    criteria - ");
    if (stat < chistat)
    {
        printf("[%s", conColor(120));
        printf(" OK ");
        printf("%s]\n", conColor(0));
        return true;
    }
    else
    {
        printf("[%s", conColor(110));
        printf(" NOT OK ");
        printf("%s]\n", conColor(0));
        return false;
    }
}