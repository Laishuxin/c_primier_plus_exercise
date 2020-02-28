#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char *s_gets(char *st, int n);

void get_string1(char *string, int num);
void practice1(void)
{
    int n = 50;
    char string[n];
    while (1)
    {
        printf("please enter characters:\n");
        get_string1(string, n);
        puts(string);
    }
}

void get_word3(char *string, const int num);
void practice3(void)
{
    // 设计并测试一个函数， 从一行输入中把一个单词读入一个数组中， 并
    // 丢弃输入行中的其余字符。 该函数应该跳过第1个非空白字符前面的所有空
    // 白。 将一个单词定义为没有空白、 制表符或换行符的字符序列。
    // 设计并测试一个函数， 它类似编程练习3的描述， 只不过它接受第2个
    // 参数指明可读取的最大字符数。
    int num = 10;
    char string[num + 1];
    printf("please enter a word(its length must be less %d characters)\n",
           num);
    get_word3(string, num);
    puts(string);
}

char *my_strchr(const char *string, const char ch);
void practice5(void)
{
    //     设计并测试一个函数， 搜索第1个函数形参指定的字符串， 在其中查
    // 找第2个函数形参指定的字符首次出现的位置。 如果成功， 该函数返指向该
    // 字符的指针， 如果在字符串中未找到指定字符， 则返回空指针（该函数的功
    // 能与 strchr()函数相同） 。 在一个完整的程序中测试该函数， 使用一个循环
    // 给函数提供输入值
    char *string = "this is a test string!";
    char ch = '0';
    char *pos;
    while (ch != '#')
    {
        printf("please enter a character"
               " then I will check whether it is in target string"
               "(type# to quit)\n");
        ch = getchar();
        // 一次只提取一个char
        while (getchar() != '\n')
            continue;
        pos = my_strchr(string, ch);
        if (pos != NULL)
        {
            printf("%c in string:%s\n", ch, string);
            puts(pos);
        }
        else
        {
            printf("%c is not in string: %s\n", ch, string);
        }
    }
}

char *my_strncpy(char *string1, const char *string2, unsigned int n);
void practice7(void)
{
    //     strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中， 截断s2， 或者有必
    // 要的话在末尾添加空字符。 如果s2的长度是n或多于n， 目标字符串不能以空
    // 字符结尾。 该函数返回s1。 自己编写一个这样的函数， 名为mystrncpy()。 在
    // 一个完整的程序中测试该函数， 使用一个循环给函数提供输入值。
    char string1[50] = "hello ";
    char *string2 = "world!";
    // char* string_copy = strncpy(string1, string2, 10);
    // printf("string1 = %s, string_copy = %s\n",string1, string_copy);
    printf("original string1 is %s\n", string1);
    char *string_copy = my_strncpy(string1, string2, 10);
    printf("finish copy and string1 is %s\n", string1);
    printf("finish copy and string_copy is %s\n", string_copy);
}

char *string_in(const char *str1, const char *str2);
void practice8(void)
{
    //     8.编写一个名为string_in()的函数， 接受两个指向字符串的指针作为参
    // 数。 如果第2个字符串中包含第1个字符串， 该函数将返回第1个字符串开始的地址。 例如， string_in("hats", "at")将返回hats中a的地址。 否则， 该函数返
    // 回空指针。 在一个完整的程序中测试该函数， 使用一个循环给函数提供输入
    // 值
    char *str1 = "this is string 1 ";
    char str2[256];
    char *ret;
    printf("please enter string 2(type a # to quit):");
    scanf("%s", str2);
    while (str2[0] != '#')
    {
        ret = string_in(str1, str2);
        if (ret)
        {
            printf("str2 in str1!\n");
            printf("its position string is %s\n", ret);
        }
        else
        {
            printf("str2(%s) is not in str1(%s)\n", str2, str1);
        }
        printf("please enter string 2(type a # to quit):");
        scanf("%s", str2);
    }
    printf("done!\n");
}

void delete_blank(char *string);
void practice10(void)
{
    // 编写一个函数接受一个字符串作为参数， 并删除字符串中的空格。
    // 在一个程序中测试该函数， 使用循环读取输入行， 直到用户输入一行空行。
    // 该程序应该应用该函数只每个输入的字符串， 并显示处理后的字符串
    char *ret;
    char string[256];
    printf("please enter a string:");
    while (s_gets(string, 256))
    {
        printf("undelete string is %s\n", string);
        delete_blank(string);
        printf("deleted string is %s\n", string);
    }
    printf("Done!\n");
}

void printf_original_str(int row, const char string[row][64]);
void printf_by_ascci(int row, const char string[row][64]);
void printf_by_len(int row, const char string[row][64]);
void printf_by_len_word(int row, const char string[row][64]);
/********************************************
Description
-----------
获取字符串第一个单词的字符个数，
单词的定义：第一个字母为开头，空白为结尾
跳过字符串前面的空白符

Parameters
-----------
string : char*
    字符串

Returns
-------
count : int
    字符串第一个单词的字符个数

*********************************************/
int get_char_count(const char *string);
void practice11(void)
{
    // 编写一个函数， 读入10个字符串或者读到EOF时停止。 该程序为用
    // 户提供一个有5个选项的菜单： 打印源字符串列表、 以ASCII中的顺序打印字
    // 符串、 按长度递增顺序打印字符串、 按字符串中第1个单词的长度打印字符
    // 串、 退出。 菜单可以循环显示， 除非用户选择退出选项。 当然， 该程序要能
    // 真正完成菜单中各选项的功能。
    int n_string = 3;
    char string2d[n_string][64];
    int string_count = 0;
    printf("You must enter less than %d strings:\n", n_string);
    for (size_t i = 0; i < n_string; i++)
    {
        s_gets(string2d[i], 64);
        if (string2d[i][0] == '\0')
        {
            break;
        }
        string_count++;
    }
    char option;
    do
    {
        printf("------------------------------------------------------------------\n");
        printf("a. print original string       b. print string order by ASCCI\n");
        printf("c. print string by length      d. print string by length of first word\n");
        printf("q. quit");
        printf("Please enter your option:");
        option = getchar();
        // 删除多余的字符，只获取用户输入的首字符
        while (getchar() != '\n')
            continue;
        switch (option)
        {
        case 'a':
            printf_original_str(string_count, string2d);
            break;
        case 'b':
            printf_by_ascci(string_count, string2d);
            break;
        case 'c':
            printf_by_len(string_count, string2d);
            break;
        case 'd':
            printf_by_len_word(string_count, string2d);
            break;
        case 'q':
            printf("Done!\n");
            return;
            break;
        default:
            printf("Your enter is error!\n");
            break;
        }
        printf("------------------------------------------------------------------\n");
    } while (1);
}

/********************************************
Description
-----------
获取字符串信息，并打印
字符串信息包括：  
1. 单词个数
2. 大写字母个数
3. 小写字母个数
4. 标点符号数
5. 数字字符个数

Parameters
-----------
string : char*
    字符串

Returns
-------

*********************************************/
void print_string_info(char *string);
void practice12(void)
{
    // 编写一个程序， 读取输入， 直至读到 EOF， 报告读入的单词数、 大
    // 写字母数、 小写字母数、 标点符号数和数字字符数。 使用ctype.h头文件中的
    // 函数
    char cpString[256];
    do
    {
        printf("Please enter a string(enter q to quit the loop):");
        s_gets(cpString, 256);
        printf("------------------------------------------------\n");
        if (cpString[0] != 'q')
        {
            print_string_info(cpString);
            printf("------------------------------------------------\n");
        }
    } while (1);
}

void reverse_string_by_word(char *cpString, int iSize);
void practice13(void)
{
    // 编写一个程序， 反序显示命令行参数的单词。 例如， 命令行参数是
    // see you later， 该程序应打印later you see
    char cpString[256];
    do
    {
        printf("Please enter a string(enter q to quit the loop):");
        s_gets(cpString, 256);
        printf("------------------------------------------------\n");
        if (cpString == 'q')
            break;
        printf("original string : %s\n", cpString);
        reverse_string_by_word(cpString, 256);
    } while (1);
}

void practice14(int argc, char **argv)
{
    // 编写一个通过命令行运行的程序计算幂。 第1个命令行参数是double
    // 类型的数， 作为幂的底数， 第2个参数是整数， 作为幂的指数
    if (argc == 1)
        return;
    double dBase = 0;
    int iIndex = 0;
    double dRet = 0;
    dBase = atof(argv[1]);
    iIndex= atoi(argv[2]);
    dRet = pow(dBase, iIndex);
    printf("The %dth power of %.2lf is %.2lf\n", iIndex, dBase, dRet);
}

int main(int argc, char const *argv[])
{
    //practice1();
    //practice3();
    //practice5();
    //practice7();
    //practice8();
    //practice10();
    //practice11();
    //practice12();

    // 编写一个程序， 反序显示命令行参数的单词。 例如， 命令行参数是
    // see you later， 该程序应打印later you see
    //practice13();
    // printf("unreversed arguments : ");
    // for (size_t i = 1; i < argc; i++)
    // {
    //     printf("%s ", argv[i]);
    // }
    // printf("\n");
    // printf("reversed arguments : ");
    // for (size_t i = 1; i < argc; i++)
    // {
    //     printf("%s ", argv[argc - i]);
    // }
    // printf("\n");

    practice14(argc, argv);
    system("pause");
    return 0;
}

void get_string1(char *string, int num)
{
    char ch;
    int i;
    for (i = 0; i < num; i++)
    {
        ch = getchar();
        if (isspace(ch))
        {
            while (getchar() != '\n')
                continue;
            break;
        }
        string[i] = ch;
    }
}

void get_word3(char *string, const int num)
{
    char ch;
    int i = 0;
    // 删除单词前面的空白字符
    while (1)
    {
        ch = getchar();
        if (!isblank(ch))
            break;
    }
    while (i < num)
    {
        string[i++] = ch;
        ch = getchar();

        if (isspace(ch))
            break;
    }
    string[i] = '\0';
}

char *my_strchr(const char *string, const char ch)
{
    int len = strlen(string);
    for (size_t i = 0; i < len; i++)
    {
        if (string[i] == ch)
            return &string[i];
    }
    return NULL;
}

char *my_strncpy(char *string1, const char *string2, unsigned int n)
{
    int len1, len2, len_copy;
    len1 = strlen(string1);
    len2 = strlen(string2);
    len_copy = len2 > n ? n : len2;

    for (size_t i = 0; i < len_copy; i++)
    {
        string1[len1 + i] = string2[i];
    }
    if (len2 < n)
    {
        string1[len1 + len2] = '\0';
    }
    return string1;
}

char *string_in(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *ret;
    bool flag = true;
    for (size_t i = 0; i < len1; i++)
    {
        for (size_t j = 0; j < len2; j++)
        {
            ret = &str1[i];
            //printf("str1[i+j] = %c, str2[j] = %c\n",str1[i+j],str2[j]);
            if (str1[i + j] != str2[j])
            {
                flag = false;
                ret = NULL;
                break; // 跳出内层循环
            }
        }
        // 如果ret不为空，说明找到了，退出内层循坏
        if (ret)
            break;
    }
    return ret;
}

void delete_blank(char *string)
{
    int len = strlen(string);
    int index = 0;
    // for (size_t i = 0; i < len; i++)
    // {
    //     if(isblank(string[i]))
    //     {
    //         string[i]
    //     }
    // }
    // 遍历字符串，如果发现空格则将空格后面的字符往前移动，切不移动下标i
    // 防止下一个字符也是空格
    while (index < len)
    {
        if (isblank(string[index]))
        {
            for (size_t i = index; i < len; i++)
            {
                string[i] = string[i + 1];
            }
        }
        else
        {
            index++;
        }
    }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
        {
            i++;
        }
        if (st[i] == '\n')
            st[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

void printf_original_str(int row, const char string[row][64])
{
    for (size_t i = 0; i < row; i++)
    {
        printf("%d : %s\n", i + 1, string[i]);
    }
}

void printf_by_ascci(int row, const char string[row][64])
{
    // 复制数组
    char *ptr_string[row];
    char *temp;
    for (size_t i = 0; i < row; i++)
    {
        ptr_string[i] = string[i];
    }

    // 选择排序，按照ascci先后顺序
    for (size_t i = 0; i < row - 1; i++)
    {
        for (size_t j = i + 1; j < row; j++)
        {
            if (strcmp(ptr_string[i], ptr_string[j]) > 0)
            {
                temp = ptr_string[i];
                ptr_string[i] = ptr_string[j];
                ptr_string[j] = temp;
            }
        }
    }

    // 打印排序好的数组
    for (size_t i = 0; i < row; i++)
    {
        printf("%d : %s\n", i + 1, ptr_string[i]);
    }
}

void printf_by_len(int row, const char string[row][64])
{
    // 复制数组
    char *ptr_string[row];
    char *temp;
    for (size_t i = 0; i < row; i++)
    {
        ptr_string[i] = string[i];
    }

    // 选择排序，按照string的长度升序，如果长度一样则按ascci
    for (size_t i = 0; i < row - 1; i++)
    {
        for (size_t j = i + 1; j < row; j++)
        {
            // 如果长度不一致，则按照长度排序
            if (strlen(ptr_string[i]) > strlen(ptr_string[j]))
            {
                temp = ptr_string[i];
                ptr_string[i] = ptr_string[j];
                ptr_string[j] = temp;
            }
            // 如果长度一致，则按照ascci排序
            else if (strlen(ptr_string[i]) == strlen(ptr_string[j]))
            {
                if (strcmp(ptr_string[i], ptr_string[j]) > 0)
                {
                    temp = ptr_string[i];
                    ptr_string[i] = ptr_string[j];
                    ptr_string[j] = temp;
                }
            }
        }
    }

    // 打印排序好的数组
    for (size_t i = 0; i < row; i++)
    {
        printf("%d : %s\n", i + 1, ptr_string[i]);
    }
}

void printf_by_len_word(int row, const char string[row][64])
{
    // 复制数组
    char *ptr_string[row];
    char *temp;
    for (size_t i = 0; i < row; i++)
    {
        ptr_string[i] = string[i];
    }

    // 选择排序，按照string首个单词的长度升序，如果长度一样则按字符串的ascc(不一定是首个单词)i
    for (size_t i = 0; i < row - 1; i++)
    {
        for (size_t j = i + 1; j < row; j++)
        {
            // 如果长度不一致，则按照长度排序
            if (get_char_count(ptr_string[i]) > get_char_count(ptr_string[j]))
            {
                temp = ptr_string[i];
                ptr_string[i] = ptr_string[j];
                ptr_string[j] = temp;
            }
            // 如果长度一致，则按照ascci排序
            else if (get_char_count(ptr_string[i]) == get_char_count(ptr_string[j]))
            {
                if (strcmp(ptr_string[i], ptr_string[j]) < 0)
                {
                    temp = ptr_string[i];
                    ptr_string[i] = ptr_string[j];
                    ptr_string[j] = temp;
                }
            }
        }
    }

    // 打印排序好的数组
    for (size_t i = 0; i < row; i++)
    {
        printf("%d : %s\n", i + 1, ptr_string[i]);
    }
}

int get_char_count(const char *string)
{
    int iCount = 0;
    int iStrLen = strlen(string);
    // 判断单词师傅结束
    bool bFlag = false;
    for (size_t i = 0; i < iStrLen; i++)
    {
        // 判断单词开始，并准备退出flag
        if (isalpha(string[i]))
        {
            iCount++;
            bFlag = true;
        }
        // 判断单词结尾
        else if (isblank(string[i]) && bFlag)
            break;
    }
    return iCount;
}

void print_string_info(char *string)
{
    const int c_iStrLen = strlen(string);
    int iWordCount = 0;
    int iLowerCount = 0;
    int iUpperCount = 0;
    int iPunctCount = 0;
    int iDigitCount = 0;
    bool bWordEnd = false;
    for (size_t i = 0; i < c_iStrLen; i++)
    {
        if (islower(string[i]))
            iLowerCount++;
        else if (isupper(string[i]))
            iUpperCount++;
        else if (ispunct(string[i]))
            iPunctCount++;
        else if (isdigit(string[i]))
            iDigitCount++;

        if (isalpha(string[i]))
        {
            if (!bWordEnd)
            {
                bWordEnd = true;
                iWordCount++;
            }
        }
        else
        {
            bWordEnd = false;
        }
    }
    printf("string : %s \nits imformation as follows:\n", string);
    printf("Numbers of words : %d\n", iWordCount);
    printf("Lowercase letters : %d\n", iLowerCount);
    printf("Uppercase letters : %d\n", iUpperCount);
    printf("Punctuation letters : %d\n", iPunctCount);
    printf("Number of digits : %d\n", iDigitCount);
}

void reverse_string_by_word(char *cpString, int iSize)
{
    // 识别单词
    // 逆序 : 通过strcat将新的单词连接在开头，从而实现逆序
    int iStringLen = strlen(cpString);

    char cpTempWord[64];
    int iWordCount = 0;

    char cpReverseWord[iSize];
    char *cpReverseIndex = cpReverseWord; // 用于记录cpReverseWord当前的位置
    cpReverseWord[0] = '\0';

    for (size_t i = iStringLen; i != 0; i--)
    {
        if (isalpha(cpString[i - 1]))
        {
            cpTempWord[iWordCount] = cpString[i - 1];
            iWordCount++;
            if (i == 1)
            {
                for (size_t j = iWordCount; j != 0; j--)
                {
                    *cpReverseIndex++ = cpTempWord[j - 1];
                }
            }
        }
        else
        {
            // 将单词载入到cpReverseWord中，并清空字符串tempWord;
            for (size_t j = iWordCount; j != 0; j--)
            {
                *cpReverseIndex++ = cpTempWord[j - 1];
                cpTempWord[j] = '\0';
            }
            // 单词与单词之间添加空格
            *cpReverseIndex++ = ' ';
            iWordCount = 0;
        }
    }
    printf("reversed string by word, its result is : %s\n", cpReverseWord);
}

double power14(long lBase, int iIndex)
{
    long ret = pow(lBase, (long)iIndex);
    return ret;
}