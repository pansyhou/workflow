/************************** Dongguan-University of Technology -ACE**************************
 * @file queue.c
 * @author pansyhou侯文辉 (1677195845lyb@gmail.com)
 * @brief 队列实现
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 ************************** Dongguan-University of Technology -ACE***************************/

typedef struct Queue
{
    int data[10];
    int head;//队首
    int tail;//队尾
}Queue;

//队列变量声明
Queue queue;
int main()
{   
    //队列初始化
    queue.head=1;
    queue.tail=1;

    int i=0;
    
}