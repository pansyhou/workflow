#include <stdio.h>
void main()
{
    int stu_num=0;
    int i=0,s=0;
    int mark[100];
    for (;i<100&&s!='\n';i++)
    {
        scanf("%d",&mark[i]);
        s=getchar();
        stu_num++;
    }
}