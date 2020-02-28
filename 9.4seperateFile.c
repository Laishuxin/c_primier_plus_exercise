#include<stdio.h>
#include "9.4header.h"

int main(int argc, char const *argv[])
{
    int nights;
    double rate;
    int status;
    while((status = menu() ) != QUIT)
    {
        switch (status)
        {
        case 1:
            rate = HOTEL1;
            break;
        case 2:
            rate = HOTEL2;
            break;
        case 3:
            rate = HOTEL3;
            break;
        case 4:
            rate = HOTEL4;
            break;          
        default:
            rate = 0.0;
            printf("The program has some error\n");
            break;
        }
        nights = getNights();
        showPrice(rate, nights);
        printf("Done!\n");
    }
    printf("See you next time!\n");
    return 0;
}
