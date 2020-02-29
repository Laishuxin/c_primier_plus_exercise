#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 复习题
void practice04(int argc, char const *argv[])
{
    // 编写一个程序， 不接受任何命令行参数或接受一个命令行参数。 如果
    // 有一个参数， 将其解释为文件名； 如果没有参数， 使用标准输入（stdin） 作
    // 为输入。 假设输入完全是浮点数。 该程序要计算和报告输入数字的算术平均值。
    // =======================================================================

    float fValue;
    float fSum = 0;
    int iCount = 0;
    FILE *fp;
    // 标准输入
    if (argc == 1)
    {
        fp = stdin;
        printf("Please enter values(enter q to quit):");
    }
    else if (argc == 2)
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "Fail to open file %s.\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "There are some error int this program!\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%f", &fValue) == 1)
    {
        iCount++;
        fSum += fValue;
        // printf("current value is %f.\n", fValue);
        // printf("current value  count is %d.\n", iCount);
        // printf("current value sum is %f.\n", fSum);
    }
    printf("The average of input values is %.2f.\n", fSum / (float)iCount);
    if (fp != NULL)
    {
        fclose(fp);
    }
    // while (getchar() != '\n')
    //     continue;
}

void practice05(int argc, char const *argv[])
{
    // 编写一个程序， 接受两个命令行参数。 第1个参数是字符， 第2个参数
    // 是文件名。 要求该程序只打印文件中包含给定字符的那些行。
    // =======================================================================
    char cpStr[256];
    char cChar;
    FILE *fp;
    if (argc != 3)
    {
        fprintf(stderr, "argument count is error.\n");
        //exit(EXIT_FAILURE);
        return;
    }
    cChar = *argv[1]; // 第一个参数，第一个字符
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "open file '%s' fail.\n", argv[2]);
        //exit(EXIT_FAILURE);
        return;
    }
    while (fgets(cpStr, 256, fp))
    {
        if (strchr(cpStr, cChar))
            puts(cpStr);
    }
    if(fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
    printf("Done!\n");
}

int main(int argc, char const *argv[])
{
    // practice04(argc, argv);
    practice05(argc, argv);
    system("pause");
    return 0;
}
