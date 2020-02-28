#include<stdio.h>
#include "9.4header.h"

// 显示菜单，并返回操作选项
int menu(void)
{
    int ret, status;
    printf("\n%s%s\n", STAR, STAR);
    printf("Please enter the option of the desired hotel:\n");
    printf("1.Ximalay Hotel\t\t2.Hiberton Hotel\n");
    printf("3.LA Hotel\t\t4.Seven Eleven Hotel\n");
    printf("5.Quit\n");
    // 处理异常输入
    while((ret = scanf("%d", &status))!=1 || (status >5 || status <1))
    {
        if(ret != 1)  // 处理非整数
        {
            scanf("%*s");
        }
        printf("Please enter an integer from 1 to 5\n");
    }

    // printf("ret = %d, status = %d\n", ret, status);
    return status;
    printf("%s%s\n", STAR, STAR);
}

// 获取入住天数
int getNights(void)
{
    int nights;
    printf("How many nights are needed?\n");
    while(scanf("%d", &nights) !=1)
    {
        scanf("%*s");
        printf("Please enter an integer!\n");
    }
    printf("nights = %d\n", nights);
    return nights;
}

// 显示入住酒店每天需要支付的金额
void showPrice(double rate, int nights)
{
    double totalBill = 0;
    double factor = 1.0;
    for(int i = 0; i<nights;i++)
    {
        totalBill += rate*factor;
        factor *= DISCOUNT;
    }
    printf("The total cost will be $%.2f. \n", totalBill);
}