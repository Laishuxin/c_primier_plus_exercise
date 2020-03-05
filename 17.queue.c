#include "17.queue.h"
static void copy_item_to_node(Item item, Node *pNode);

void initialize_queue(Queue *pQueue)
{
    pQueue->front = pQueue->rear = NULL;
    pQueue->size = 0;
}

bool is_empty(const Queue *pQueue)
{
    return (pQueue->size == 0);
}

bool is_full(const Queue *pQueue)
{
    return (pQueue->size == MAXSIZE);
}

unsigned int count(const Queue *pQueue)
{
    return pQueue->size;
}

bool append(Item item, Queue *pQueue)
{
    if (is_full(&pQueue))
    {
        // TODO : delete testing
        fprintf(stderr, "There is no space to append.\n");
        exit(EXIT_FAILURE);
    }
    Node *pNewNode;
    pNewNode = (Node *)malloc(sizeof(Node));
    copy_item_to_Node(item, pNewNode);
    pNewNode->next = NULL;
    if (is_empty(pQueue))
    {
        pQueue->front = pNewNode;
    }
    else
    {

        pQueue->rear->next = pNewNode;
        // TODO: delete testing
        fprintf(stdin, "pQueue->rear = %p", pQueue->rear);
        fprintf(stdin, "pQueue->rear->next = %p", pQueue->rear->next);
    }
    pQueue->rear = pNewNode;
    // TODO: delete testing
    fprintf(stdin, "pQueue->rear = %p", pQueue->rear);
    fprintf(stdin, "pQueue->rear->next = %p", pQueue->rear->next);
    pQueue->size++;
    return true;
}

bool left_pop(Queue *pQueue)
{
    if(is_empty(pQueue))
    {
        // TODO: delete test
        fprintf(stderr, "queue is empty.\n");
        return false;
    }
    Node *pTempNode;
    pTempNode = (*pQueue).front;
    pQueue->front = pQueue->front->next;
    free(pTempNode);
    pQueue->size--;
    if(pQueue->size == 0)
    {
        pQueue->rear = NULL;
    }
    return true;
}


void clean(Queue *pQueue)
{
    while(!is_empty(pQueue))
    {
        left_pop(pQueue);
    }
}