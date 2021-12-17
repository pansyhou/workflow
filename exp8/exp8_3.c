/**
 * @file exp8_3.c
 * @author  pansyhou
 * @brief   定义一个学生结构体Student(含学号、姓名、年龄、身高)
 *          和一个函数sort(struct Student *p)，
 *          该函数使用选择排序法按年龄由小到大排序。
 *          在主函数中输入10个学生的学号、姓名、年龄和身高，
 *          调用sort函数对学生数据排序，最后输出排序后的学生全部信息。
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#define N 3
#include <stdio.h>
typedef struct Student
{
    int num;
    char name[15];
    int age;
    int height;
};
void sort(struct Student *p);
void input(struct Student *p);
void output(struct Student *p);

int main()
{
    struct Student stu[N];
    struct Student *p=stu;
    input(p);
    sort(p);
    output(p);
}
void input(struct Student *p)
{
    for(int i=0;i<N;i++)
    {
        printf("请输入第%d名学生的学号:",i);
        scanf("%d",&p[i].num);
        printf("请输入第%d名学生的名字:",i);
        scanf("%s",&p[i].name);
        printf("请输入第%d名学生的年龄:",i);
        scanf("%d",&p[i].age);
        printf("请输入第%d名学生的身高:",i);
        scanf("%d",&p[i].height);
    }
}
void output(struct Student *p)
{
    for(int i=0;i<N;i++)
    {
        printf("第%d名学号是: %d 名字是: %s 年龄是: %d 身高是: %d\n",i,p[i].num,p[i].name,p[i].age,p[i].height);
    }
}
void sort(struct Student *p)
{
    for (int i=0;i<N;i++)
    {
        struct Student temp_struct;
        int temp=p[i].age;
        int temp_Mark=i,k=i+1;
        for (k=i+1;k<N;k++)
        {
            if (temp>p[k].age)
            {
                temp_Mark=k;
                temp=p[k].age;
            }
        }
        temp_struct=p[i];
        *(p+i)=*(p+temp_Mark);
        p[temp_Mark]=temp_struct;
    }
}