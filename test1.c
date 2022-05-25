#include "stdio.h"

typedef struct
{
    int data;
    LinkList *next;
} LinkList;

void ListReverse_L(LinkList *L)
{
    int Size = 0;
    LinkList *temp = L;
    LinkList *temp2 = L;
    while (temp->next != NULL)
    {
        Size++; //计算链表节点个数
    }
    int n = Size / 2; //逆置操作次数
    for (; n > 0; n--)
    {
        temp = temp2; //让temp回到头结点开始遍历
        for (int i = 0; i < Size; i++)
        {
            temp = temp->next;
        }
        int t = temp->data; //前后逆置
        temp->data = L.data;
        L.data = t;
        Size
    }
}