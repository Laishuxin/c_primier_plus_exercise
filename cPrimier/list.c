#include <stdio.h>
#include <stdlib.h>
#include "list.h"


static void copy_to_node(Item item, Node* pNode);

/*�������ʼ��Ϊ������*/
void initialize_list(List* pList)
{
    *pList = NULL;
}

/*�ж������Ƿ�Ϊ������*/
bool list_is_empty(const List* pList)
{
    if (*pList == NULL)
        return true;
    return false;
}

/*�ж������Ƿ�����*/
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

/*���������е���Ŀ*/
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

/*���item���ɹ�����true*/
/*Item item : Ҫ��ӵ���Ŀ��Ϣ*/
bool add_item(Item item, List* pList)
{
    Node* pNewNode;
    Node* pScan = *pList;
    pNewNode = (Node*)malloc(sizeof(Node));

    // ���䲻���ռ�
    if (pNewNode == NULL)
    {
        return false;
    }
    copy_to_node(item, pNewNode);
    pNewNode->next = NULL;


    // ��������ǿ��������԰��´�����������Ϊ��ͷ
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

/*�������е�ÿһ��ִ�к���*pf */
void traverse(const List* pList, void (*pf)(Item item))
{
    Node* pNode = *pList;
    while (pNode != NULL)
    {
        (*pf)(pNode->item);
        pNode = pNode->next;
    }
}

/*�ͷ��ڴ�*/
void empty_list(List* pList)
{
    Node* pSave;
    while (*pList != NULL)
    {
        // ������һ�� �ڵ㣬��Ϊ�ͷŽڵ����޷�������һ���ڵ�
        pSave = (*pList)->next;
        // �ͷŵ�ǰ�ڵ�
        free(*pList);
        *pList = pSave;

    }
}

static void copy_to_node(Item item, Node* pNode)
{
    pNode->item = item;

}