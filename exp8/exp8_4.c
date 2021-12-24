/**
 * @file    exp8_4.c
 * @author  pansyhou
 * @brief   定义一个学生结构体Student(含学号、姓名、成绩和成绩等级)
 *          和一个函数SetGrade(struct Student *p, int *a, int *b, int *c, int *d, int *e)
 *          该函数具有设置成绩等级、统计各等级人数和返回平均成绩的功能。
 *          在主函数中输入10个学生的学号、姓名和成绩，调用SetGrade函数设置成绩等级
 *          、统计各等级人数和返回平均成绩，最后输出学生全部信息。
 *          成绩等级规则为：大于等于90—A，大于等于80—B，大于等于70—C，大于等于60—D，60以下—E。
 * @version 0.1
 * @date 2021-12-17
 * @copyright Copyright (c) 2021
 */
//idea 他这个a~b的指针应该是统计等级人数，然后返回一个平均成绩，最后输出学生全部信息
#include <stdio.h>
#define N 2
typedef struct Student
{
    int num;
    char name[15];
    int mark;
    char grade;
};
double SetGrade(struct Student *p, int *a, int *b, int *c, int *d, int *e);
int main()
{
    struct Student stu[N];
    int A=0,B=0,C=0,D=0,E=0;
    double avg=0;
    int *a=A,*b=B,*c=C,*d=D,*e=E;
    a=&A;b=&B;c=&C;d=&D;e=&E;

    struct Student *p=stu;
    for(int i=0;i<N;i++)
        {
            printf("请输入第%d名学生的学号:",i);
            scanf("%d",&p[i].num);
            printf("请输入第%d名学生的名字:",i);
            scanf("%s",&p[i].name);
            printf("请输入第%d名学生的成绩:",i);
            scanf("%d",&p[i].mark);
        }
    avg=SetGrade(p, a, b,c, d,e);
    printf("平均成绩=%.2f\n",avg);
    printf("A:%d B:%d C:%d D:%d E:%d\n",A,B,C,D,E);
    for(int i=0;i<N;i++)
    {
        printf("第%d名学号是: %d 名字是: %s 成绩是: %d 等级是: %c \n",i,p[i].num,p[i].name,p[i].mark,p[i].grade);
    }
}
double SetGrade(struct Student *p, int *a, int *b, int *c, int *d, int *e)
{
    struct Student *q=p;
    int sum=0;
    for(int i=0;i<N;i++)
    {
        if ((*q).mark>=90)
        {
            (*q).grade='A';
            (*a)++;
        }
        else if ((*q).mark>=80&&(*q).mark<90)
        {
            (*b)++;
            (*q).grade='B';
        }
        else if ((*q).mark>=70&&(*q).mark<80)
        {
            (*c)++;
            (*q).grade='C';
        }
        else if ((*q).mark>=60&&(*q).mark<70)
        {
            (*d)++;
            (*q).grade='D';
        }
        else if ((*q).mark<60)
        {
            (*e)++;
            (*q).grade='E';
        }
        sum+=(*q).mark;
        q++;
    }
    return (double)sum/N;
}
