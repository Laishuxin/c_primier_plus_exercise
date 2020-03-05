#ifndef QUEUE__H
#define QUEUE__H
#include<stdbool.h>
// TODO : delete testing code
#include<stdio.h>
    
#include<stdlib.h>
#define MAXSIZE 10

typedef int Item;
typedef struct node
{
    Item m_item;
    struct node *next;
} Node;

typedef struct queue
{
    unsigned int size;
    Node *front;
    Node *rear;
} Queue;

void initialize_queue(Queue *pQueue);
bool is_empty(const Queue *pQueue);
bool is_full(const Queue *pQueue);
unsigned int count(const Queue *pQueue);
bool append(Item item, Queue *pQueue);
bool left_pop(Queue *pQueue);
void clean(Queue *pQueue);
#endif