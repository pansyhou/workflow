#include <stdio.h>

int main()
{
    int time=0,n=0,watchtime=0;
    scanf("%d",&time);
    int hero=0;
    int soilder=0;
    while(n<time)
    {
        n++;
        hero=hero+3;
        watchtime++;
        if (watchtime<=10)//步兵前10秒的正常行走
        {
            soilder=soilder+9;
            if (watchtime==10)
            {
                if (soilder<hero)
                {
                    watchtime=0;
                }
            } 
        }
        else if (watchtime==11)//当10秒的时候回头看
        {
            
            if (soilder<(hero-3))
            {
                soilder=soilder+9;
                watchtime=0; 
            }
        

        }
        else if (watchtime>39)//调试后将累积的时间清零重新计算
        {
            watchtime=0;
        }
    }
    if (hero>soilder){
        printf("hero %d",hero);

    }
    else if (soilder>hero)
    {
        printf("infantry %d",soilder);
    }
    else
    {
        printf("draw");
    }
    return 0;
}