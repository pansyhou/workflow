#include "linker.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// struct student *addmem(struct student *q)
// {
//     q=(struct student *)malloc(sizeof(struct student));
//     if (q==NULL) 
//     {
//         printf("out of memory!");
//         exit(1);
//     }
//     else return q;
// }

// void addlinker(struct student *head,struct student *prev,struct student *current)
// {
//     if(head==NULL)//将第一部分的结构放入头地址/头结构
//         head=current;
//     else//后续的结构地址都会放入
//         prev->next=current;
//     current->next=NULL;
//     // printf("请输入学号");
//     // scanf("%d",&current->id);
//     // printf("请输入姓名");
//     // scanf("%s",&current->name);
//     // printf("请输入学生总成绩");
//     // scanf("%d",&current->sumMark);
    
//     puts("请输入学号、姓名、总成绩(回车结束)");
//     scanf("%d %s %d",&current->id,&current->name,&current->sumMark);
//     prev=current;//尾插法 暂存的current正式放入prev
//     // current=current->next;
// }

void printAllLinked(struct student *head)
{
    struct student *current;
    current=addmem(current);
    if(head==NULL) puts("没有学生信息喔？");
    else
    {
        puts("这里是学生信息");
        while (current!=NULL)
        {
            printf("学号: %d/t 姓名: %s/t 总成绩: %d",current->id,current->name,current->sumMark);
            current=current->next;
        }
    }
}

void killmem(struct student *head)
{
    while(head!=NULL)
    {
        free(head);
        head=head->next;
    }
}

student * cpylinked(struct student *origin)
{
    static struct student *p;
    p=addmem(p);
    *p=*origin;
    return p;
}

void sortLinked(struct student *head)
{
    struct student *current;
    current=head;
    while(current->next!=NULL)
    {
        if (current->sumMark<current->next->sumMark)
        {
            // student *p=cpylinked(current); //纯傻子了，还想结构互换来着
            // p->next=current->next;
            // current->next=p;

            /*current copy到temp*/
            int temp1=current->id,temp3=current->sumMark;
            char temp2[15];
            strcpy(temp2,current->name);

            /*next copy到current*/
            current->id=current->next->id;
            strcpy(current->name,current->next->name);
            current->sumMark=current->next->sumMark;

            /*temp copy到current.next*/
            current->next->id=temp1;
            strcpy(current->next->name,temp2);
            current->next->sumMark=temp3;
        }
        current=current->next;
    }
}

void deleteLinker(struct student *preDeleteObject,struct student *deleteObject)
{
    preDeleteObject->next=deleteObject->next;
    free(deleteObject);
}

void printOneLinker(struct student *object)
{
    printf("学号: %d/t 姓名: %s/t 总成绩: %d",object->id,object->name,object->sumMark);
}