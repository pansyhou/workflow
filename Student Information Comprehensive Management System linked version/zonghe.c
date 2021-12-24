#include <stdio.h>
#include<linker.h>

/*定义单向链表*/
typedef struct student
{
    int id;
    char name[15];
    int sumMark;
    student *next;
}student;

int main()
{
    student *head=NULL;
    student *prev,*current;
}