/**
 * @file    exp7_2.c
 * @author  pansyhou
 * @brief   有5名学生，每人有三门考试成绩（语文、数学、英语），
 *          计算每个学生的平均成绩，查找有一门及以上课程不及格的学生，
 *          输出不及格学生的课程成绩（含学号和三门课成绩和平均成绩）。
 */
#include <stdio.h>
#define M 5//宏定义，可修改学生数
void input(int i, int (*nums)[5]);
int main()
{
    int curriculum_Mark[5][M]={0};//定义一行一个学生,最后一个为平均数
    int (* nums)[5]=curriculum_Mark, i = 5;//定义二维数组
    for (int cot = 0; cot < i; cot++)
    {
        input(cot,nums);//cot为行数
    }
    for (int hang = 0; hang < 5; hang++)
    {
        int fail = 0;
        for (int lie = 1; lie < M-1; lie++)
        {
            if (curriculum_Mark[hang][lie] < 60)
            {
                fail = 1;
                break;
            }
        }
        if (fail == 1)
        {
            for (int a = 0; a < M; a++)
            {
                if(a!=M-1) printf("%d ", curriculum_Mark[hang][a]);
                else printf("平均成绩=%d",curriculum_Mark[hang][a]);
            }
        }
        fail=0;
        printf("\n");
    }
}
void input(int i, int (*nums)[5])
{
    int k = 0;
    char s;
    printf("请输入学号 语文 数学 英语成绩");
    for (; k < M-1 && s != '\n'; k++)//输入成绩
    {
        scanf("%d",*(nums+i)+k);
        s = getchar();
    }
    s='0';
    int sum = 0;
    for (k = 1; k < M - 1; k++)
    {
        sum = sum + *(*(nums + i) + k);
    }
    double avarg=(double)sum/3.0;
    *(*(nums + i) + M-1)=avarg;
}
