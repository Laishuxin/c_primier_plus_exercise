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

/*�������ʼ��Ϊ������*/
void initialize_list(List* pList);

/*�ж������Ƿ�Ϊ������*/
bool list_is_empty(const List* pList);

/*�ж������Ƿ�����*/
bool list_is_full(const List* pList);

/*���������е���Ŀ*/
unsigned int list_item_count(const List* pList);

/*���item���ɹ�����true*/
/*Item item : Ҫ��ӵ���Ŀ��Ϣ*/
bool add_item(Item item, List* pList);

/*�������е�ÿһ��ִ�к���*pf */
void traverse(const List* pList, void (*pf)(Item item));

/*�ͷ��ڴ�*/
void empty_list(List* pList);

#endif