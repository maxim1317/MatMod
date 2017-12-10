#ifndef __MISC_CPP__
#define __MISC_CPP__

#include "cookie.h"

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
        int bg = code % 10;
        res += std::to_string(bold) + ";";
        res += std::to_string(fg+30) + ";";
        res += std::to_string(49-bg) + "m";

        return res.c_str();
    }
    return "";
}

void consolePrint (long double cur_time, long double time, long double temp, long double tea_temp)
{
    int color, clr_cookie;
    if (temp < 1.0*tea_temp/2)
        color = 120;
    else if ((temp > 2.0*tea_temp/3))
        color = 110;
    else
        color = 130;

    if (cur_time < 1.0*time/2)
        clr_cookie = 120;
    else if ((cur_time > 5.0*time/6))
        clr_cookie = 110;
    else
        clr_cookie = 130;



    std::string bsp(46+37, '\b');
    printf("%s", bsp.c_str());
    int position = 46*cur_time/time;

    // std::string pre(position, ' ');
    // std::string post(25 - position-1, ' ');
    std::string pre(23, ' ');
    std::string post(23, ' ');

    if (position < 23)
        pre[position] = '#';
    else
        post[position-23] = '#'; 

    printf("%s", conColor(130));
    printf("|");
    printf("%s", conColor(0));

    for (int i = 0; i < pre.size(); ++i)
    {
        if (pre[i] == '#')
        {
            printf("%s", conColor(clr_cookie));
            if (i % 4 == 0)
                printf("/");
            else if (i % 4 == 1)
                printf("\\");
            else if (i % 4 == 2)
                printf("#");
            else 
                printf("-");
            printf("%s", conColor(0));
        }
        else
            printf("%s", " ");
    }

    printf("%s", conColor(160));
    printf("[");
    printf("%s", conColor(0));

    clr_cookie += 5;
    for (int i = 0; i < post.size(); ++i)
    {
        if (post[i] == '#')
        {
            printf("%s", conColor(clr_cookie));
                        if (i % 4 == 0)
                printf("\\");
            else if (i % 4 == 1)
                printf("/");
            else if (i % 4 == 2)
                printf("#");
            else 
                printf("-");
            printf("%s", conColor(0));
        }
        else
        {
            printf("%s", conColor(5));
            printf("%s", " ");
            printf("%s", conColor(0));
        }
    }

    printf("%s", conColor(160));
    printf("]");
    printf("%s", conColor(0));

    printf("%s", conColor(130));
    printf("| ");
    printf("%s", conColor(0));
    
    printf("%s", conColor(160));    
    printf("%6.3Lf", cur_time);
    printf("%s", conColor(0));
    
    printf("%s", conColor(130));
    printf(" | ");
    printf("%s", conColor(0));
    
    printf("%s", conColor(color));
    printf("%10.7Lf", temp);
    printf("%s", conColor(0));

    printf("%s", conColor(130));
    printf(" |");
    printf("%s", conColor(0));
     
    usleep(time/10*300);    
}


#endif