#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char getChoice(void);

char getFirst(void);

int getInt(void);

void count(void);

int main(void)
{
    int choice;
    while ((choice = getChoice()) != 'q')
    {
        printf("main choice = %c\n", choice);
        switch (choice)
        {
        case 'a':
            printf("Buy low, and sell high.\n");
            break;
        case 'b':
            // putchar('\a');
            printf("this is a bell!\n");
            break;
        case 'c':
            count();
            break;
        default:
            printf("The program have some error!\n");
            break;
        }
        printf("--------------------------------\n");
    }
    printf("See you next time!\n");

    system("pause");
    return 0;
}

char getChoice(void)
{
    int ch;
    printf("please enter the letter of your choice!\n");
    printf("\ta. advice \tb.bell\n");
    printf("\tc.count \tq.quit\n");

    ch = getFirst();
    // printf("getChoice ch = %c\n", ch);
    while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'q')
    {
        printf("please respond with a, b, c, or q.\n");
        ch = getFirst();
    }
    return ch;
}

char getFirst(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    // printf("getFirst ch = %c\n", ch);
    return ch;
}

int getInt(void)
{
    int input;
    char ch;

    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not an integer.\nPlease enter a integer value!\n");
    }
    return input;
}

void count(void)
{
    int input;
    printf("Count how far? Enter a integer!\n");
    input = getInt();

    for (int i = 0; i < input; ++i)
    {
        printf("current index is %d\n", i+1);
    }
    while (getchar() != '\n')
        continue;
}
