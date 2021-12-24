#ifndef __LINKER_H
#define __LINKER_H

typedef struct student
{
    int id;
    char name[15];
    int sumMark;
    student *next;
}student;

student *addmem(student *q);
void addlinker(student *head,student *prev,student *current);
void printlLinked(student *head);
void killmem(student *head);
student * cpylinked(student *origin);
void sortLinked(student *head);



#endif