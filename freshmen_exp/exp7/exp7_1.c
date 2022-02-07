/**
 * @file    exp7_1.c
 * @author  pansyhou
 * @brief   从键盘输入10个整数（在main函数中完成这个功能），
 *          求这10个整数的最大值和序号（要求编写一个以指针作为参数的函数来完成这个功能）。
 *          然后在main函数中输出最大值和序号。
 */
#include <stdio.h>
void main(void)
{
    int num[10],i=0;
    char s;
    printf("请输入十个数字，回车结束");
    for (i=0;i<10&&s!='\n';i++)//循环获得十个数字，具体为，数字先在缓冲区被scanf扫到，后面有一个空格作为char被get到结束一次循环
    {
        scanf("%d",&num[i]);
        s=getchar();
    }
    int *p,max_num=num[0],max_mark=0;
    p=&num;//p指针指向数组的第0个
    for (int k=0;k<i;k++)
    {
        if (*(p+k)>max_num) 
        {
            max_num=*(p+k);
            max_mark=k;
        }
    }
    printf("最大值=%d 序号=%d",max_num,max_mark+1);
}