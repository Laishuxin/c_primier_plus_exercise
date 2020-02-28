#include <stdio.h>
#include <stdlib.h>

int g_iUnits = 0;

void change_units(void);
void code1211(void)
{
    // 这里只是声明要用到全局变量。可以删去
    // extern int g_iUnits;
    // 而这里是局部变量，(与全局变量同名，)，修改改变量不会影响全局变量
    int g_iUnits = 0;
    printf("1. g_iUnits(in code1211) : %d \n", g_iUnits);
    printf("please enter another number to change g_iUnits : ");
    scanf("%d", &g_iUnits);
    printf("2. g_iUnits(in code1211) : %d \n", g_iUnits);
    printf("call change_units function to change g_iUnits!\n");
    change_units();
    printf("3. g_iUnits(in code1211) : %d \n", g_iUnits);
}

void code123(void)
{
    // 利用malloc动态管理内存
    int n = 10;
    double *dpArr;
    dpArr = (double *)malloc(n * sizeof(double));
    printf("push data...\n");
    for (size_t i = 0; i < n; i++)
    {
        dpArr[i] = (double)i * 10;
    }
    printf("dpArr : ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%.2lf ", dpArr[i]);
    }
    printf("\n");
    free(dpArr);
    printf("Done!\n");
}

int main(int argc, char const *argv[])
{
    //code1211();
    //printf("5. g_iUnits(in main) : %d \n", g_iUnits);
    code123();
    system("pause");
    return 0;
}

void change_units(void)
{
    printf("Now, we're in change_units function, please enter a number to change g_iUnits :");
    scanf("%d", &g_iUnits);
    printf("4. g_iUnits(in change_units) : %d \n", g_iUnits);
}