#include <stdio.h>
#include "linker.h"

void start(void);
void add(void);
void change(void);
void delete(void);
void browse(void);
void sort(void);
void search(void);
void statistics(void);
void Delay(int nCount)
{
  for(; nCount != 0; nCount--);//原理是让cpu计数，空载，cpu算完就算一段延迟
}
struct student *addmem(struct student *q)
{
    q=(struct student *)malloc(sizeof(struct student));
    if (q==NULL) 
    {
        printf("out of memory!");
        exit(1);
    }
    else return q;
}

void addlinker(struct student *head,struct student *prev,struct student *current)
{
    if(head==NULL)//将第一部分的结构放入头地址/头结构
        head=current;
    else//后续的结构地址都会放入
        prev->next=current;
    current->next=NULL;
    puts("请输入学号、姓名、总成绩(回车结束)");
    scanf("%d %s %d",&current->id,current->name,&current->sumMark);
    prev=current;//尾插法 暂存的current正式放入prev
}

int main()
{
    struct student *head=NULL;
    struct student *prev;
    struct student *current;
    start();
    int stuNum=0;
    scanf("%d",&stuNum);
    for(int i=0;i<stuNum;i++)
    {
      printf("%d",head);
      current=(struct student *)malloc(sizeof(struct student));
      addlinker(head,prev,current);
      printf("%d",head);
    }
}
void start(void)
{
    // printf("------------------------------------------------------------\n");
    // printf("-----------------欢迎来到学生信息管理系统V2.0-----------------\n");
    // printf("---------------------如有卡顿请回车一下---------------------\n");
    // printf("---------------------有bug也请原谅一下----------------------\n");
    // printf("------------------------------------------------------------\n");
    // Delay(0xffffffff);//delay延迟

    // system("cls");
    // printf("------------------------------------------------------------\n");
    // printf("----------------------V2.0版本更新内容-----------------------\n");
    // printf("---------------------数据结构更改为链表----------------------\n");
    // printf("------------------------------------------------------------\n");
    // Delay(0xffffffff);

    // system("cls");
    printf("------------------------------------------------------------\n");
    printf("---------------------输入学生信息以开始---------------------\n");
    printf("------------------------------------------------------------\n");
    //Delay(0xffffffff);
    printf("请输入学生个数:");
}