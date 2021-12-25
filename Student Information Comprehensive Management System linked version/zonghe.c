#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linker.h"
void start(void);
void change(void);
void delete (void);
void browse(void);
void sort(void);
void search(void);
void statistics(void);
int startMenu(void);
int stuNum = 0;
struct student *head = NULL;
int main()
{
    start();
    while (1)
    {
        if (startMenu()==8)
    {
        printf("exit successfully!");
        break;
    }
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
    // Delay(0xffffffff);
    printf("请输入学生个数:");
    scanf("%d", &stuNum);
    head = addlinker(head,stuNum);
    system("cls");
}

int startMenu(void)
{
    printf("------------------------------------------------------------\n");
    printf("-----------------请输入对应数字实现对应功能-----------------\n");
    printf("---------------------1-增加学生信息-------------------------\n");
    printf("---------------------2-修改学生信息-------------------------\n");
    printf("---------------------3-删除学生信息-------------------------\n");
    printf("---------------------4-浏览学生信息-------------------------\n");
    printf("---------------------5-查找学生信息-------------------------\n");
    printf("---------------------6-排序学生信息-------------------------\n");
    printf("---------------------7-统计学生信息-------------------------\n");
    printf("---------------------8-退出查询系统-------------------------\n");
    printf("------------------------------------------------------------\n");
    int fun_Num = 0;
    scanf("%d", &fun_Num);
    switch (fun_Num)
    {
    case (1):
        head=addSinglelinker(head,&stuNum);
        system("cls"); //清楚显示内容函数
        break;
    case (2):
        change();
        system("cls");
        break;
    case (3):
        delete();
        system("cls");
        break;
    case (4):
        printAllLinked(head);
        puts("输出#以退出");
        while(getchar()!='#');
        break;
    case (5):
        search();
        system("cls");
        break;
    case (6):
        head=sortLinked(head,stuNum);
        system("cls");
        break;
    // case (7):
        
    //     system("cls");
    //     break;
    default:
        break;
    }
    system("cls");
    return fun_Num;
}
void change(void)
{
    struct student *current;
    current=head;
    int stu=0;
    puts("请输入该学生的学号");
    scanf("%d",&stu);
    while(stu!=current->id&&current->next!=NULL)
    {
        current=current->next;
    }
    if(stu!=current->id)
    {
        system("cls");
        printf("没有找到学生信息喔");
        Delay(0xffffffff);
        system("cls");
        return 0;
    }
    else
    {
        puts("请输入学号、姓名、总成绩(回车结束)");
        scanf("%d %s %d", &current->id, current->name, &current->sumMark);
    }
    return 0;
}

void delete (void)
{
    struct student *current;
    struct student *before;
    current=head;
    int stu=0;
    puts("请输入该学生的学号");
    scanf("%d",&stu);
    if (head->id==stu)
    {
        before=head;
        head=head->next;
        free(before);
    }
    else
    {
        while(stu!=current->id&&current->next!=NULL)
        {
            before=current;
            current=current->next;
        }
        if(stu!=current->id)
        {
            system("cls");
            printf("没有找到学生信息喔\n");
            puts("输出#以退出");
        while(getchar()!='#');
            system("cls");
            return 0;
        }
        else
        {
            before->next=current->next;
            free(current);
        }
        puts("删除成功!\n");
        puts("输出#以退出");
        while(getchar()!='#');
    }
}

void search(void)
{
    struct student *current;
    current=head;
    int stu=0;
    puts("请输入该学生的学号");
    scanf("%d",&stu);
    while(stu!=current->id&&current->next!=NULL)
    {
        current=current->next;
    }
    if(stu!=current->id)
    {
        system("cls");
        printf("没有找到学生信息喔\n");
        puts("输出#以退出");
        while(getchar()!='#');
        system("cls");
        return 0;
    }
    else
    {
        printf("学号: %d\t 姓名: %s\t 总成绩: %d\n", current->id, current->name, current->sumMark);
        puts("输出#以退出");
        while(getchar()!='#');
    }
    return 0;
}