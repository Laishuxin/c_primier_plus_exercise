#include <stdio.h>
#include <stdlib.h>
#include "list.h"


static void copy_to_node(Item item, Node* pNode);

/*将链表初始化为空链表*/
void initialize_list(List* pList)
{
    *pList = NULL;
}

/*判断链表是否为空链表*/
bool list_is_empty(const List* pList)
{
    if (*pList == NULL)
        return true;
    return false;
}

/*判断链表是否满了*/
bool list_is_full(const List* pList)
{
    Node* pt;
    bool full;
    pt = (Node*)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
    {
        full = false;
        free(pt);
    }
    return full;
}

/*计算链表中的条目*/
unsigned int list_item_count(const List* pList)
{
    unsigned int count = 0;
    Node* pNode = *pList;
    while (pNode != NULL)
    {
        count++;
        pNode = pNode->next;
    }
    return count;
}

/*添加item，成功返回true*/
/*Item item : 要添加的条目信息*/
bool add_item(Item item, List* pList)
{
    Node* pNewNode;
    Node* pScan = *pList;
    pNewNode = (Node*)malloc(sizeof(Node));

    // 分配不到空间
    if (pNewNode == NULL)
    {
        return false;
    }
    copy_to_node(item, pNewNode);
    pNewNode->next = NULL;


    // 传进入的是空链表，所以把新创建的链表作为表头
    if (pScan == NULL)
    {
        *pList = pNewNode;
    }
    else
    {
        while (pScan->next)
        {
            pScan = pScan->next;
        }
        pScan->next = pNewNode;

    }
    return true;
}

/*对链表中的每一项执行函数*pf */
void traverse(const List* pList, void (*pf)(Item item))
{
    Node* pNode = *pList;
    while (pNode != NULL)
    {
        (*pf)(pNode->item);
        pNode = pNode->next;
    }
}

/*释放内存*/
void empty_list(List* pList)
{
    Node* pSave;
    while (*pList != NULL)
    {
        // 保存下一个 节点，因为释放节点后就无法访问下一个节点
        pSave = (*pList)->next;
        // 释放当前节点
        free(*pList);
        *pList = pSave;

    }
}

static void copy_to_node(Item item, Node* pNode)
{
    pNode->item = item;

}