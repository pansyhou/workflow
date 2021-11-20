#include <stdio.h>
int main()
{
    int U,N,D;//U为上爬寸数,D为下滑数，N为井深
    scanf("%d %d %d",&N,&U,&D);
    if (D>=U)
    {
        printf("下滑数大于上爬数，请重新输入上爬寸数 井深 下滑寸数");
        scanf("%d %d %d",&N,&U,&D);
    }
    if (N>100)
    {
        printf("井深超过100，请重新输入上爬寸数 井深 下滑寸数");
        scanf("%d %d %d",&N,&U,&D);
    }
    int time=1,r_height=0;
    for (time=1;r_height<=N;time++)
    {
        if (time%2!=0)
        {
            r_height=r_height+U;
        }
        else
        {
            r_height=r_height-D;
        }
    }
    time--;
    printf("%d",time);
    return 0;
}