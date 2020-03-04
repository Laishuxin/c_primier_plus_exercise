#ifndef LIST_COPY__H
#define LIST_COPY__H

#include <stdlib.h>
#include <stdbool.h>
#define TSIZE 45

struct film
{
    char m_title[TSIZE];
    unsigned int m_rating;
};
typedef struct film Item;

typedef struct node
{
    Item m_item;
    struct node *next;
} Node;
typedef Node* List;


void initialize_list(List* pList);
bool list_is_empty(const List* pList);
bool list_is_full(const List* pList);
unsigned int list_item_count(const List*pList);
bool add_item(Item item, List* pList);
void traverse(const List* pList, void(*pf)(Item item));
void empty_list(List*pList);

#endif