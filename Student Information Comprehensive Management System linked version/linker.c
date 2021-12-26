#include "linker.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief 动态内存分配，入口为指针，返回指针
 * 
 * @param q 
 * @return struct student* 
 */
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

/**
 * @brief 搜索是否含有相同学号
 * 
 * @param head 
 * @param num 
 * @return int 
 */

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


/**
 * @brief 该函数用于一开始的学生信息输入，包含学号查重功能
 * 
 * @param i(入口变量为学生人数) 
 * @return struct student* head
 */
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

/**
 * @brief 打印链表全部节点
 * 
 * @param head (入口为头地址)
 */

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
            printOneLinker(current);
            //printf("学号: %d\t 姓名: %s\t 总成绩: %d\n", current->id, current->name, current->sumMark);
            current = current->next;
        }
    }
}

/**
 * @brief 干掉已经分配的内存
 * 
 * @param head 
 */

void killmem(struct student *head)
{
    while (head != NULL)
    {
        free(head);
        head = head->next;
    }
}
/*好像没有用到这个呢*/
struct student *cpylinked(struct student *origin)
{
    static struct student *p;
    p = addmem(p);
    *p = *origin;
    return p;
}

/**
 * @brief 链表硬排序，以成绩降序为主
 * 
 * @param head 
 * @param stuNum1 
 * @return struct student* 
 */

struct student *sortLinked(struct student *head, int stuNum1)
{
    struct student *current;
    current = head;
    /*这里没有采用冒泡,因为比较麻烦所以没用，就直接暴力遍历了,直接swap*/
    for (int i = 0; i < stuNum1; i++)
    {
        current = head;
        for (int k = 0; k < stuNum1 - 1; k++)
        {
            if ((current->sumMark < current->next->sumMark) && current->next != NULL)
            {
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

/**
 * @brief 删除节点函数，原理是让目标节点的上一个节点的next指向目标节点的next，直接无视目标节点
 * 
 * @param preDeleteObject 
 * @param deleteObject 
 */

void deleteLinker(struct student *preDeleteObject, struct student *deleteObject)
{
    preDeleteObject->next = deleteObject->next;
    free(deleteObject);
}

void printOneLinker(struct student *object)
{
    printf("学号: %d\t 姓名: %s\t 总成绩: %d\n", object->id, object->name, object->sumMark);
}


/**
 * @brief 添加单个节点在末尾，返回头地址
 * 
 * @param head 
 * @param stuNum1 
 * @return struct student* head
 */
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