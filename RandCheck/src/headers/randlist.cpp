#ifndef __RANDLIST_HPP__
#define __RANDLIST_HPP__

#include "randcheck.h"

class Rands
{
public:
    int d;
    long long m;
    long long a;
    long long b;
    long long y0;
    long long amount;
    std::string name;
    Rands(std::string, long long, long long, long long, long long, long long, int);
    ~Rands(){};
     
}; 

Rands::Rands(std::string name_, long long m_, long long a_, long long b_, long long y0_, long long amount_, int d_)
{
    name = name_;
    m = m_;
    a = a_;
    b = b_;
    y0 = y0_;
    amount = amount_;
    d = d_;
}

void CheckAll(long long amount, int d, int option)
{
//_|Class_Name_______|_Name________|_m__________________|_a_______________|_b_________|_y0___________________________|_amount|_d|
    Rands ANSIC      ("ANSIC"      , std::pow(2, 31)    , 1103515245      , 12345     , 12345                        , amount, d);
    Rands MINSTD     ("MINSTD"     , std::pow(2, 31)-1  , 16807           , 0         , 1                            , amount, d);
    Rands RANDU      ("RANDU"      , std::pow(2, 31)    , 65539           , 0         , 1                            , amount, d);
    Rands SIMSCRIPT  ("SIMSCRIPT"  , std::pow(2, 31)-1  , 630360016       , 0         , 1                            , amount, d);
    Rands BCSLIB     ("BCSLIB"     , std::pow(2, 35)    , std::pow(5, 15) , 7261067085, 0                            , amount, d);
    Rands BCPL       ("BCPL"       , std::pow(2, 32)    , 2147001325      , 715136305 , 0                            , amount, d);
    Rands URN12      ("URN12"      , std::pow(2, 31)    , 452807053       , 0         , 1                            , amount, d);
    Rands APPLE      ("APPLE"      , std::pow(2, 35)    , std::pow(5, 13) , 0         , 1                            , amount, d);
    Rands Super_Duper("Super_Duper", std::pow(2, 32)    , 69069           , 0         , 1                            , amount, d);
    Rands NAG        ("NAG"        , std::pow(2, 59)    , std::pow(13, 13), 0         , 123456789*(std::pow(2, 32)+1), amount, d);
    Rands DRAND48    ("DRAND48"    , std::pow(2, 48)    , 25214903917     , 11        , 0                            , amount, d);
    Rands CRAY       ("CRAY"       , std::pow(2, 48)    , 44485709377909  , 0         , 1                            , amount, d);
    Rands MAPLE      ("MAPLE"      , std::pow(10, 12)-11, 427419669081    , 0         , 1                            , amount, d);
    Rands DERIVE     ("DERIVE"     , std::pow(2, 32)    , 3141592653      , 1         , 0                            , amount, d);

    std::vector<Rands> r;

    r.push_back(ANSIC);
    r.push_back(MINSTD);
    r.push_back(RANDU);
    r.push_back(SIMSCRIPT);
    r.push_back(BCSLIB);
    r.push_back(BCPL);
    r.push_back(URN12);
    r.push_back(APPLE);
    r.push_back(Super_Duper);
    r.push_back(NAG);
    r.push_back(DRAND48);
    r.push_back(CRAY);
    r.push_back(MAPLE);
    r.push_back(DERIVE);

    std::string randfile, buf;

    for (int i = 0; i < r.size(); ++i)
    {
        buf = r[i].name;
        std::string dir = "rands/";
        std::string ext = ".rand";
        std::string randfile = dir + "rand" + "_" + r[i].name + ext;

        if (option)
            randfile = RandGen(r[i].d, r[i].m, r[i].a, r[i].b, r[i].y0, r[i].amount, buf);
      
        // std::cout << buf << ":\n";
        printf("");
        printf("%s", conColor(130));
        printf("%s:", buf.c_str());
        printf("%s\n", conColor(0));
        AllCriteria(r[i].d, r[i].amount, randfile);
        printf("\n");
    }  
}

#endif
