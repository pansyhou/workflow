#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linker.h" //添加自己写的linker头文件

//对了！！！！如果只运行这个zonghe.c的话可能运行不了，直接打开exe看我的说明



void start(void);
void change(void);
void delete (void);
void browse(void);
void sort(void);
void search(void);
void statistics(void);
int startMenu(void);
void wannasay(void);
void saveData(void);
int stuNum = 0;
struct student *head = NULL;//head全局变量哦

int main()
{
    start();
    while (1)
    {
        if (startMenu()==9)//startMenu会返回我输入的值，如果为9直接退出
    {
        printf("exit successfully!");
        saveData();
        killmem(head);
        break;
    }
    }
}
void start(void)//启动画面,包含最开始的学生信息输入
{
    printf("------------------------------------------------------------\n");
    printf("----------------欢迎来到学生信息管理系统V2.0----------------\n");
    printf("---------------------如有卡顿请回车一下---------------------\n");
    printf("---------------------有bug也请原谅一下----------------------\n");
    printf("---------如果整个文件夹丢进vs或者devc++啥的运行不了---------\n");
    printf("------------请把linker.c里的函数、头文件丢进zonghe----------\n");
    printf("------------------------------------------------------------\n");
    Delay(0xffffffff);//delay延迟

    system("cls");
    printf("------------------------------------------------------------\n");
    printf("----------------------V2.0版本更新内容----------------------\n");
    printf("---------------------数据结构更改为链表---------------------\n");
    printf("-------------------支持数据导出至data.txt-------------------\n");

    printf("------------------------------------------------------------\n");
    Delay(0xffffffff);

    system("cls");
    printf("------------------------------------------------------------\n");
    printf("---------------------输入学生信息以开始---------------------\n");
    printf("------------------------------------------------------------\n");
    printf("请输入学生个数:");
    scanf("%d", &stuNum);
    head = addlinker(stuNum);//这里=可以右键addlinker看这个函数的声明或者定义
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
    printf("---------------------8-作者想说的话-------------------------\n");
    printf("----------------9-退出查询系统并保存数据--------------------\n");
    printf("------------------------------------------------------------\n");
    int fun_Num = 0;
    scanf("%d", &fun_Num);
    switch (fun_Num)
    {
    case (1):
        head=addSinglelinker(head,&stuNum);//添加单个节点
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
    case (7):
        statistics();
        system("cls");
        break;
    case (8):
        wannasay();
        system("cls");
        break;
    case (9):
        break;
    default:
        puts("输入信息有误哦");
        Delay(0xffffffff);
        break;
    }
    system("cls");
    return fun_Num;
}
void change(void)
{
    int flag = 1;
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
            (stuNum)--;
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
        printOneLinker(current);
        puts("输出#以退出");
        while(getchar()!='#');
    }
    return 0;
}

void statistics(void)
{
    struct student *current;
    current=head;
    int sum=0,i=0;
    while(current->next!=NULL)
    {
        sum+=current->sumMark;
        i++;
        current=current->next;
    }
    double avg=sum/i;
    printf("平均分= %.2f\n",avg);
    puts("输出#以退出");
    while(getchar()!='#');
}

void wannasay(void)
{
    puts("  其实你综合看代码看下来其实会很乱，因为linker,c里写了一些关于链表的操作，但是\n主的c文件zonghe.c又有一些是关于链表的操作，少量，但是也多。\n");
    puts("  一开始有着对程序架构的完美蓝图，但是在具体写程序的时候你会发现，不\n实际。还是要多加练习，真的就是不熟练，对变量的生命周期一点都不熟悉，调试了两\n个下午，直到周六晚上突破了变量的问题才开始写主函数。\n");
    puts("  写完这个项目之后不禁感叹，想去搞项目了，只有项目才能摆脱很多坏习惯，比\n如变量名乱写（看我的变量，是不是全是什么head/prev/before/current之类的，虽\n然说方便我移植，但是要是在项目里说不定会被打死，太多重名的了。而且注释也不\n写完全=>   By pansyhou.\n");
    puts("输出#以退出");
    while(getchar()!='#');
}

void saveData(void)
{
    struct student *current;
    current=head;
    FILE *fp;
    int i;
    fp=fopen("data.txt","w");
    if(fp==NULL)
    {
        printf("文件打开失败...");
        exit (0);
    }

    for(i=0;i<stuNum;i++)
    {
        fprintf(fp,"学号: %d\t 姓名: %s\t 总成绩: %d\n", current->id, current->name, current->sumMark);
        current=current->next;
    }
    fclose(fp); 
}