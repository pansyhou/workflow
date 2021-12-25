#include "linker.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct student *addmem(struct student *q)
{
    q = (struct student *)malloc(sizeof(struct student));
    if (q == NULL)
    {
        printf("out of memory!");
        exit(1);
    }
    else
        return q;
}

int seachTheSame(struct student *head, int num)
{
    int flag=0;
    struct student *current;
    current = head;
    while ( current->next != NULL)
    {
        if (num != current->id)
        {
            flag= 0;
        }
        else
        {
            return 1;
        }
        current = current->next;
    }
    return flag;
}

void Delay(int nCount)
{
    for (; nCount != 0; nCount--)
        ; //原理是让cpu计数，空载，cpu算完就算一段延迟
}

struct student *addlinker(int i)
{
    
    struct student *head1 = NULL;
    for (int stuNum; stuNum < i; stuNum++)
    {
        int flag = 1;
        struct student *prev;
        struct student *current;
        current = addmem(current);
        if (head1 == NULL) //将第一部分的结构放入头地址/头结构
            head1 = current;
        else //后续的结构地址都会放入
            prev->next = current;
        current->next = NULL;
        puts("请输入学号、姓名、总成绩(回车结束)");
        do
        {
            scanf("%d %s %d", &current->id, current->name, &current->sumMark);
            if (seachTheSame(head1, current->id))
            {
                puts("已经存在该学生了喔,重新输入吧");
            }
            else
                flag = 0;
        } while (flag);
        prev = current; //尾插法 暂存的current正式放入prev
    }
    return head1;
}

void printAllLinked(struct student *head)
{
    struct student *current = head;
    if (head == NULL)
        puts("没有学生信息喔？");
    else
    {
        puts("这里是学生信息");
        while (current != NULL)
        {
            printf("学号: %d\t 姓名: %s\t 总成绩: %d\n", current->id, current->name, current->sumMark);
            current = current->next;
        }
    }
}

void killmem(struct student *head)
{
    while (head != NULL)
    {
        free(head);
        head = head->next;
    }
}

struct student *cpylinked(struct student *origin)
{
    static struct student *p;
    p = addmem(p);
    *p = *origin;
    return p;
}

struct student *sortLinked(struct student *head, int stuNum1)
{
    struct student *current;
    current = head;
    for (int i = 0; i < stuNum1; i++)
    {
        current = head;
        for (int k = 0; k < stuNum1 - 1; k++)
        {
            if ((current->sumMark < current->next->sumMark) && current->next != NULL)
            {
                // student *p=cpylinked(current); //纯傻子了，还想结构互换来着
                // p->next=current->next;
                // current->next=p;

                /*current copy到temp*/
                int temp1 = current->id, temp3 = current->sumMark;
                char temp2[15];
                strcpy(temp2, current->name);

                /*next copy到current*/
                current->id = current->next->id;
                strcpy(current->name, current->next->name);
                current->sumMark = current->next->sumMark;

                /*temp copy到current.next*/
                current->next->id = temp1;
                strcpy(current->next->name, temp2);
                current->next->sumMark = temp3;
            }
            current = current->next;
        }
    }
    return head;
}

void deleteLinker(struct student *preDeleteObject, struct student *deleteObject)
{
    preDeleteObject->next = deleteObject->next;
    free(deleteObject);
}

void printOneLinker(struct student *object)
{
    printf("学号: %d/t 姓名: %s/t 总成绩: %d", object->id, object->name, object->sumMark);
}

struct student *addSinglelinker(struct student *head, int *stuNum1)
{
    int flag=1;
    struct student *current;
    struct student *prev;
    struct student *before;
    current = head;
    prev = addmem(prev);
    while (current != NULL)
    {
        before = current;
        current = current->next;
    }
    (*stuNum1)++;
    before->next = prev;
    prev->next = NULL;
    puts("请输入学号、姓名、总成绩(回车结束)");
    do
        {
            scanf("%d %s %d", &prev->id, prev->name, &prev->sumMark);
            if (seachTheSame(head, prev->id))
            {
                puts("已经存在该学生了喔,重新输入吧");
            }
            else
                flag = 0;
        } while (flag);
    return head;
}