/************************** Dongguan-University of Technology -ACE**************************
 * @file Stack.c
 * @author pansyhou侯文辉 (1677195845lyb@gmail.com)
 * @brief 栈实现
 *        例子：回文字符串检验
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 ************************** Dongguan-University of Technology -ACE***************************/

#include "stdio.h"
#include "string.h"
int main(void)
{
    char a[101]; //存放字符串
    char stack[101];
    int i, len, mid, next, top;

    gets(a);           //获取字符串
    len = strlen(a);   //字符串长度获取
    mid = len / 2 - 1; //字符串中点获取

    top = 0; //栈的初始化
    for (i = 0; i <=mid; i++)
    {
        stack[++top] = a[i];
    }

    if (len % 2 == 0)
        next = mid + 1;
    else
        next = mid + 2;

    //开始匹配
    for (i = next; i <= len - 1; i++)
    {
        if (a[i] != stack[top])
            break;
        top--;
    }
    //如果top的值为0，则说明栈内所有的字符都被一一匹配了
    if (top == 0)
        printf("YES");
    else
        printf("NO");
}