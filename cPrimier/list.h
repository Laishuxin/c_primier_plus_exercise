#ifndef LIST__H
#define LIST__H

#include <stdbool.h>
#include<string.h>
#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
};
typedef struct film Item;

typedef struct node
{
    Item item;
    struct node* next;
} Node;
typedef Node* List;

/*将链表初始化为空链表*/
void initialize_list(List* pList);

/*判断链表是否为空链表*/
bool list_is_empty(const List* pList);

/*判断链表是否满了*/
bool list_is_full(const List* pList);

/*计算链表中的条目*/
unsigned int list_item_count(const List* pList);

/*添加item，成功返回true*/
/*Item item : 要添加的条目信息*/
bool add_item(Item item, List* pList);

/*对链表中的每一项执行函数*pf */
void traverse(const List* pList, void (*pf)(Item item));

/*释放内存*/
void empty_list(List* pList);

#endif