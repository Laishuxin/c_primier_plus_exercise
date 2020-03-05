#include "17.list_copy.h"
static void copy_to_node(Item, Node *pNode);

void initialize_list(List *pList)
{
    *pList = NULL;
}

bool list_is_empty(const List *pList)
{
    if (*pList)
    {
        return false;
    }
    return true;
}

bool list_is_full(const List *pList)
{
    Node *pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if (pt)
    {
        full = false;
    }
    else
    {
        full = true;
    }
    free(pt);
    return full;
}

unsigned int list_item_count(const List *pList)
{
    unsigned int count = 0;
    Node *tempNode;
    tempNode = *pList;
    while (tempNode)
    {
        count++;
        tempNode = tempNode->next;
    }
    return count;
}

bool    add_item(Item item, List *pList)
{
    Node *pNewNode;
    Node *pCurNode = *pList;
    pNewNode = (Node *)malloc(sizeof(Node));
    if (pNewNode == NULL)
    {
        return false;
    }
    copy_to_node(item, pNewNode);
    pNewNode->next = NULL;
    if (pCurNode == NULL)
    {
        *pList = pNewNode;
    }
    else
    {
        while (pCurNode->next)
        {
            pCurNode = pCurNode->next;
        }
        pCurNode->next = pNewNode;
    }
    return true;
}

void traverse(const List *pList, void (*pf)(Item item))
{
    Node* tempNode = *pList;
    while(tempNode)
    {
        (*pf)(tempNode->m_item);
        tempNode = tempNode->next;
    }
}
void empty_list(List *pList)
{
    Node *tempNode;
    while (pList)
    {
        tempNode = (*pList)->next;
        free(pList);
        *pList = tempNode;
    }
}

static void copy_to_node(Item item, Node* pNode)
{
    pNode->m_item = item;
}