#include <stdio.h>
#include <string.h>
#define SLEN 40
#define LIM 5
#define STLEN 14
#define SIZE 80

void code111(void)
{
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately", "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"};
    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping", " Watching televion",
        "Mailing letters", "Reading email"};
    puts("Let's compare talents");
    for (int i = 0; i < LIM; i++)
        printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
    printf("\nsizeof mytalents: %zd , sizeof yourtalents: %zd\n",
           sizeof(mytalents), sizeof(yourtalents));
}

void code112(void)
{
    char string[STLEN];
    puts("Enter a string, pleas:");
    fgets(string, STLEN, stdin);
    printf("your string twice(first puts() then fputs()) : \n");
    puts(string);
    fputs(string, stdout);

    printf("please enter another string\n");
    fgets(string, STLEN, stdin);
    printf("your string twice(first puts() then fputs()) : \n");
    puts(string);
    fputs(string, stdout);
    printf("done!\n");
}

void code1122(void)
{
    // 用fgets函数读取字符串
    // 当字符串长度超过默认长度时，清空缓冲区
    // 删除不必要的换行符
    char string[STLEN];
    printf("Please enter a string:\n");
    while ((fgets(string, STLEN, stdin)) != NULL && string[0] != '\n')
    {
        int i = 0;
        while (string[i] != '\n' && string[i] != '\0')
        {
            i++;
        }

        if (string[i] == '\n')
        {
            string[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
        puts(string);
    }
    printf("Done!\n");
}

void put1(const char *string);
int put2(const char *string);
void code114(void)
{
    put1("startup put1\n");
    int ret = put2("startup put2 and count characters");
    printf("there are %d characters in string\n", ret);
}

char *s_gets(char *st, int n);
void code115(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    puts("What is your favorite flower?");
    if (s_gets(flower, SIZE))
    {
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    }
    else
    {
        puts("End of file encountered!");
        puts("bye");
    }
}


void sort_str(char*ptrstr[], int ct);
void code116(void)
{
    // 字符串排序
    char input[LIM][SIZE]; // 输入的str数组
    // 不改变原来的数组
    char *ptrstr[LIM];
    // 记录数组的真实个数
    int ct = 0;
    printf("Input up to %d lines and then I will sort it.\n", LIM);
    printf("To stop, please press Enter key!\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptrstr[ct] = input[ct];
        ct++;
    }
    sort_str(ptrstr, ct);
    puts("\nHere's the sorted list:");
    for (int i = 0; i < ct; i++)
    {
        puts(ptrstr[i]);
    }
}

int main(int argc, char const *argv[])
{

    //code111();
    // code112();
    //code1122();
    //code114();
    //code115();
    //code116();
    printf("this program named %s\n", argv[0]);
    printf("there are %d argument in this program.\n", argc-1);
    for(int i= 1;i<argc;i++)
    {
        printf("%d: %s\n", i, argv[i]);
    }
    printf("sizeof('$') = %d, sizeof(\"$\" ) = %d", sizeof('$'), sizeof("$"));
    system("pause");
    return 0;
}
void put1(const char *string)
{
    while (*string)
    {
        putchar(*string++);
    }
}
int put2(const char *string)
{
    int count = 0;
    while (*string)
    {
        putchar(*string++);
        count += 1;
    }
    putchar('\n');
    return count;
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


void sort_str(char*ptrstr[], int ct)
{
    char *temp;
    for(int i=0;i<ct-1;i++)
    {
        for(int j=i+1; j<ct;j++)
        {
            if(strcmp(ptrstr[i], ptrstr[j])> 0)
            {
                temp = ptrstr[i];
                ptrstr[i] = ptrstr[j];
                ptrstr[j] = temp;
            }
        }
    }
}


