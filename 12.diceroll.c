/*************************************************************************
File name : 12.diceroll.c
Its function : 掷骰子模拟程序
Create time : 2020.2.27
Author : Lsx
*************************************************************************/
#include "12.diceroll.h"
#include <stdio.h>
#include <stdlib.h>

// =======================================================================
int g_iRollCount = 0;

/*************************************************************************
Description
-----------
掷骰子，产生随机数(1 - iSides)，
使用静态函数，指定其作用域为当前文件

Parameters
-----------
iSides : int
    骰子的面数

Returns
-------
产生的随机数

*************************************************************************/
static int rollem(int iSides)
{
    int iRoll;
    iRoll = rand() % iSides + 1;
    // 每掷骰子一次，记录下来
    ++g_iRollCount;
    return iRoll;
}

/*************************************************************************
Description
-----------
用于多个掷多个(iDice)骰子

Parameters
-----------
iDice : int
    骰子的个数
iSides : 骰子的面数
Returns
-------
掷出的骰子的总点数,
如果所给的骰子面数，骰子的个数达不到要求，则返回特定的值
*************************************************************************/
int roll_n_dice(int iDice, int iSides)
{
    int iTotal = 0;
    if (iSides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (iDice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }
    for (size_t d = 0; d < iDice; d++)
    {
        iTotal += rollem(iSides);
    }
    return iTotal;
}
