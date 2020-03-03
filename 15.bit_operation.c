#include <stdio.h>
#include <limits.h>

char *itobs(int, char *);
void show_bstr(const char *);
void code1538(int argc, char const *argv[])
{
    char bin_str[CHAR_BIT * sizeof(int) + 1]; // +1 流出一个’\0'
    int number;
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Byee!");
}

// num 为要转换的十进制整数，bits为要取反的bit数
int invert_end(int num, int bits);
void code1539(void)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1]; // +1 流出一个’\0'
    int number;
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
        printf("Inverting last 4 bits gives:");
        number = invert_end(number, 4);
        show_bstr(itobs(number, bin_str));
    }
    puts("Byee!");
}

int main(int argc, char const *argv[])
{
    const int lm = 5;
    // static int data[lm];
    const int x = lm * 5;
    //code1539();
    printf("x = %d\n", x);
    system("pause");
    return 0;
}

char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; // 转换为char的整数
    ps[size] = '\0';
    return ps;
}

void show_bstr(const char *str)
{
    int i = 0;
    while (str[i])
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1;
    while (bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    return num ^ mask;
}