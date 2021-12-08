#include <stdio.h>
#define N 10
int getmax(int *p);
int main()
{
     int i, j;
     int b[N] = {0};
     int a[N] = {0};
     int *p = b;
     int x, y;
     for (i = 0; i < N; i++)
     {

          scanf("%d", &b[i]);
     }
     for (i = 0; i < N; i++)
     {
          a[i] = b[i];
     }
     x = getmax(p);
     for (j = 0; j < N; j++)
     {
          if (a[j] == x)
               y = j;
     }
     printf("序号为：%d\n", y + 1);
}
int getmax(int *p)
{
     int t, i, j;
     for (i = 0; i < N; i++)
     {
          if (p[i] > p[i + 1])333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
          {
               t = p[i];
               p[i] = p[i + 1];
               p[i + 1] = t;
          }
     }
     printf("最大值为：%d\n", t);
     return t;
}