/*
 * @lc app=leetcode.cn id=232 lang=c
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include "stdbool.h"
#include "stdlib.h"

typedef struct {
    int *stk;
    int stkSize;
    int stkCapacity;
} Mystk;

typedef struct {
    Mystk *inStk;
    Mystk *outStk;
} MyQueue;

//栈操作部分
void stkPush(Mystk *obj,int x)
{
    obj->stk[obj->stkSize++]=x;
}

void stkPop(Mystk *obj)
{
    obj->stkSize--;
}

int stkTop(Mystk *obj)
{
    return obj->stk[obj->stkSize-1];
}

bool stkEmpty(Mystk *obj)
{
    return obj->stkSize==0;
}

void stkFree(Mystk *obj)
{
    free(obj->stk);
}


void in2out(MyQueue *obj)
{
    while (!stkEmpty(obj->inStk))
    {
        stkPush(obj->outStk,stkTop(obj->inStk));
        stkPop(obj->inStk);
    }
}

Mystk *stkCreat(int capacity)
{
    Mystk *ret=(Mystk *)malloc(sizeof(Mystk));
    ret->stk=malloc(sizeof(int)*capacity);
    ret->stkCapacity=capacity;
    ret->stkSize=0;
    return ret;
}



MyQueue* myQueueCreate() {
    MyQueue *ret=(MyQueue *)malloc(sizeof(MyQueue));

    ret->inStk=stkCreat(100);
    ret->outStk=stkCreat(100);

    return ret;
}

void myQueuePush(MyQueue* obj, int x) 
{
    stkPush(obj->inStk,x);
}

int myQueuePop(MyQueue* obj) 
{
    if (stkEmpty(obj->outStk))
    {
        in2out(obj);
    }
    int x=stkTop(obj->outStk);
    stkPop(obj->outStk);
    return x;
    
}

int myQueuePeek(MyQueue* obj) {
    if(stkEmpty(obj->outStk))
    {
        in2out(obj);
    }
    return stkTop(obj->outStk);
}

bool myQueueEmpty(MyQueue* obj) {
    return stkEmpty(obj->inStk)&&stkEmpty(obj->outStk);
}

void myQueueFree(MyQueue* obj) {
    stkFree(obj->inStk);
    stkFree(obj->outStk);
}



/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
// @lc code=end


