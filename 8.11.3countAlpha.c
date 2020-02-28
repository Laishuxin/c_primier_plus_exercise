#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    // setlocale(LC_CTYPE, "");
    char ch;
    int upperCt, lowerCt, notAlphaCt;
    upperCt = 0;
    lowerCt = 0;
    notAlphaCt = 0;

    while ((ch = getchar()) != EOF)
    {
        if (!isalpha(ch))
        {

            // printf("current char is %c\n", ch);
            notAlphaCt++;
            continue;
        }
        if (isupper(ch))
        {
            upperCt++;
        }
        else
        {
            lowerCt++;
        }
    }

    printf("非写字母有%d, 小写字母有%d, 大写字母有%d\n",
           notAlphaCt, lowerCt, upperCt);
    system("pause");
    return 0;
}
