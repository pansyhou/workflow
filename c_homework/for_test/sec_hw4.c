#include <stdio.h>
int main()
{
    char cha[30],strin[20],need[30],*p,*q;
    int k=0,j=0;
    char t;
    char o='"';
    gets(cha);
    while (cha[k]!=o)
    {
        k++;
    }
    k++;
    for (;cha[k]!=o;k++,j++)
    {
        t=cha[k];
        strin[j]=t;
    }
    k++;
    while (cha[k]!=o)
    {
        k++;
    }
    k++;
    for (j=0;cha[k]!=o;k++,j++)
    {
        t=cha[k];
        need[j]=t;
    }
    
}