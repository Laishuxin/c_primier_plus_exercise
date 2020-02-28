#include<stdio.h>


int main() {
    int ch;
    while((ch = getchar())!=EOF)
    {
        putchar(ch);
    }
    printf("finish putchar\n");
    system("pause");
    return 0;
}