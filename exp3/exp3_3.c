#include <stdio.h>
void main()
{
    int sex=0;
    int weight=0,age=0,height=0;
    printf("请输入性别（男1女2）");
    scanf("%d",&sex);
    switch (sex)
    {
    case 1:
        printf("请输入年龄 身高 体重");
        scanf("%d %d %d",&age,&height,&weight);
        if (height>=170 && weight>=60)
        {
            if (age<=24 && age >=18)
            {
                printf("恭喜你被录用为销售业务员");
            }
            else if (age>24) 
            {
                printf("恭喜你被录用为售后服务人员");
            }
        }
        else
        {
            printf("很抱歉您没有被录上");
        }
        break;
    
    case 2:
        printf("请输入年龄 身高 体重");
        scanf("%d %d %d",&age,&height,&weight);
        if (height>=160 && weight>=45)
        {
            if (age<=24 && age >=18)
            {
                printf("恭喜你被录用为销售业务员");
            }
            else if (age>24) 
            {
                printf("恭喜你被录用为售后服务人员");
            }
        }
        else
        {
            printf("很抱歉您并没有被录上");
        }
        break;
    }
}