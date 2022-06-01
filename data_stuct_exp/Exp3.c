/************************** Dongguan-University of Technology -ACE**************************
 * @file Exp3.c
 * @author pansyhou侯文辉 (1677195845lyb@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 ************************** Dongguan-University of Technology -ACE***************************/
#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "stdbool.h"
typedef struct{
    char data;
    struct Node *pleft;
    struct Node *pright;
}Node;

//队列实现
typedef struct{
    Node **data;
    int rear;
    int head;
    int Size;
}Queue;

//队列创建
Queue* QueueInit(int capacity)
{
    Queue *ret=(Queue *)malloc(sizeof(Queue));
    ret->data=(Node **)malloc(sizeof(Node *)*capacity);  
    ret->Size=capacity;
    ret->rear=-1;
    ret->head=-1;
    return ret;
}

//node queue pop
Node* QueuePop(Queue *obj)
{
    Node *x=obj->data[obj->head];//暂存 头数据
    if(obj->rear==obj->head)//判断队列是否为空
    {
        obj->head=-1;
        obj->rear=-1;
        return x;
    }
    obj->head=(obj->head+1)%obj->Size;//头指向后一个
    return x;
}


//node queue push
void QueuePush(Queue *obj,Node *x)
{
    if(obj->head==-1)//当队列为空时
    {
        obj->head=0;
    }
    obj->rear=(obj->rear+1)%obj->Size;
    obj->data[obj->rear]=x;
}

//QueueISempty
bool QueueISempty(Queue *obj)
{
    return obj->head==-1;
}
//queue 数量
int QueueSize(Queue *obj)
{
    return (obj->rear-obj->head+obj->Size+1)%obj->Size;
}




Node* CreatNode(char value){
    Node *pnode = (Node *)malloc(sizeof(Node));
    pnode->data = value;
    pnode->pleft = pnode->pright = NULL;
    return pnode;
}

Node *addnode(char value,Node *pnode)
{
    if(pnode == NULL)
        return CreatNode(value);

    if(value == pnode->data)
    {
        return pnode;
    }

    if(value < pnode->data)
    {
        if(pnode->pleft == NULL)
        {
            pnode->pleft = CreatNode(value);
            return pnode->pleft;
        }
        else
        {
            return addnode(value, pnode->pleft);
        }
    }
    else
    {
        if(pnode->pright == NULL)
        {
            pnode->pright = CreatNode(value);
            return pnode->pright;
        }
        else
        {
            return addnode(value, pnode->pright);
        }
    }
}

//后序遍历
void postorder(Node *pnode)
{
    if(pnode == NULL)
        return;
    postorder(pnode->pleft);
    postorder(pnode->pright);
    printf("%c ",pnode->data);
}

//层序遍历
void levelorder(Node *pnode)
{
    Queue *q = QueueInit(100);
    QueuePush(q,pnode);
    while(!QueueISempty(q))
    {
        int num=QueueSize(q);
        for(int i=0;i<num;i++)
        {
            Node *p = QueuePop(q);
            printf("%c ",p->data);
            if(p->pleft != NULL)
                QueuePush(q,p->pleft);
            if(p->pright != NULL)
                QueuePush(q,p->pright);
        }
        printf("\n");
    }
}

int TreeDepth(Node *pnode)
{
    if(pnode == NULL)
        return 0;
    int left = TreeDepth(pnode->pleft);
    int right = TreeDepth(pnode->pright);
    return left>right?left+1:right+1;
}
//输出树T的叶子结点
void PrintLeaf(Node *pnode)
{
    if(pnode == NULL)
        return;
    if(pnode->pleft == NULL && pnode->pright == NULL)
        printf("%c ",pnode->data);
    PrintLeaf(pnode->pleft);
    PrintLeaf(pnode->pright);
}

//输出非叶子结点
void PrintNOTLeaf(Node *pnode){
    if(pnode == NULL)
        return;
    if(pnode->pleft == NULL && pnode->pright == NULL)
        return;
    PrintNOTLeaf(pnode->pleft);
    PrintNOTLeaf(pnode->pright);
    printf("%c ",pnode->data);
}


int main(void){
    char newvalue;
	Node *proot = NULL;
	char answer = 'n';
	do
	{
		printf("Enter the node value:\n");
        scanf(" %c", &newvalue);
		if(proot == NULL)
		{
			proot = CreatNode(newvalue);
		}
		else
		{
			addnode(newvalue, proot);
		}
		printf("\nDo you want to enter another (y or n)? ");
		scanf(" %c", &answer);
	} while(tolower(answer) == 'y');

    printf("后序遍历：");
    postorder(proot);
    printf("\n");
    printf("层序遍历：\n");
    levelorder(proot);
    printf("\n");
    printf("树的深度：%d\n",TreeDepth(proot));
    printf("叶子结点：");
    PrintLeaf(proot);
    printf("\n");
    printf("非叶子结点：");
    PrintNOTLeaf(proot);
    printf("\n");

}

