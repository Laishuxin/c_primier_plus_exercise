#include "queue.h"

void initialize_queue(Queue* pQueue)
{
    pQueue->front = pQueue->rear = NULL;
    pQueue->size = 0;
}

bool is_empty(const Queue* pQueue)
{
    return (pQueue->size == 0);
}

bool is_full(const Queue* pQueue)
{
    return (pQueue->size == MAXSIZE);
}

unsigned int count(const Queue* pQueue)
{
    return pQueue->size;
}

bool append(Item item, Queue* pQueue)
{
    if (is_full(pQueue))
    {
        exit(EXIT_FAILURE);
    }
    Node* pNewNode;
    pNewNode = (Node*)malloc(sizeof(Node));
    pNewNode->m_item = item;
    //copy_item_to_Node2(item, pNewNode);
    pNewNode->next = NULL;
    if (is_empty(pQueue))
    {
        pQueue->front = pNewNode;
    }
    else
    {

        pQueue->rear->next = pNewNode;
    }
    pQueue->rear = pNewNode;
    pQueue->size++;
    return true;
}

bool left_pop(Queue* pQueue)
{
    if (is_empty(pQueue))
    {
        return false;
    }
    Node* pTempNode;
    pTempNode = (*pQueue).front;
    pQueue->front = pQueue->front->next;
    free(pTempNode);
    pQueue->size--;
    if (pQueue->size == 0)
    {
        pQueue->rear = NULL;
    }
    return true;
}


void clean(Queue* pQueue)
{
    while (!is_empty(pQueue))
    {
        left_pop(pQueue);
    }
}

void copy_item_to_node2(Item item, Node *pNode)
{
    pNode->m_item = item;
}

void show_queue(const Queue* pQueue)
{
    if (is_empty(pQueue))
    {
        return;
    }
    Node* pTempNode = pQueue->front;
    printf("Queue : \n");
    while (pTempNode)
    {
        printf("%d ", pTempNode->m_item);
        pTempNode = pTempNode->next;
    }
    printf("\n");
}