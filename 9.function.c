#include <stdio.h>

long long factorial1(int num);
long long factorial2(int num);
void recursion93(void)
{
    printf("Please enter a number(from 0 to 12) and then I will"
           "give you its factorial:\n");

    int num;
    long long ret;
    while (scanf("%d", &num) == 1)
    {
        if (num < 0)
        {
            printf("the number is too small.\n");
        }
        else if (num > 50)
        {
            printf("the number is too big");
        }
        else
        {
            printf("------------------------------\n");
            printf("call the first function to compute its factorial...\n");
            ret = factorial1(num);
            printf("%d! = %lld.\n", num, ret);
            printf("call the second function to compute its factorial...\n");
            ret = factorial2(num);
            printf("%d! = %lld.\n", num, ret);
            printf("------------------------------\n");
        }
        printf("Please enter a number(from 0 to 12) and then I will"
               "give you its factorial:\n");
    }
    printf("Done.\n");
}


void to_binary(unsigned long number);
void to_binary934(void)
{
    // 将十进制数字�?换成二进制数�?
    unsigned long input;
    printf("������Ҫʮ������ֵ��");
    while(scanf("%lu", &input) == 1)
    {
        printf("%lu to binary is ", input);
        to_binary(input);
        putchar('\n');
        printf("---------------------\n");
        printf("������Ҫʮ������ֵ��");
    } 
    printf("Done!\n");
}


unsigned long fibonacci(int number);
void fibonacci935(void)
{
    int number;
    printf("������n��fibonacci�Ľ�����");
    while(scanf("%d", &number) == 1)
    {
        printf("��%d��fibonacciΪ��%lu\n", number, fibonacci(number));

        printf("������n��fibonacci�Ľ�����");
    }
    printf("Done!\n");
}




int main(int argc, char const *argv[])
{
    // recursion93();
    //to_binary934();
    fibonacci935();
    system("pause");
    return 0;
}

long long factorial1(int num)
{
    // 利用�?�?算出n的阶�?
    long long ret = 1L;
    for (int i = 0; i < num; ++i)
    {
        ret *= (i + 1);
    }
    return ret;
}

long long factorial2(int num)
{
    // 利用递归算出n的阶�?
    long long ret;
    if (num > 0)
    {
        ret = num * factorial2(num - 1);
    }
    else 
    {
        ret = 1;
    }
    return ret;
}


void to_binary(unsigned long number)
{
    int ret;
    ret = number % 2;
    if(number >=2)
    {
        to_binary(number /2);
    }
    putchar(ret == 0? '0':'1');
    return;
}
unsigned long fibonacci(int number)
{
    unsigned long ret;
    if(number >2)
    {

        ret = fibonacci(number -1) + fibonacci(number -2);
        return ret;
    }
    else 
        ret = 1;
        return ret;
}