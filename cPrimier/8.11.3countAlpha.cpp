#include<stdio.h>
#include<ctype.h>


int main3(int argc, char const* argv[])
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

    printf("非字母有%d个，小写字母有%d个， 大写字母有%d个\n",
        notAlphaCt, lowerCt, upperCt);

    system("pause");
    return 0;
}
