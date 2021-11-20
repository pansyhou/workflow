#include <stdio.h>
int rounding(double a);//四舍五入函数声明
void main()
{
    int stu_num=0;
    int i=0;
    char s;
    int mark[100];
    printf("请输入成绩，如100 52 50，回车开始计算\n");
    for (;i<100&&s!='\n';i++)
    {
        scanf("%d",&mark[i]);
        s=getchar();
        stu_num++;
    }//冒泡排序
    for (int k=0;k<stu_num;k++)
    {
        for (int t=0;t<stu_num-k;t++)
        {
            if(mark[t]>mark[t+1])
            {
                int temp=0;
                temp=mark[t+1];
                mark[t+1]=mark[t];
                mark[t]=temp;
            }
        }
    }
    int judge=1;
    for (int u=0;u<stu_num;u++)
    {
        if (mark[u]<60)judge=0;
    } 
    if (judge==1)printf("及格线为60");//首先判断有没有全部超过60分
    else
    {
        int pass_num=rounding(((double)stu_num*0.6));//计算超过前60的人数
        int pass_line=((mark[stu_num-pass_num])/10)*10;//刚好压60的人的成绩除10乘10即为及格线
        printf("及格线为%d",pass_line);
    }
}
int rounding(double a)
{
    int b=0;
    b=(int)(a+0.5);//如果是1.6，+0.5变成2.1然后取整得2，如果是1.2，+0.5变成1.7取整得1
    return b;
}