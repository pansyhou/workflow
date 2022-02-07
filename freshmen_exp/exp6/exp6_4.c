#include <stdio.h>
int cal(int x,int n);
int main()
{
    int x=0,y=0;
    printf("输入x和n:");
    scanf("%d %d",&x,&y);
    printf("%d",cal(x,y));
}
int cal(int x,int n)
{
    int y=0;
    if (n==0) y=1;
    else y=x*(cal(x,n-1));
    return y;
}