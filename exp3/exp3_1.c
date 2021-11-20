#include <stdio.h>
int main()
{
    int x;
    double y;
    double w;
    printf("请输入购物款");
    scanf("%d",&x);
    if (x<1600)
    {
        y=0;
    }
    else if (x<2400 && x >1600)
    {
        y=0.05;
    
    }
    else if (x<3200 && x>2400)
    {
        y=0.1;
    }
    else if (x<6400 && x>3200)
    {
        y=0.15;
    }
    else if (x>=6400)
    {
        y=0.2;
    }
    w=x-x*y;
    printf("付款数:%.2f",w);
    return 0;

}