#ifndef __LINKER_H
#define __LINKER_H

typedef struct student
{
    int id;
    char name[15];
    int sumMark;
    struct student *next;
}student;

// struct student *addmem(struct student *q);
// void addlinker(struct student *head,struct student *prev,struct student *current);
void printAllLinked(struct student *head);
void killmem(struct student *head);
student * cpylinked(struct student *origin);
void sortLinked(struct student *head);
void deleteLinker(struct student *preDeleteObject,struct student *deleteObject);
void printOneLinker(struct student *object);
#endif