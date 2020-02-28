#include <stdio.h>
#include <ctype.h>

int getPos(char(ch));
void practice7(void)
{
    /*
    编写一个函数， 从标准输入中读取字符， 直到遇到文件结尾。 程序要
    报告每个字符是否是字母。 如果是， 还要报告该字母在字母表中的数值位
    置。 例如， c和C在字母表中的位置都是3。 合并一个函数， 以一个字符作为
    参数， 如果该字符是一个字母则返回一个数值位置， 否则返回-1
    */
    int ch;
    int position;
    printf("please enter a char：\n");
    while ((ch = getchar()) != EOF)
    {
        position = getPos(ch);
        if (position == -1)
        {
            printf("%c is not a alpha!\n", ch);
        }
        else
        {
            printf("%c's position in alphabet %d.\n", ch, position);
        }
        while (getchar() != '\n')
            continue;
        printf("please enter a char：\n");
    }
    printf("Done!\n");
}

long getPow(int num, int times);
void practice9(void)
{
    /*
    .第6章的程序清单6.20中， power()函数返回一个double类型数的正整数
    次幂。 改进该函数， 使其能正确计算负幂。 另外， 函数要处理0的任何次幂
    都为0， 任何数的0次幂都为1（函数应报告0的0次幂未定义， 因此把该值处
    理为1） 。 要使用一个循环， 并在程序中测试该函数。
    */
    int num;
    int times; // times powers
    long ret;
    num = 5;
    times = -3;

    ret = getPow(num, times);
    printf("power\(%d, %d\) = %ld\n", num, times, ret);
}

void to_base_n(n, base);
void practice10(void)
{
    /*
    10.为了让程序清单9.8中的to_binary()函数更通用， 编写一个to_base_n()
    函数接受两个在2～10范围内的参数， 然后以第2个参数中指定的进制打印第
    1个参数的数值。 例如， to_base_n(129， 8)显示的结果为201， 也就是129的
    八进制数。 在一个完整的程序中测试该函数。
    */
    int base;
    int n;
    base = 3;
    n = 20;
    printf("In the base of %d, %d is equivalent:\n", base, n);
    to_base_n(n, base);
    printf("\n");
}

void practice11(void)
{
    // 用循环实现fibonacci
    int n; // n阶fibonacci数列
    n = 20;
    int curr = 1;
    int prev = 0;
    int temp;  //中间变量
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", curr);
        temp = prev;
        prev = curr;
        curr += temp;
    }
    printf("\n");
}

int main()
{
    //practice7();
    //practice9();
    //practice10();
    practice11();
    system("pause");
    return 0;
}

int getPos(char(ch))
{
    int ret;
    if (isalpha(ch))
    {
        ret = tolower(ch) - 96; // a的ascii为97
        return ret;
    }
    else
    {
        ret = -1;
        return ret;
    }
}

long getPow(int num, int times)
{
    int sign;
    long ret = 1;
    sign = (times > 0) ? 1 : -1;
    if (times > 0)
    {
        return sign * num * getPow(num, times - 1);
        //return times;
    }
    else if (times < 0)
    {
        times = -times;
        return sign * num * getPow(num, times - 1);
        //return times;
    }
    else
    {
        return 1;
    }
}

void to_base_n(n, base)
{
    int ret;
    ret = n % base;
    if (n / base >= base)
    {
        to_base_n(n / base, base);
    }
    else
    {
        printf("%d", n / base);
    }

    printf("%d", ret);
    return;
}