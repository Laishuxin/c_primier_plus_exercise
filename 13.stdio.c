/*************************************************************************
File name : 13.stdio.c
Its function : c primier plus chapter 13
Create time : 2020.2.28
Author : Lsx
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define BUFSIZE 4096
#define SLEN 81

void code133(int argc, char const *argv[])
{
    FILE *F_in, *F_out;
    int iCh;
    char cpName[LEN];
    int iCount = 0;
    if (argc < 2)
    {
        fprintf(stderr, "usage : %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((F_in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open %s file.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    strncpy(cpName, argv[1], LEN - 5);
    cpName[LEN - 5] = '\0';
    strcat(cpName, ".red");
    if ((F_out = fopen(cpName, "w")) == NULL)
    {
        fprintf(stderr, "I couldn't open the output file %s.\n", cpName);
        exit(EXIT_FAILURE);
    }
    while ((iCh = getc(F_in)) != EOF)
    {
        if (iCount++ % 3 == 0)
        {
            putc(iCh, F_out);
        }
    }
    if (fclose(F_in) != 0 || fclose(F_out) != 0)
    {
        fprintf(stderr, "exit failure!\n");
    }
}

void code134(void)
{
    int iMax = 40;
    char cpWord[iMax];
    char *FILENAME = "test.txt";
    FILE *fp = fopen(FILENAME, "a+");
    if (fp == NULL)
    {
        fprintf(stdout, "Fail to open \"%s\" file.\n", FILENAME);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Please enter words to append at the end of \"%s\" file(enter # to quit).\n", FILENAME);
    while ((fscanf(stdin, "%40s", cpWord) == 1) && (cpWord[0] != '#'))
    {
        fprintf(fp, "%s\n", cpWord);
    }
    printf("File contents : \n");

    //将指针移动到文件开头
    rewind(fp);
    while (fscanf(fp, "%s", cpWord) == 1)
    {
        fprintf(stdout, "%s\n", cpWord);
    }
    fprintf(stdout, "Done!\n");
    if (fclose(fp) != 0)
    {
        printf("Fail to close the file.\n");
    }
}

/*************************************************************************
Description
-----------
在文件末尾添加附件
1.以追加的方式打开文件
2.如果打开失败，则退出程序
3.为该文件分配缓冲区
4.如果分配失败，则退出程序
(
如果两个附件的文件与目标文件相同时，追加下一个文件
如果以只读方式打开文件失败，追加下一个文件
将附件添加在文件末尾 
)

*************************************************************************/
char *s_gets(char *cpStr, int iSize);
void append(FILE *fpSource, FILE *fpTarget);
void code137(void)
{
    FILE *fpSource, *fpTarget;
    int iAppendFileCount = 0;
    char cpFileTarget[SLEN];
    char cpFileSource[SLEN];

    int iChar;
    puts("Enter the name of destination file.");
    s_gets(cpFileTarget, SLEN);
    if ((fpTarget = fopen(cpFileTarget, "a+")) == NULL)
    {
        fprintf(stderr, "Fail to open \"%s\" file.\n", cpFileTarget);
        exit(EXIT_FAILURE);
    }

    // NULL : 系统自动分配缓冲区，也可以传入char*，
    // _IOFBF : 完全缓冲
    // setvbuf 成功的话返回0
    if (setvbuf(fpTarget, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Fail to set buffer.", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter the name of source file(empty line to quit)");
    while (s_gets(cpFileSource, SLEN) && cpFileSource[0] != '\0')
    {
        if (strcmp(cpFileSource, cpFileTarget) == 0)
        {
            fputs("can't append itself.", stderr);
        }
        else if ((fpSource = fopen(cpFileSource, "r")) == NULL)
        {
            fprintf(stderr, "Fail to open \"%s\" file.\n", cpFileSource);
        }
        else
        {
            if (setvbuf(fpSource, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("can't create input buffer.", stderr);
                continue;
            }
            append(fpSource, fpTarget);
            if (ferror(fpSource) != 0)
            {
                fprintf(stderr, "Error in reading file %s.\n", cpFileSource);
            }
            if (ferror(cpFileTarget) != 0)
            {
                fprintf(stderr, "Error in reading file %s.\n", cpFileTarget);
            }
            fclose(fpSource);
            iAppendFileCount++;
            printf("File %s appended.\n", cpFileSource);
            puts("Next file(enter empty line to quit).");
        }
    }
    printf("Done appending. %d files appended.\n", iAppendFileCount);
    rewind(fpTarget);
    printf("%s contents : \n", cpFileTarget);
    while ((iChar = getc(fpTarget)) != EOF)
        putchar(iChar);
    puts("Done displaying.");
    fclose(fpTarget);
}

void code1379(void)
{
    // 二进制读写，实现随机访问
    const int iSize = 1000;
    double dpArr[iSize];
    for (size_t i = 0; i < iSize; i++)
    {
        dpArr[i] = 1.0 + i / 10.0;
    }

    // =======================================================================
    // 写入数据
    FILE *fpInput;
    const char *FILENAME = "test.dat";
    if ((fpInput = fopen(FILENAME, "wb")) == NULL)
    {
        printf("Fail to open \"%s\" file.\n", FILENAME);
        exit(EXIT_FAILURE);
    }
    fwrite(dpArr, sizeof(double), iSize, fpInput);
    // 关闭文件
    if (fpInput != NULL)
    {
        fclose(fpInput);
        fpInput = NULL;
    }

    // =======================================================================
    // 读取数据
    double dValue;  // 读取到的数据
    long lPos = 0L; // 数据在文件中的位置，按字节计算
    int iPos;       // 用户想要访问第几个数据，按数据的个数计算
    // 打开文件
    FILE *fpOutput;
    if ((fpOutput = fopen(FILENAME, "rb")) == NULL)
    {
        fprintf(stderr, "Fail to open \"%s\" file.\n", FILENAME);
        exit(EXIT_FAILURE);
    }
    printf("Enter the data index you want to visit(enter q to quit) : ");
    while ((scanf("%d", &iPos) == 1) &&(iPos>=0) && (iPos<iSize))
    {
        lPos = (long) iPos * sizeof(double);
        fseek(fpOutput, lPos, SEEK_SET);
        fread(&dValue, sizeof(double),1,fpOutput);
        printf("The value you want read is %lf.\n", dValue);
        printf("Enter the data index you want to visit(enter q to quit) : ");
    }
    printf("Done!\n");
}

int main(int argc, char const *argv[])
{
    //code133(argc, argv);
    // code134();
    // code137();
    code1379();
    system("pause");
    return 0;
}

char *s_gets(char *cpStr, int iSize)
{
    char *cpRetVal;
    char *cpFind;
    cpRetVal = fgets(cpStr, iSize, stdin);
    if (cpRetVal)
    {
        cpFind = strchr(cpRetVal, '\n');
        if (cpFind)
            *cpFind = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return cpRetVal;
}

void append(FILE *fpSource, FILE *fpTarget)
{
    size_t bytes;
    // =======================================================================
    // 这里用静态char arr 当成缓冲区，通过fread返回值限制fwrite写入文件的字节数，
    // 虽然数组后面的数据没有清空，但fwrite根本读不到
    static char s_cpTemp[BUFSIZE];

    // =======================================================================
    // 因为char为一个字节，所以大于0，说明fread正确运行
    // 之所以用fread是因为fprintf在存储数据的时候会忽视数据的类型
    // bytes是从文件中读取到的字符数
    while ((bytes = fread(s_cpTemp, sizeof(char), BUFSIZE, fpSource)) > 0)
    {
        fwrite(s_cpTemp, sizeof(char), bytes, fpTarget);
    }
    fwrite("\n", sizeof(char), 1, fpTarget);
}