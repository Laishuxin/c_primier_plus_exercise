#include <stdio.h>
#include <string.h>
#include "17.list_copy.h"

void show_list(Item item);
char *s_gets(char *str, int size);
void test(void)
{
    List movies;
    Item tempItem;
    initialize_list(&movies);
    if (list_is_full(&movies))
    {
        fprintf(stderr, "list is full.\n");
        return;
    }
    printf("Enter movie title(empty to quit):");
    while (s_gets(tempItem.m_title, TSIZE) != NULL && tempItem.m_title[0] != '\0')
    {
        printf("Enter the rating <0-10>: ");
        scanf("%u", &tempItem.m_rating);
        while (getchar() != '\n')
        {
            continue;
        }
        if (!add_item(tempItem, &movies))
        {
            fprintf(stderr, "Fail to add item!\n");
            return;
        }
        if (list_is_full(&movies))
        {
            fprintf(stderr, "The list is now full!\n");
            return;
        }
        printf("Please enter the next title(empty to quit):");
    }
    if (list_is_empty(&movies))
    {
        printf("Sorry, the list is empty!\n");
    }
    else
    {
        traverse(&movies, show_list);
    }
    printf("There are %d items in the list.\n", list_item_count(&movies));
    printf("Done!\n");
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}

void show_list(Item item)
{
    printf("Title : %s  Rating : %u\n", item.m_title, item.m_rating);
}

char *s_gets(char *str, int size)
{
    char *pRet;
    char *pFind;
    pRet = fgets(str, size, stdin);
    if (pRet)
    {
        pFind = strchr(str, '\n');
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