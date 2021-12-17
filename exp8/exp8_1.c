/**
 * @file exp8_1.c
 * @author  pansyhou
 * @brief   输入平面上两个点P1(x1,y1)和P2(x2,y2)的坐标，
 *          以这两个点为左上角和右下角可以确定一个矩形，输出这个矩形的周长。
 *          要求平面上点的坐标和矩形都用结构体来表示。
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <math.h>
typedef struct 
{
    int x1;
    int y1;
    int x2;
    int y2;
    int c;
}coordinate;

int main()
{
    coordinate P1;
    printf("请输入P1 x坐标");
    scanf("%d",&P1.x1);
    printf("请输入P1 y坐标");
    scanf("%d",&P1.y1);
    printf("请输入P2 x坐标");
    scanf("%d",&P1.x2);
    printf("请输入P2 x坐标");
    scanf("%d",&P1.y2);
    P1.c=(abs(P1.x1-P1.x2)+abs(P1.y1-P1.y2))*2;
    printf("周长=%d",P1.c);
    return 0;
}