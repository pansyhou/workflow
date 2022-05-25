/************************** Dongguan-University of Technology -ACE**************************
 * @file Exp1_1.c
 * @author pansyhou侯文辉 (1677195845lyb@gmail.com)
 * @brief 一元多项式的操作
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 ************************** Dongguan-University of Technology -ACE***************************/
#include "stdio.h"
#include "stdlib.h"

typedef struct LinkNode {
    int coefficient;//系数
    int index;      //指数
    struct LinkNode *next;//指向下一个节点
}LinkNode;

typedef struct {
    LinkNode *head;//链表头
    LinkNode *tail;//链表尾
    int LikeSize;//链表大小
}Linker;

Linker *LinkNodeInit(void) {
    Linker *l = (Linker *)malloc(sizeof(Linker));
    l->head = 0;
    l->tail = 0;
    l->LikeSize = 0;
    return l;
}

//多项式链表建立
Linker *NewLinkNode(Linker *obj)
{
    LinkNode *obj1=(LinkNode*)malloc(sizeof(LinkNode));
    LinkNode *temp=obj->head;
    printf("输入系数和指数：");
    scanf("%d%d",&obj1->coefficient,&obj1->index);
    obj1->next=NULL;
    if(obj->head==0)
    {
        obj->head=obj1;
        obj->tail=obj1;
        obj->LikeSize++;
    }
    else
    {
        while(temp!=NULL)
        {
            if(obj1->index==temp->index)
            {
                temp->coefficient+=obj1->coefficient;
                return obj;
            }
            temp=temp->next;
        }
        obj->tail->next=obj1;
        obj->tail=obj1;
        obj->LikeSize++;
    }
    return obj;
}

LinkNode* merge(LinkNode* head1, LinkNode* head2) {
    LinkNode* dummyHead = malloc(sizeof(LinkNode));
    dummyHead->index = 0;
    LinkNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->index <= temp2->index) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != NULL) {
        temp->next = temp1;
    } else if (temp2 != NULL) {
        temp->next = temp2;
    }
    return dummyHead->next;
}

LinkNode* toSortList(LinkNode* head, LinkNode* tail) {
    if (head == NULL) {
        return head;
    }
    if (head->next == tail) {
        head->next = NULL;
        return head;
    }
    LinkNode*slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    LinkNode* mid = slow;
    return merge(toSortList(head, mid), toSortList(mid, tail));
}

LinkNode* sortList(LinkNode* head) {
    return toSortList(head, NULL);
}

//链表相加
LinkNode *AddLinkNode(LinkNode *NodeHead1,LinkNode *NodeTail1,LinkNode *NodeHead2,LinkNode *NodeTail2)
{
    sortList(NodeHead1);
    sortList(NodeHead2);
    LinkNode *temp1=NodeHead1;
    LinkNode *temp2=NodeHead2;
    LinkNode *obj=(LinkNode*)malloc(sizeof(LinkNode));
    LinkNode *NodeHead3=obj;
    if(NodeHead1->next==NULL)
    {
        obj->next=(LinkNode*)malloc(sizeof(LinkNode));
        obj->coefficient=temp1->coefficient;
        obj->index=temp1->index;
        obj->next=NULL;
    }
    //思路：将链表1复制到3，然后将2的插入到3里
    while(temp1!=NULL)
    {
            obj->next=(LinkNode*)malloc(sizeof(LinkNode));
            obj->coefficient=temp1->coefficient;
            obj->index=temp1->index;
            if(temp1->next==NULL)
            {
                obj->next=NULL;
            }else obj=obj->next;
            temp1=temp1->next;
    }
    obj->next=NULL;
    obj=NodeHead3;
    while(temp2!=NULL)
    {
        if(temp2->index==obj->index)
        {
            obj->coefficient=obj->coefficient+temp2->coefficient;
            temp2=temp2->next;
            obj=obj->next;
        }else if(obj->next!=NULL){
            obj=obj->next;
        }
        else
        {
            LinkNode* temp4=obj->next;//暂存下下个节点
            obj->next=(LinkNode*)malloc(sizeof(LinkNode));
            obj->next->coefficient=temp2->coefficient;
            obj->next->index=temp2->index;
            obj=obj->next;
            obj->next=temp4;
            temp2=temp2->next;
        }


    }
    // obj->next=NULL;
    sortList(NodeHead3);
    return NodeHead3;
}

//多项式输出
void PrintLinkNode(LinkNode *NodeHead)
{
    LinkNode *temp=NodeHead;
    while(temp!=NULL)
    {   
        
        printf("%dX^%d",temp->coefficient,temp->index);
        temp=temp->next;
        if(temp!=NULL&&temp->coefficient>=0)
        {
            printf("+");
        }
        else if(temp!=NULL&&temp->coefficient<0)
        {
            printf("");
        }
    }
    printf("\n");
}


//计算多项式
int CalculateLinkNode(LinkNode *NodeHead,int x)
{
    LinkNode *temp=NodeHead;
    double sum=0;
    while(temp!=NULL)
    {   
        
        printf("%dX^%d",temp->coefficient,temp->index);
        sum=(double)sum+temp->coefficient*pow(x,temp->index);
        temp=temp->next;
        if(temp!=NULL&&temp->coefficient>=0)
        {
            printf("+");
        }
        else if(temp!=NULL&&temp->coefficient<0)
        {
            printf("");
        }
    }
    printf("=%f\n",sum);
    printf("\n");
}


void main(void)
{
    Linker *Node1=LinkNodeInit();
    Linker *Node2=LinkNodeInit();
    printf ("初始化多项式1：\n");
    Node1=NewLinkNode(Node1);
    printf("初始化多项式2：\n");
    Node2=NewLinkNode(Node2);
    // PrintLinkNode(NodeHead3);
    LinkNode *NodeHead3=NULL;
    while(1)
    {   
        int choice;
        printf("请输入数字进行对应操作\n");
        printf("1：多项式1插入元素\n");
        printf("2：多项式2插入元素\n");
        printf("3：多项式相加\n");
        printf("4：打印多项式1\n");
        printf("5：打印多项式2\n");
        printf("6：打印多项式3\n");
        printf("7：多项式1排序\n");
        printf("8：多项式2排序\n");
        printf("9：计算多项式\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:{
                Node1=NewLinkNode(Node1);
                break;
            }
            case 2:{
                Node2=NewLinkNode(Node2);
                break;
            }
            case 3:{
                NodeHead3=AddLinkNode(Node1->head,Node1->tail,Node2->head,Node2->tail);
                PrintLinkNode(NodeHead3);
                break;
            }
            case 4:{
                PrintLinkNode(Node1->head);
                break;
                }
            case 5:{
                PrintLinkNode(Node2->head);
                break;
                }
            case 6:{
                PrintLinkNode(NodeHead3);
                break;
                }
            case 7:{
                sortList(Node1->head);
                break;
                }
            case 8:{
                sortList(Node2->head);
                break;
                
                }
            case 9:{
                int choice2;
                int x=0;
                printf("计算哪个多项式（1-3）\n");
                scanf("%d",&choice2); 
                printf("输入x的值\n");
                scanf("%d",&x);
                switch (choice2)
                {
                    case 1:{
                        CalculateLinkNode(Node1->head,x);
                        break;
                    }
                    case 2:{
                        CalculateLinkNode(Node2->head,x);
                        break;
                    }
                    case 3:{
                        CalculateLinkNode(NodeHead3,x);
                        break;
                    }
                    default:{
                        printf("输入错误\n");
                    }
                }
                break;
            }
            default:{
                printf("输入错误，请重新输入\n");
                break;
            }
        }
        
    }
}
