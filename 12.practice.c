#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void print_int_arr(int iSize, int ipArr[iSize]);
void fill_with_random_int(int iSize, int ipArr[iSize]);
void sort_int_arr(int iSize, int ipArr[iSize], bool bAscending);
void describe_arr(int iSize, int ipArr[iSize]);
void practice5(void)
{
    // 5.编写一个程序， 生成100个1～10范围内的随机数， 并以降序排列（可
    // 以把第11章的排序算法稍加改动， 便可用于整数排序， 这里仅对整数排
    // 序） 。
    int iSize = 100;
    int ipArr[iSize];
    fill_with_random_int(iSize, ipArr);
    print_int_arr(iSize, ipArr);
    printf("----------------------------------\n");
    sort_int_arr(iSize, ipArr, false);
    print_int_arr(iSize, ipArr);
    printf("----------------------------------\n");
}

void practice6(void)
{
    // 6.编写一个程序， 生成1000个1～10范围内的随机数。 不用保存或打印
    // 这些数字， 仅打印每个数出现的次数。 用 10 个不同的种子值运行， 生成的
    // 数字出现的次数是否相同？ 可以使用本章自定义的函数或ANSI C的rand()和
    // srand()函数， 它们的格式相同。 这是一个测试特定随机数生成器随机性的方
    // 法
    int iTimes = 10;
    int iSize = 100;
    int ipArr[iSize];
    for (size_t i = 0; i < iTimes; i++)
    {
        printf("**************************************************\n");
        fill_with_random_int(iSize, ipArr);
        describe_arr(iSize, ipArr);
        sort_int_arr(iSize, ipArr, true);
        print_int_arr(iSize, ipArr);
        printf("**************************************************\n");
    }
}

void practice9(void)
{
    // 9.编写一个符合以下描述的函数。 首先， 询问用户需要输入多少个单
    // 词。 然后， 接收用户输入的单词， 并显示出来， 使用malloc()并回答第1个问
    // 题（即要输入多少个单词） ， 创建一个动态数组， 该数组内含相应的指向
    // char的指针（注意， 由于数组的每个元素都是指向char的指针， 所以用于储
    // 存malloc()返回值的指针应该是一个指向指针的指针， 且它所指向的指针指
    // 向char） 。 在读取字符串时， 该程序应该把单词读入一个临时的char数组，
    // 使用malloc()分配足够的存储空间来储存单词， 并把地址存入该指针数组
    // （该数组中每个元素都是指向 char 的指针） 。 然后， 从临时数组中把单词
    // 拷贝到动态分配的存储空间中。 因此， 有一个字符指针数组， 每个指针都指
    // 向一个对象， 该对象的大小正好能容纳被储存的特定单词。
    int iNumOfWords;
    char **cppWords; // 指向字符串数组的指针
    char cpTempWord[256];
    printf("How many words do you wish to enter?\n");
    scanf("%D", &iNumOfWords);
    cppWords = (char **)malloc(sizeof(char *) * iNumOfWords);
    printf("Now, enter %d words:\n", iNumOfWords);
    for (size_t i = 0; i < iNumOfWords; i++)
    {
        scanf("%s", cpTempWord);
        int iWordLength = strlen(cpTempWord);
        cppWords[i] = (char *)malloc(iWordLength + 1);
        strncpy(cppWords[i], cpTempWord, iWordLength + 1);
    }
    printf("Here are your words:\n");
    for (size_t i = 0; i < iNumOfWords; i++)
    {
        printf("%d : %s\n", i + 1, cppWords[i]);
    }

    // 释放内存
    for (size_t i = 0; i < iNumOfWords; i++)
    {
        if (cppWords[i] != NULL)
        {
            free(cppWords[i]);
            cppWords[i] = NULL;
        }
    }
    if (cppWords != NULL)
        free(cppWords);
}

int main(int argc, char const *argv[])
{
    //practice5();
    //practice6();
    practice9();

    system("pause");
    return 0;
}

void fill_with_random_int(int iSize, int ipArr[iSize])
{
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < iSize; i++)
    {
        ipArr[i] = rand() % 10 + 1;
    }
}

void print_int_arr(int iSize, int ipArr[iSize])
{
    for (size_t i = 0; i < iSize; i++)
    {
        printf("%3d ", ipArr[i]);
        if (i % 10 == 9)
            putchar('\n');
    }
}

void sort_int_arr(int iSize, int ipArr[iSize], bool bAscending)
{
    int iTemp;
    for (size_t i = 0; i < iSize - 1; i++)
    {
        for (size_t j = i + 1; j < iSize; j++)
        {
            // 升序排序
            if (bAscending)
            {
                if (ipArr[i] > ipArr[j])
                {
                    iTemp = ipArr[i];
                    ipArr[i] = ipArr[j];
                    ipArr[j] = iTemp;
                }
            }
            else
            {
                if (ipArr[i] < ipArr[j])
                {
                    iTemp = ipArr[i];
                    ipArr[i] = ipArr[j];
                    ipArr[j] = iTemp;
                }
            }
        }
    }
}

void describe_arr(int iSize, int ipArr[iSize])
{
    int ipTemp[10];
    for (size_t i = 0; i < 10; i++)
    {
        ipTemp[i] = 0;
    }

    for (size_t i = 0; i < iSize; i++)
    {
        // ipArr[i] - 1 对应ipTemp的index，该用法类似于python字典
        (ipTemp[ipArr[i] - 1])++;
    }

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d occurrence %d times.\n", i + 1, ipTemp[i]);
    }
}