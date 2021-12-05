#include <stdio.h>
#include <string.h>
#define n 5  //为什麽要使用宏定义？便于更改一些变量时只需要在开头进行该动即可
#define m 10 //而不需要，当你改便某个变量的数据后将整章文章都进行改动，反正宏定义十分好用希望大家也能早点爱上宏定义
int main()
{
     int i = 0;
     char a[n][m];                 //定义一个2维数组对字符串进行储存
     char *b[n];                   //使用指针数组方便对字符串的排序
     void sort(char *p[m], int k); //定义一个以指针数组维参数的函数
     printf("输入字符串：");
     for (i = 0; i < n; i++)
     {
          // printf("输入第%d个字符串：\n",i+1);
          scanf("%s", (a + i)); //对多个字符串的输入
          b[i] = *(a + i);
          printf("%d",sizeof(*(a + i)));       //建立字符串与字符数组的联系
     }
     sort(b, n);
     for (i = 0; i < n; i++)
     {
          printf("%s ",b[i]);
     }
     return 0;
}
void sort(char *p[n], int k)
{
     int i, j;
     char *temp;                  //定以以个空指针方便交换0
     for (i = 0; i <= k - 1; i++) //使用冒泡排序法进行排序
     {
          for (j = 0; j < k - 1 - i; j++)
          {
               if (strcmp(p[j], p[j + 1]) < 0) //注意函数里面的参数的是字符串的地址
               {
                    temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
               }
          }
     }
}
