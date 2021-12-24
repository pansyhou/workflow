#include <stdio.h>
#include <string.h>//提供strcpy

#include <stdlib.h>//malloc

struct film
{
    char title [45];
    int rating;
    struct film *next;//这个指针用于指向下一个结构
    
};

int main()
{
    struct film *head=NULL;
    struct film *prev,*current;//head表示首地址，prev表示存入的下一个结构，current用于暂存下一个结构
    char input[45];//输入缓冲区

    /*收集并存储信息*/
    puts("输入第一部电影名");
    while(gets(input)!=NULL&&input[0]!='\0')
    {
        current=(struct film *)malloc(sizeof(struct film));//循环每一轮都会先开启一段内存
        if(head==NULL)//第一次循环，将第一部分的结构放入头地址/头结构
            head=current;
        else //后续的结构地址都会放入
            prev->next=current;//链表连接的重点
        current->next=NULL;
        strcpy(current->title,input);
        puts("输入你对它的打分");
        scanf("%d",&current->rating);
        while (getchar()!='\n')
        {
            continue;
        }
        puts("输入下一个电影名");
        prev=current;//暂存的current正式放入prev
    }

    /*给出电影列表*/
    if(head==NULL)
        puts("没有电影录入");
    else 
        printf("这里是电影列表:\n");
    current=head;//暂存指向头结构开始经历
    while (current!=NULL)
    {
        printf("电影: %s 打分: %d\n",current->title,current->rating);
        current=current->next;
    }
    /*任务完成,释放内存*/
    current=head;
    while (current!=NULL)
    {
        free(current);
        current=current->next;
    }
    return 0;
}

