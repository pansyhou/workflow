#include <stdio.h>
int main()
{
    int a[100]={1,2,1,3,2,5,8},k=0;
    for (k=0;a[k]!='\0';k++){}//计算数组下标长度
    for(int i=1;i<k;i++)
    {
        if((a[i]>a[i+1]&&a[i]>a[i-1])||(a[i]<a[i+1]&&a[i]<a[i-1]))printf("%d ",i);
    }
    return 0;
}