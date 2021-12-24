#include <linker.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

student *addmem(student *q)
{
    student *p;
    p=(student *)malloc(sizeof(student));
    if (p==NULL) 
    {
        printf("out of memory!");
        exit(1);
    }
    else return p;
}

void addlinker(student *head,student *prev,student *current)
{
    current=addmem(current);
    if(head==NULL)//将第一部分的结构放入头地址/头结构
        head=current;
    else//后续的结构地址都会放入
        prev=current;
    current->next=NULL;
    printf("请输入学号");
    scanf("%d",&current->id);
    printf("请输入姓名");
    gets(current->name);
    printf("请输入学生总成绩");
    scanf("%d",&current->sumMark);
    prev=current;//尾插法 暂存的current正式放入prev
}

void printlLinked(student *head)
{
    student *current;
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

void killmem(student *head)
{
    while(head!=NULL)
    {
        free(head);
        head=head->next;
    }
}

student * cpylinked(student *origin)//我也不知道有什么用
{
    static student *p;
    p=addmem(p);
    *p=*origin;
    return p;
}

void sortLinked(student *head)
{
    student *current;
    current=head;
    if (current->sumMark<current->next->sumMark)
    {
        student *p=cpylinked(current);
        p->next=current->next;
        current->next=p;
    }
}