#include <stdio.h>
void main(void)
{
    int count=0;
    for (int a=1;a<100;a++)
    {
        for (int b=1;b<100-a;b++)
        {
            for (int c=1;c<100-b-a;c++)//套三个循环，内循环每结束一次b+1
            //大概意思就是第一个循环先把c尝试1-100，b不断加，a不断加，但是都是100以内
            if((pow(a*a,-1))+(pow(b*b,-1))==(pow(c*c,-1)))
            {
                printf("a=%d b=%d c=%d\n",a,b,c);
                count++;
            }
        }
    }
    printf("一共%d组",count);
}