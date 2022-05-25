#include "stdio.h"

int main(void)
{
    // long long a,b;
    // scanf("%d %d",&a,&b);
    // printf("%d",a-b);

    int depth;
    int fdepth;
    int gargage_num;//垃圾
    int gargae=0;
    
    int gglife=9;
    scanf("%d%d",&depth,&gargage_num);
    fdepth=depth;
    depth=0;
    int cal_time[gargage_num];
    int time=1;
    int maintiantime[gargage_num];
    int foodheight[gargage_num];
    int lastfod=0;
    for(int i=0;i<gargage_num;i++)
    {
        scanf("%d%d%d",&cal_time[i],&maintiantime[i],&foodheight[i]);
    }
    int cout=0;
    while(gglife>-1)
    {
        if(time==cal_time[cout])
        {
            //gglife+=maintiantime[cout];
            depth+=foodheight[cout];
            cout++;
            lastfod++;
        }
        if (depth>=fdepth)
        {
            printf("%d",time);
            return time;
        }
        if(gglife==0)
        {
            if(lastfod>0)
            {
                gglife+=maintiantime[lastfod-1];
                depth-=foodheight[lastfod-1];
                lastfod--;
            }
            else
            {
                printf("%d",time);
                return time;
            }
        }
        gglife--;
        time++;
    }
}


// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc,char * argv[])
// {
//     int a;
//     int sum=0;
//     scanf ("%d",&a);
//     while (a)
//     {
//         if(a%2==1)
//         {
//             sum+=a;
//         }
//         a--;
//     }
//     printf("%d",sum);
    
// }