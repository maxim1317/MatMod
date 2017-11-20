#ifndef __CHIGEN_HPP__
#define __CHIGEN_HPP__
#endif

double a[] = { 1.0000886 ,  0.4713941  , 0.0001348028, -0.008553069,  0.00312558 , -0.0008426812,  0.00009780499};
double b[] = {-0.2237368 ,  0.02607083 , 0.01128186  , -0.01153761 ,  0.005169654,  0.00253001  , -0.001450117  };
double c[] = {-0.01513904, -0.008986007, 0.02277679  , -0.01323293 , -0.006950356,  0.001060438 ,  0.001565326  };

double ChiGen(double alpha, int nu)
{
    double d;

    if (alpha < 0.5)
    {
        d = -2.0637*std::pow((std::log(1.0/alpha)-0.16), 0.4274) + 1.5774;
    }
    else
    {
        d =  2.0637*std::pow((std::log(1.0/(1-alpha))-0.16), 0.4274) - 1.5774;
    }

    double sum = 0;

    for (int j = 0; j < 7; ++j)
    {
        sum += std::pow(nu, -(1.0*j)/2) * std::pow(d, j) * (a[j] + b[j]/nu + c[j]/(nu*nu));
    }

    return nu * std::pow(sum, 3.0);
}