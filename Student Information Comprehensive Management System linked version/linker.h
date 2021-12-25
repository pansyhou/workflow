#ifndef __LINKER_H
#define __LINKER_H

struct student
{
    int id;
    char name[15];
    int sumMark;
    struct student *next;
};

void Delay(int nCount);
struct student *addmem(struct student *q);
struct student *addlinker(int i);
void printAllLinked(struct student *head);
void killmem(struct student *head);
struct student * cpylinked(struct student *origin);
struct student * sortLinked(struct student *head,int stuNum1);
void deleteLinker(struct student *preDeleteObject,struct student *deleteObject);
void printOneLinker(struct student *object);
struct student * addSinglelinker(struct student *head,int *stuNum1);
int seachTheSame(struct student *q,int num);
#endif