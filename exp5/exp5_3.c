#include <stdio.h>
void main (void)
{
    int b[]={1,6,8,7};
    printf("原数组：1 6 8 7");
    int n=4;
    int temp=0;
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<n-i;k++)
        {
            if (b[k+1]%2!=0&&b[k]%2==0)//参考冒泡排序
            {
                temp=b[k+1];
                b[k+1]=b[k];
                b[k]=temp;
            }
        }
    }
    printf("\n排序后：");
    for (int i=0;i<n;i++)
    {
        printf("%d  ",b[i]);
    }
}