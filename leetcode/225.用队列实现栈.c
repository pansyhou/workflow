/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include "stdbool.h"
#include "stdlib.h"
typedef struct{
    int *data;
    int rear;
    int head;
    int Size;
}Queue;

typedef struct {
    Queue *queue1;
    Queue *queue2;
} MyStack;

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
    obj->head=(obj->head+1)%obj->Size;//头指向后一个，
    return x;
    
}

bool QueueISempty(Queue *obj)
{
    return obj->head==-1;
}



MyStack* myStackCreate() {
    MyStack *obj=(MyStack *)malloc(sizeof(MyStack));
    obj->queue1=QueueInit(20);
    obj->queue2=QueueInit(20);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if(QueueISempty(obj->queue1))
    {
        QueuePush(obj->queue1,x);
    }
    else{
        QueuePush(obj->queue2,x);
    }
}

int myStackPop(MyStack* obj) {
    if(QueueISempty(obj->queue1))
    {
        while(obj->queue2->head!=obj->queue2->rear)
        {
            QueuePush(obj->queue1,QueueDel(obj->queue2));
        }
        return QueueDel(obj->queue2);
    }
    if(QueueISempty(obj->queue2))
    {
        while(obj->queue1->head!=obj->queue1->rear)
        {
            QueuePush(obj->queue2,QueueDel(obj->queue1));
        }
        return QueueDel(obj->queue1);
    }
    
}

int myStackTop(MyStack* obj) {
    if(QueueISempty(obj->queue1))
    {
        return (obj->queue2->data[obj->queue2->rear]);
    }
    return (obj->queue1->data[obj->queue1->rear]);
}

bool myStackEmpty(MyStack* obj) {
    if(obj->queue1->head==-1&&obj->queue2->head==-1)
    {
        return false;
    }
    return true;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1->data);
    obj->queue1->data=NULL;
    free(obj->queue1);
    obj->queue1=NULL;
    free(obj->queue2->data);
    obj->queue2->data=NULL;
    free(obj->queue2);
    obj->queue2=NULL;
    free(obj);
    obj=NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
// @lc code=end

