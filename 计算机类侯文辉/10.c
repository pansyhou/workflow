#include <stdio.h>
void main()
{
    int water=0;
    int a=0,b=1,final=0,temp=0,i=0,k=0;
    int num[]={4,2,0,3,2,5,-1};
    printf("4,2,0,3,2,5\n");//阿这真的尽力了，不知道怎么把输入的参数传入数组
    
    while (num[i]!=(-1))
    {
        final++;
        i++;
    }
    i=0;
    while (b<=final)
    {
        if (num[b]<num[a])
        {
            temp+=num[a]-num[b];
        }
        else
        {
            water+=temp;
            temp=0;
            a=b;
        }
        b++;
    }
    if(temp!=0)
    {
        b=final-1;
        while (b>a)
        {
            if(num[b]<num[final])
            {
                water+=num[final]-num[b];
            }
            else
            {
                final=b;
            }
            b--;
        }
        
    }
    printf("%d",water);
    return 0;
}