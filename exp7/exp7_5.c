/*brief
    用一个函数实现两个字符串的比较，即自己写一个strcmp函数，函数原型为：
                int strcmp(char *p1,char *p2);
    设p1指向字符串s1，p2指向字符串s2，要求当s1=s2时，函数返回值为0；
    如果s1≠s2，返回它们二者第一个不相同字符的ASCII码差值（如“BOY”与“BAD”，第二个字母不相同，“O”与“A”之差为79-65=14）；
    如果s1>S2，则输出正值；如s1<s2则输出负值。
*/
#include <math.h>
#include <stdio.h>
int strcmp(char *p1,char *p2)
{
    int return_ascii=0,cnt=0,flag=0;
    for (;p1[cnt]!='\0'&&p2[cnt]!='\0';cnt++)
    {
        if(p1[cnt]!=p2[cnt]&&return_ascii==0)
        {
            return_ascii=abs(p1[cnt]-p2[cnt]);
        }
        if (p1[cnt]!=p2[cnt]) flag=1;
    }
    if (return_ascii!=0) return return_ascii;
    else if (p1[cnt]!='\0') return 1;
    else if (p2[cnt]!='\0') return -1;
    else if (flag==0) return 0;
}
int main()
{
    char a[]={"BOY"};
    char b[]={"BAD"};
    char *p1=a,*p2=b;
    printf("%d",strcmp(p1,p2));
    return 0;
}