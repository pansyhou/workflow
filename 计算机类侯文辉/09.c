#include <stdio.h>
void main ()
{
    char borad[100];//1 0 0 0 1（1.3.5.7）.1 0 0 0 0 0 1
    gets(borad);
    printf("n= ");
    int n=0;
    scanf("%d",&n);
    int count=0;
    int num=0,j=0;
    while (borad[j]!='\0')
    {
        j++;
    }
    
    for (int i=0;i<j;i=i+4)
    {
        for (int k=i;k<j&&k+2<j&&k+4<j;k=k+2)
        {
            if (borad[k]=='0'&&borad[k+4]=='0')
            {
                if(borad[k+2]!='1')
                {
                    borad[k+2]='1';
                    count++;
                }
            }
            
        }
    }
    if(n<=count)
    {
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}