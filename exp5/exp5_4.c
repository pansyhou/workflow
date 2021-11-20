#include <stdio.h>
void main(void)
{
    int n=0,m=0;//n行,m列
    printf("请输入行 列");
    scanf("%d %d",&n,&m);
    int a[n][m];
    printf("请一个个输入");
    for(int i=0;i<n;i++)
    {
        for (int u=0;u<m;u++)
        {
            scanf("%d",&(a[i][u]));
        }
        if(i!=n-1)printf("请输入下一行\n");
    }
    int t=0,l=0,k=0,i=0;
    for (i=0;i<n;i++)
    {
        for (k=0;k<m-1;k++)
        {
            //先找每一行的最大值
            if(a[i][t+1]>a[i][t])
            {
                t=k+1;
            }
        }
        //找对应列数的最小值
        for (int v=0;v<n-1;v++)
        {
            if(a[l][t]>a[l+1][t])
            {
                l=v;
            }
        }
        if (a[i][t]==a[l][t])printf("%d %d\n",l,t);
    }
    
}