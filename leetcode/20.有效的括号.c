/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#include "string.h"
#include <stdbool.h> 

int Check(char a)
{
    
    if(a==')')return '(';
    if(a=='}')return '{';
    if(a==']')return '[';
    return 0;

}

bool isValid(char *s)
{
    int a = strlen(s);
    if (a%2==1)return false;
    int top=0;
    int stk[a+1];
    for (int i=0;i<a;i++)
    {
        char ch =Check(s[i]);
        if(ch)
        {
            //判断是否闭合， 
            if(top==0||stk[top-1]!=ch)
            {
                return false;   
            }
            top--;
        }
        else
        {
            stk[top++]=s[i];
        }
    }
    return top==0;
}
// @lc code=end
