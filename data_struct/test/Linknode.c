/************************** Dongguan-University of Technology -ACE**************************
 * @file Linknode.c
 * @author pansyhou侯文辉 (1677195845lyb@gmail.com)
 * @brief 利用链表进行比赛记录，既可以实现无限的比赛过程记录，
 *        同时数据域灵活，可通过链表节点结构体改动实现，下面只写了相对应的
 *        操作函数，实现比赛记录调用即可
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 ************************** Dongguan-University of Technology -ACE***************************/
#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int hang;
    int lie;
    int color;
    LinkNode *next;
}LinkNode;

typedef struct
{
    LinkNode *head;
    LinkNode *tail;
    int LikeSize;
}Linker;


Linker *LinkNodeInit(void)
{
    Linker * l=(Linker *)malloc(sizeof(Linker));
    l->head=0;
    l->tail=0;
    l->LikeSize=0;
    return l;
}

LinkNode * addLinkNode(int hang,int lie ,int color)
{
    LinkNode *obj=(LinkNode*)malloc(sizeof(LinkNode));
    obj->hang=hang;
    obj->lie=lie;
    obj->color=color;
    obj->next=NULL;
    return obj;
}

void addOperation(Linker *obj,int hang,int lie ,int color)
{
    if(obj->head==0)
    {
        obj->head=addLinkNode(hang,lie,color);
        obj->LikeSize++;
    }
    else
    {
        LinkNode *l=obj->head;
        for(int i=0;i<obj->LikeSize;i++)
        {
            l=l->next;
        }
        l=addLinkNode(hang,lie,color);
        obj->LikeSize++;

    }
}

