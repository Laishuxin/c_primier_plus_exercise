/*************************************************************************
File name : manydice.c
Its function : 多次掷骰子
Create time : 2020.2.27
Author : Lsx
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12.diceroll.h"
// =======================================================================

int main(void)
{
    int iDice, iRoll;
    int iSides;
    int iStatus;
    srand((unsigned int)time(NULL));
    printf("Enter the number of sides per die(0 to quit):");
    while ((scanf("%d", &iSides) == 1) && iSides > 0)
    {
        printf("How many dice?\n");
        if ((iStatus = scanf("%d", &iDice)) != 1)
        {
            if (iStatus == EOF)
            {
                break;
            }
            else
            {
                printf("You should have entered an integer.\n");
                printf("Let's begin again.\n");
                while (getchar() != '\n')
                    continue;
                printf("Houw many sides? Enter 0 to stop.\n");
                continue;
            }
        }
        iRoll = roll_n_dice(iDice, iSides);
        printf("You have rolled a %d using %d %d-sided dice.\n", iRoll, iDice, iSides);
        printf("Houw many sides? Enter 0 to stop.\n");
    }
    printf("The rollem() function was called %d times.\n", g_iRollCount);
    printf("Done!!!!!!!!!!!!!!!\n");

    return 0;
}