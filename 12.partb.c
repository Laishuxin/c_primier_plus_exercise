#include <stdio.h>

extern int g_iCount;
static int g_iTotal = 0;

void accumulate(int k);
void accumulate(int k)
{
    static int iSubtotal = 0;
    if (k <= 0)
    {
        printf("loop cycle : %d\n", g_iCount);
        printf("iSubtotal : %d, g_iTotal : %d \n", iSubtotal, g_iTotal);
        iSubtotal = 0;
    }
    else
    {
        iSubtotal += k;
        g_iTotal += k;
    }
}