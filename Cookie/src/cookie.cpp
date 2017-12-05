#include "headers/cookie.h"
const long double eps = 0.001;
 
int main()
{
    long double cookie_temp, tea_temp, speed, t;

    FILE *out;
    std::ifstream in("input.txt",std::ios::in);
    out = fopen("tmp/output.txt", "w");
    if (!out)
    {
        printf("Broken lines, broken strings\nBroken threads, broken springs\nBroken idols, broken heads\nPeople sleeping in broken beds\nAin't no use jiving\nAin't no use joking\nEVERYTHING IS BROKEN\n\n\n\nSeriously though, this error shoulong double never be shown\nIf you are a user, god speed\nẺ̵͎͓̕x̸̛̜̯͑i̴̳̇̕t̸̻̦̊̃ ̵͈͈̂w̸͔̍h̵̭͌ͅĩ̷̠̽l̷̻̠͌̒ë̴̻́ ̸̺̮̒̾y̵͉̌ȯ̷͉̻ü̴͍̟ ̸͓̬̂͋c̶̛̖ȧ̵̀͜n̵̓̒͜\n");
    }

    in >> cookie_temp;
    in >> tea_temp;
    in >> speed;
    in >> t;
    
    long double cur_temp, prev_temp;
    prev_temp = cookie_temp;
    fprintf(out, "Time = %5.2Lf, Temperature = %9.6Lf\n", 0*eps, prev_temp);
    printf("Time = %5.2Lf, Temperature = %9.6Lf", 0*eps, prev_temp);
    for (int i = 1; i < (long double)t/eps; ++i) {
        cur_temp = speed*eps*(tea_temp - prev_temp) + prev_temp;
        prev_temp = cur_temp;
        fprintf(out, "Time = %5.2Lf, Temperature = %9.6Lf\n", i*eps, cur_temp);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

        printf("%s", conColor(0));
        printf("Time = ");
        printf("%s", conColor(160));
        printf("%5.2Lf", i*eps);
        printf("%s", conColor(0));
        printf(", Temperature = ");
        if (cur_temp < tea_temp/3)
            printf("%s", conColor(120));
        else if ((cur_temp > 2.0*tea_temp/3))
            printf("%s", conColor(110));
        else
            printf("%s", conColor(130));
        printf("%9.6Lf", cur_temp);
        printf("%s", conColor(0));
        
        usleep(600);
    }
    printf("\n");
}