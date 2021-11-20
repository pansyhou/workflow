#include <stdio.h>
int main()
{
    int a=0;
    scanf("%d",&a);
    int num[100]={0};
    int count=0;
    while(a!=0)//将数字存进数组
    {
        int t=0;
        t=a%10;
        num[count]=t;
        a/=10;
        count++;
    }
    int control=0;//引用控制数来控制函数，会比直接在循环里打印好
    for (int i=0;i<count;i++)//两两比较
    {
        for (int k=0;k<count;k++)
        if(num[i]==num[k]&&(i!=k))
        {
            control=1;
            break;
        } 
    }
    if(control==0)
    {
        printf("NO");
    }
    else printf("YES");

}