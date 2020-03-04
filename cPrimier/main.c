#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void show_movies(Item item);

char* s_gets(char* st, int n);

void test(void)
{
    List movies;
    Item temp;
    initialize_list(&movies);
    if (list_is_full(&movies))
    {
        fprintf(stderr, "No memory available!\n");
        return;
    }
    printf("Enter  movie title (empty line to stop):");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        printf("Enter your rating <0-10> : ");
        scanf_s("%d", &temp.rating);
        while (getchar() != '\n')
        {
            continue;
        }
        if (!add_item(temp, &movies))
        {
            fprintf(stderr, "Problem allocating memory!\n");
            return;
        }
        if (list_is_full(&movies))
        {
            printf("The list is now full!\n");
            return;
        }
        printf("Enter next movie title (empty line to stop):");
    }
    if (list_is_empty(&movies))
    {
        printf("There is no data entered!\n");
    }
    else
    {
        printf("Here is your movie list : \n");
        traverse(&movies, show_movies);
    }
    printf("There are %d movie enters.\n", list_item_count(&movies));
    empty_list(&movies);
    printf("Done!\n");
}
int main(void)
{
    test();
    system("pause");
    return 0;
}

char* s_gets(char* st, int n)
{
    char* pRet;
    char* pFind;
    pRet = fgets(st, n, stdin);
    if (pRet)
    {
        pFind = strchr(st, '\n');
        if (pFind)
        {
            *pFind = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return pRet;
}

void show_movies(Item item)
{
    printf("Movie : %s  Rating : %d\n", item.title, item.rating);
}