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
#include <string.h>

typedef struct 
{
    int num;
    char name[15];
    int age;
    int height;
}Student;
void input(int i,Student *p,int *student_Num);
void add(Student *p,int *student_Num);
void change(Student *p,int *student_Num);
void delete(Student *p,int *student_Num);
void browse(Student *p,int *student_Num);
void sort(Student *p,int *student_Num);
void search(Student *p,int *student_Num);
void statistics(Student *p,int *student_Num);
void Delay(int nCount)
{
  for(; nCount != 0; nCount--);
}

int main()
{
    int Student_Num=1;
    printf("------------------------------------------------------------\n");
    printf("------------------欢迎来到学生信息管理系统------------------\n");
    printf("---------------------如有卡顿请回车一下---------------------\n");
    printf("---------------------有bug也请原谅一下----------------------\n");
    printf("------------------------------------------------------------\n");
    Delay(0xffffffff);
    //Delay(0xffffffff);

    system("cls");
    printf("------------------------------------------------------------\n");
    printf("---------------------输入学生信息以开始---------------------\n");
    printf("------------------------------------------------------------\n");
    Delay(0xffffffff);

    system("cls");
    printf("请输入学生个数:");
    scanf("%d",&Student_Num);
    Student stu[999];
    int *student_Num;
    student_Num=&Student_Num;
    Student *p;
    p=&stu;
    for (int t;t<*student_Num;t++)
    {
      input(t,p,student_Num);
    }
    //1-增加 2-修改 3-删除 4-浏览 5-查找 6-排序 7-统计
    int contral=1;
    system("cls");
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
      printf("---------------------8-退出查询系统-------------------------\n");
      printf("------------------------------------------------------------\n");
      int fun_Num=0;
      scanf("%d",&fun_Num);
      switch (fun_Num)
      {
      case (1):
        add(p,student_Num);
        system("cls");
        break;
      case (2):
        change(p,student_Num);
        system("cls");
        break;
      case (3):
        delete(p,student_Num);
        system("cls");
        break;
      case (4):
        browse(p,student_Num);
        char s=0;
        printf("输入#退出浏览");
        while(s=getchar()!='#');
        break;
      case (5):
        search(p,student_Num);
        system("cls");
        break;
      case (6):
        sort(p,student_Num);
        system("cls");
        break;
      case (7):
        statistics(p,student_Num);
        system("cls");
        break;
      default:
        printf("输入的数字不符合规范");
        break;
      }
      system("cls");
      if(fun_Num==8)
      {
        printf("exit successfully!");
        break;
      }
    }
    
}
void input(int i,Student *p,int *student_Num)
{
    printf("请输入第%d位学生的学号",i);
    scanf("%d",&p[i].num);
    printf("\n");
    printf("请输入第%d位学生的名字",i);
    scanf("%s",&p[i].name);
    printf("\n");
    printf("请输入第%d位学生的年龄",i);
    scanf("%d",&p[i].age);
    printf("\n");
    printf("请输入第%d位学生的身高",i);
    scanf("%d",&p[i].height);
    printf("\n");

}

void browse(Student *p,int *student_Num)
{
  for (int i=0;i<*student_Num;i++)
  {
    printf("第%d位学生的姓名为%s 学号为%d 年龄为%d 身高为%d\n",i,p[i].name,p[i].num,p[i].age,p[i].height);
  }
}

void change(Student *p,int *student_Num)
{
  browse(p,student_Num);
  printf("\n");
  printf("请输入你要修改学生的序号");
  int change_Stu_Num=0;
  scanf("%d",&change_Stu_Num);
  printf("请输入第%d位学生的学号",change_Stu_Num);
  scanf("%d",&p[change_Stu_Num].num);
  printf("请输入第%d位学生的名字",change_Stu_Num);
  scanf("%s",&p[change_Stu_Num].name);
  printf("请输入第%d位学生的年龄",change_Stu_Num);
  scanf("%d",&p[change_Stu_Num].age);
  printf("请输入第%d位学生的身高",change_Stu_Num);
  scanf("%d",&p[change_Stu_Num].height);
}
void delete(Student *p,int *student_Num)
{
  browse(p,student_Num);
  printf("\n");
  printf("请输入你要删除学生的序号");
  int change_Stu_Num=0;
  scanf("%d",&change_Stu_Num);
  for (;change_Stu_Num<*student_Num;change_Stu_Num++)
  {
    p[change_Stu_Num]=p[change_Stu_Num+1];
  }
  (*student_Num)--;
}
void sort(Student *p,int *student_Num)
{
  printf("请输入对身高/年龄排序，年龄扣1,身高扣2:");
  int flag_ageortall=0;
  scanf("%d",&flag_ageortall);
  printf("请输入升序还是降序，升序扣1，降序扣2:");//升从小到大
  int flag_upordowm=0;
  scanf("%d",&flag_upordowm);
  switch (flag_ageortall)
  {
  case 1:
        switch (flag_upordowm)
        {
        case 1:
          for (int i=0;i<*student_Num;i++)
          {
              Student temp_struct;
              int temp=p[i].age;
              int temp_Mark=i,k=i+1;
              for (k=i+1;k<*student_Num;k++)
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
          break;
        case 2:
          for (int i=0;i<*student_Num;i++)
          {
              Student temp_struct;
              int temp=p[i].age;
              int temp_Mark=i,k=i+1;
              for (k=i+1;k<*student_Num;k++)
              {
                  if (temp<p[k].age)
                  {
                      temp_Mark=k;
                      temp=p[k].age;
                  }
              }
              temp_struct=p[i];
              *(p+i)=*(p+temp_Mark);
              p[temp_Mark]=temp_struct;
          }
          break;
        default:
          break;
        }
        break;
  case 2:
    switch (flag_upordowm)
        {
        case 1:
          for (int i=0;i<*student_Num;i++)
          {
              Student temp_struct;
              int temp=p[i].height;
              int temp_Mark=i,k=i+1;
              for (k=i+1;k<*student_Num;k++)
              {
                  if (temp>p[k].height)
                  {
                      temp_Mark=k;
                      temp=p[k].height;
                  }
              }
              temp_struct=p[i];
              *(p+i)=*(p+temp_Mark);
              p[temp_Mark]=temp_struct;
          }
          break;
        case 2:
          for (int i=0;i<*student_Num;i++)
          {
              Student temp_struct;
              int temp=p[i].height;
              int temp_Mark=i,k=i+1;
              for (k=i+1;k<*student_Num;k++)
              {
                  if (temp<p[k].height)
                  {
                      temp_Mark=k;
                      temp=p[k].height;
                  }
              }
              temp_struct=p[i];
              *(p+i)=*(p+temp_Mark);
              p[temp_Mark]=temp_struct;
          }
          break;
        default:
          break;
        }
    break;
  default:
    break;
  }
}

void search(Student *p,int *student_Num)
{
  printf("------------------------------------------------------------\n");
  printf("---------------------请输入要查询的内容---------------------\n");
  printf("---------------------------1-姓名---------------------------\n");
  printf("---------------------------2-学号---------------------------\n");
  printf("---------------------------3-年龄---------------------------\n");
  printf("---------------------------4-身高---------------------------\n");
  printf("------------------------------------------------------------\n");
  int search_Context=0;
  char name1[999];
  int flag=0;
  int index[*student_Num];
  int temp;
  char s;
  scanf("%d",&search_Context);
  printf("请输入查询的内容:");
  switch (search_Context)
  {
  case 1:
  scanf("%s",&name1);
    for (int i=0;i<*student_Num;i++)
    {
      if(strcmp(p[i].name,name1)==0)
      {
        index[i]=1;
        flag++;
      }
    }
    if(flag==0)printf("查询不到内容\n");
    else printf("查询到以下信息\n");
    for (int k=0;k<*student_Num;k++)
    {
      if(index[k]==1)
      {
        printf("第%d位学生的姓名为%s 学号为%d 年龄为%d 身高为%d\n",k,p[k].name,p[k].num,p[k].age,p[k].height);
      }
    }
    printf("输入#以退出查询");
    while(s=getchar()!='#');
    break;
  case 2:
    scanf("%d",&temp);
    for(int i=0;i<*student_Num;i++)
    {
      if(temp==p[i].num)
      {
      index[i]=1;
      flag++;
      }
    }
    if(flag==0)printf("查询不到内容");
    else printf("查询到以下信息\n");
    for(int i=0;i<*student_Num;i++)
    {
      if(index[i]==1)
      {
        printf("第%d位学生的姓名为%s 学号为%d 年龄为%d 身高为%d\n",i,p[i].name,p[i].num,p[i].age,p[i].height);
      }
    }
    printf("输入#以退出查询");
    while(s=getchar()!='#');
    break;
  case 3:
    scanf("%d",&temp);
    for(int i=0;i<*student_Num;i++)
    {
      if(temp==p[i].age)
      {
      index[i]=1;
      flag++;
      }
    }
    if(flag==0)printf("查询不到内容");
    else printf("查询到以下信息\n");
    for(int i=0;i<*student_Num;i++)
    {
      if(index[i]==1)
      {
        printf("第%d位学生的姓名为%s 学号为%d 年龄为%d 身高为%d\n",i,p[i].name,p[i].num,p[i].age,p[i].height);
      }
    }
    printf("输入#以退出查询");
    while(s=getchar()!='#');
    break;
  case 4:
    scanf("%d",&temp);
    for(int i=0;i<*student_Num;i++)
    {
      if(temp==p[i].height)
      {
      index[i]=1;
      flag++;
      }
    }
    if(flag==0)printf("查询不到内容");
    else printf("查询到以下信息\n");
    for(int i=0;i<*student_Num;i++)
    {
      if(index[i]==1)
      {
        printf("第%d位学生的姓名为%s 学号为%d 年龄为%d 身高为%d\n",i,p[i].name,p[i].num,p[i].age,p[i].height);
      }
    }
    printf("输入#以退出查询");
    while(s=getchar()!='#');
    break;
  default:
    printf("输入有误,输入#以退出查询");
    while(s=getchar()!='#');
    break;
  }
  flag=0;
}
void add(Student *p,int *student_Num)
{
  input((*student_Num),p,student_Num);
  (*student_Num)++;
}

void statistics(Student *p,int *student_Num)
{
  printf("------------------------------------------------------------\n");
  printf("---------------------请输入要统计的内容---------------------\n");
  printf("---------------------------1-年龄---------------------------\n");
  printf("---------------------------2-身高---------------------------\n");
  printf("------------------------------------------------------------\n");
  int flag=0;
  double sum=0,avg=0;
  char s;
  scanf("%d",&flag);
  switch (flag)
  {
  case 1:
    for (int i=0;i<*student_Num;i++)
    {
      sum+=p[i].age;
    }
    avg=sum/(*student_Num);
    printf("平均年龄为:%f\n",avg);
    printf("输入#以退出查询");
    while(s=getchar()!='#');
    break;
  case 2:
    for (int i=0;i<*student_Num;i++)
      {
        sum+=p[i].height;
      }
      avg=sum/(*student_Num);
      printf("平均年龄为:%f\n",avg);
      printf("输入#以退出查询");
      while(s=getchar()!='#');
      break;
  
  default:
    printf("输入有误,输入#以退出查询");
    while(s=getchar()!='#');
    break;
  }
  sum=0,avg=0;
}