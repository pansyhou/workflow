/**
 * @file   exp8_5.c
 * @author pansyhou
 * @brief   使用本学期所学习的结构化程序设计思想，设计并实现一个“学生信息管理系统”，系统功能与技术要求如下：
 *          （1）系统基本功能：输入、增加、修改、删除、浏览、查找、排序、统计等。
 *          （2）系统必须使用结构体等数据结构表示系统中管理的数据对象。
 *          （3）其他要求：至少两层菜单。提供良好的人机界面，方便用户进行相关操作。
 *          （4）学生信息内容由自己设定。
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
//欢迎来到学生信息管理系统，首先您需要输入学生信息，
//1-增加 2-修改 3-删除 4-浏览 5-查找 6-排序 7-统计
#include <stdio.h>
typedef struct 
{
    int num;
    char name[15];
    int age;
    int height;
}Student;
void input(Student *p,int student_Num);
void add(Student *p);
void change(Student *p,int student_Num);
void delete(Student *p);
void browse(Student *p,int student_Num);
void sort(Student *p);
void statistics(Student *p);
void Delay(int nCount)
{
  for(; nCount != 0; nCount--);
}

int main()
{
    int student_Num=1;
    printf("——————————————————————————————\n");
    printf("—————————欢迎来到学生信息管理系统—————————\n");
    printf("——————————————————————————————\n");
    Delay(0xffffffff);
    //Delay(0xffffffff);

    system("cls");
    printf("——————————————————————————————\n");
    printf("———————————输入学生信息以开始—————————\n");
    printf("——————————————————————————————\n");
    Delay(0xffffffff);

    system("cls");
    printf("请输入学生个数:");
    scanf("%d",&student_Num);
    Student stu[student_Num];
    Student *p;
    p=&stu;
    input(p,student_Num);
    //1-增加 2-修改 3-删除 4-浏览 5-查找 6-排序 7-统计
    int contral=1;
    while(1)
    {
      printf("------------------------------------------------------------\n");
      printf("-----------------请输入对应数字实现对应功能-----------------\n");
      printf("---------------------1-增加学生信息-------------------------\n");
      printf("---------------------2-修改学生信息-------------------------\n");
      printf("---------------------3-删除学生信息-------------------------\n");
      printf("---------------------4-浏览学生信息-------------------------\n");
      printf("---------------------5-查找学生信息-------------------------\n");
      printf("---------------------6-排序学生信息-------------------------\n");
      printf("---------------------7-统计学生信息-------------------------\n");
      printf("------------------------------------------------------------\n");
      int fun_Num=0;
      scanf("%d",&fun_Num);
      switch (fun_Num)
      {
      case (1):
        add(p);
        system("cls");
        break;
      case (2):
        change(p,student_Num);
        system("cls");
        break;
      // case (3):
      //   delete(p);
      //   system("cls");
      //   break;
      // case (4):
      //   browse(p,student_Num);
      //   system("cls");
      //   break;
      // case (5):
      //   sort(p);
      //   system("cls");
      //   break;
      // case (6):
      //   statistics(p);
      //   system("cls");
      //   break;
      // default:
      //   printf("输入的数字不符合规范");
      //   break;
      }
      system("cls");
    }
}
void input(Student *p,int student_Num)
{
  for(int i=0;i<student_Num;i++)
  {

    
    printf("     请输入第%d位学生的学号",i);
    scanf("%d",&p[i].num);
    printf("\n");
    printf("     请输入第%d位学生的名字",i);
    scanf("%s",&p[i].name);
    printf("\n");
    printf("     请输入第%d位学生的年龄",i);
    scanf("%d",&p[i].age);
    printf("\n");
    printf("     请输入第%d位学生的身高",i);
    scanf("%d",&p[i].height);
    printf("\n");
  }
}
void browse(Student *p,int student_Num)
{
  for (int i=0;i<student_Num;i++)
  {
    printf("%s %d %d %d\n",p[i].name,p[i].num,p[i].age,p[i].height);
  }
}

void change(Student *p,int student_Num)
{
  browse(p,student_Num);
  printf("\n");
  printf("请输入你要修改学生的序号");
  int change_Stu_Num=0;
  scanf("%d",&change_Stu_Num);
  printf("请输入第%d位学生的学号",change_Stu_Num);
  scanf("%d",&p[change_Stu_Num].num);
  printf("\n");
  printf("请输入第%d位学生的名字",change_Stu_Num);
  scanf("%s",&p[change_Stu_Num].name);
  printf("\n");
  printf("请输入第%d位学生的年龄",change_Stu_Num);
  scanf("%d",&p[change_Stu_Num].age);
  printf("\n");
  printf("请输入第%d位学生的身高",change_Stu_Num);
  scanf("%d",&p[change_Stu_Num].height);
  printf("\n");
}
// void delete(Student *p);
// void browse(Student *p,int student_Num);
// void sort(Student *p);
// void statistics(Student *p);