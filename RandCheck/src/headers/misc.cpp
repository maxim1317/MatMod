#ifndef __MISC_CPP__
#define __MISC_CPP__

#include "randcheck.h"

int GetOption(int argc, char const *argv[])
{
    int option = 0;

    if (argc > 1)
    {
        if (argv[1][1] == 'n')
            option = 1;
    }

    return option;
}

const char* conColor (int code)
{
    int val = 0;
    if (!val)
    {
        std::string res;
        if (code == 0)
        {   
            res = "\e[39;49m";
            return res.c_str();
        }
        res = "\033[";
        int bold = code/ 100;
        int fg = (code / 10) % 10;
        // int bg = code % 10;
        res += std::to_string(bold) + ";";
        res += std::to_string(fg+30) + ";";
        res += std::to_string(49) + "m";

        return res.c_str();
    }
    return "";
}
#endif