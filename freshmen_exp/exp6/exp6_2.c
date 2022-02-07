#include <stdio.h>
int qiuhe(int a,int n);
int main()
{
    int a=0,n=0;
    scanf("%d %d",&a,&n);
    printf("%d",qiuhe(a,n));
}
int qiuhe(int a,int n)
{
    int s1=0,t1=a;
    for (int i=0;i<n;i++)
    {
        s1+=t1;
        t1=t1*10+a;
        a*=10;
    }
    return s1;
}