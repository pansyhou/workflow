/*@brief
    编写一个函数strmcpy(s,t,m)，该函数将字符串t中从m个字符开始的全部字符复制到字符串s中去。
    在主程序中输入一个字符串t和一个开始位置m，调用strmcpy(s,t,m)函数，
    然后输出字符串s的结果。例如：输入字符串liwangzhajinxiao和开始位置2，输出：wangzhajinxiao。
*/
#include <stdio.h>
void strmcpy(char *s, char *p, int m)
{
    int s_Num = 0, p_Num = 0;
    m--;
    for (; s[s_Num] != '\0'; s_Num++);
    for (; s[p_Num] != '\0'; p_Num++);
    int i=0;
    for (;m<= s_Num; m++,i++)
    {
        p[i]=s[m];
    }
    printf("%s",p);
}
int main()
{
    char str1[9999];
    char str2[9999];
    char *s=str1;
    char *p=str2;
    int m=0;
    printf("请输入字符串s=");
    scanf("%s",&str1);
    printf("请输入开始位置m=");
    scanf("%d",&m);
    m++;
    strmcpy(s,p,m);
}