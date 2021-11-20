#include <stdio.h>
int main(void)
{
    int fir_time=0,pass_time=0;
    scanf("%d %d",&fir_time,&pass_time);

    //分别计算开始时间的小时和分钟

    int fir_mins=fir_time%100;//获取分钟
    int fir_hours=fir_time/100;//获取小时

    int pass_hours=pass_time/60;//分别计算过去的小时和分钟
    int pass_mins=pass_time%60;
    
    int final_hours=fir_hours+pass_hours;//最后加上去
    int final_mins=fir_mins+pass_mins;

    //排除分钟大于60的问题
    while (final_mins > 60)
    {
        final_hours++;
        final_mins=final_mins-60;
    }
    //排除分钟小于0的问题

    while (final_mins<0)
    {
        final_hours--;
        final_mins=final_mins+60;
    }
    

    printf("%d%d",final_hours,final_mins);
    return 0;
}