/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };
#include "stdio.h"
#include "stdlib.h"
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    // if (list1 == NULL && list2 == NULL)
    //     return NULL;
    // if (list1 == NULL)
    //     return list2;
    // else if (list2 == NULL)
    //     return list1;
    // struct ListNode *temp=list1;
    // struct ListNode *new=(struct ListNode *)malloc(sizeof(struct ListNode));
    // while (list2->next!=NULL&&list1->next!=NULL)
    // {
    //     if((list1->next->val>=list2->val))
    //     {
    //         struct ListNode *new=(struct ListNode *)malloc(sizeof(struct ListNode));
    //         struct ListNode *tempNew;
    //         tempNew=list1->next;
    //         list1->next=new;
    //         new->val=list2->val;
    //         new->next=tempNew;
    //         list2=list2->next;
    //     }else if(list1->val==list2->val)
    //     {
    //         struct ListNode *tempNew=(struct ListNode *)malloc(sizeof(struct ListNode));
    //         struct ListNode *t=list1->next;
    //         list1->next=tempNew;
    //         tempNew->val=list2->val;
    //         tempNew->next=t;
    //     }
    //     list1=list1->next;
    // }
    // return temp;

    struct ListNode *new=(struct ListNode *)malloc(sizeof(struct ListNode));
    new->val=-1;
    struct ListNode *prev=new;
    while(list2!=NULL&&list1!=NULL)
    {
        if(list1->val<=list2->val)
        {
            prev->next=list1;
            list1=list1->next;
        }
        else{
            prev->next=list2;
            list2=list2->next;
        }
        prev=prev->next;
    }
    prev->next=list1==NULL?list2:list1;
    return new->next;
}
// @lc code=end
