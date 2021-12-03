#include <stdio.h>
int f(int *p, int i, int j);
int main()
{
     int a[5][4];
     int i, j;
     printf("请按顺序输入学号1—5的学生的学号，语文，数学，英语成绩：");
     for (i = 0; i < 5; i++)
     {
          for (j = 0; j < 4; j++)
          {
               scanf("%d", &a[i][j]);
          }
     }
     return 0;
}
int f(int *p, int i, int j)
{
     int *p = 0;
     int e, f;
     float sum = 0;
     for (e = 0; e < i; e++)
     {
          for (f = 1; f < j; f++)
          {
               sum += *(p[e] + f);
          }
     }
}