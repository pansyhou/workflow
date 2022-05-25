/************************** Dongguan-University of Technology -ACE**************************
 * @file Exp1_2.c
 * @author pansyhou侯文辉 (1677195845lyb@gmail.com)
 * @brief 顺序循环队列的基本操作
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 ************************** Dongguan-University of Technology -ACE***************************/
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
typedef struct{
    int *data;
    int rear;
    int head;
    int Size;
}Queue;

Queue* QueueInit(int capacity)//队列初始化
{
    Queue *ret=(Queue *)malloc(sizeof(Queue));
    ret->data=(int *)malloc(sizeof(int)*capacity);  
    ret->Size=capacity;
    ret->rear=-1;
    ret->head=-1;
    return ret;
}

void QueuePush(Queue *obj,int x)
{
    if(obj->head==-1)//当队列为空时
    {
        obj->head=0;
    }
    obj->rear=(obj->rear+1)%obj->Size;
    obj->data[obj->rear]=x;
}

int QueueDel(Queue *obj)
{
    int x=obj->data[obj->head];//暂存 头数据
    if(obj->rear==obj->head)//判断队列是否为空
    {
        obj->head=-1;
        obj->rear=-1;
        return x;
    }
    obj->head=(obj->head+1)%obj->Size;//头指向后一个
    return x;
    
}

bool QueueISempty(Queue *obj)
{
    return obj->head==-1;
}
//队列元素计算
int QueueSize(Queue *obj)
{
    return (obj->rear-obj->head+obj->Size)%obj->Size;
}


int main()
{
    int Queue_Capacity=40;
    //1.初始化一个队列Q
    Queue *Q=QueueInit(Queue_Capacity);
    //2.判断队列是否为空？
    bool Queue_is_empty=QueueISempty(Q);
    printf("Queue_is_empty=%d\n",Queue_is_empty);
    //3.入队操作
    for(int i=0;i<20;i++)
    {
        QueuePush(Q,i);
    }
    //4.出队操作
    for(int i=0;i<20;i++)
    {
        int x=QueueDel(Q);
        printf("x=%d\n",x);
    }

    //5.输出队列元素个数
    printf("Queue_Size=%d\n",QueueSize(Q));

    //6.入队四个元素
    for(int i=0;i<4;i++)
    {
        QueuePush(Q,i);
    }
    //7.出队四个元素
    for(int i=0;i<4;i++)
    {
        int x=QueueDel(Q);
        printf("x=%d\n",x);
    }
    return 0;

}