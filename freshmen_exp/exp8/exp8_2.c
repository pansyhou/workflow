/**
 * @file exp8_2.c
 * @author  pansyhou    
 * @brief   有N名学生，
 *          每个人的信息包括学号、姓名和语文、数学、英语、平均分等内容（用结构体表示 ）
 *          输出平均分排名倒数第2的学生信息。
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#define N 3
typedef struct 
{
    int stu_num;
    char name[15];
    int chinese;
    int math;
    int english;
    float avg;
}mark_info;
int main (void)
{
    mark_info stu[N];

    for(int i=0;i<N;i++)
    {
        printf("请输入第%d名学生的学号",i);
        scanf("%d",&stu[i].stu_num);
        printf("请输入第%d名学生的名字",i);
        scanf("%s",&stu[i].name);
        printf("请输入第%d名学生的语文成绩",i);
        scanf("%d",&stu[i].chinese);

        printf("请输入第%d名学生的数学成绩",i);
        scanf("%d",&stu[i].math);
        printf("请输入第%d名学生的英语成绩",i);
        scanf("%d",&stu[i].english);
        stu[i].avg=(stu[i].chinese+stu[i].english+stu[i].math)/3.0;
    }

    for (int i=0;i<N;i++)
    {
        for(int k=0;k<N-i-1;k++)
        {
            if(stu[k].avg>stu[k+1].avg)
            {
                mark_info temp;
                temp=stu[k];
                stu[k]=stu[k+1];
                stu[k+1]=temp;
            }
        }
    }
    printf("倒数第二名的学生学号为%d 姓名为 %s",stu[1].stu_num,stu[1].name);

}

