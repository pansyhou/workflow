
#include <stdio.h>
int main()
{
 int cnt = 0;
 char ch[10000];
 gets(ch);
 printf("\n\n");
 while(ch[cnt] != '\0' && ch[cnt] != '.')
 {
 if(ch[cnt] != ' ')
 {
 printf("%c",ch[cnt]);
 }
 else
 {
 printf("\n");
 }
 cnt++;
 }
 getch();
 return 0;
}
#include<stdio.h>
void sort(int s[],int n,int b)
{
int i,j,t;
for(i=0;i<n;i++)
for(j=0;j<n-1-i;j++)
if(s[j]>s[j+1])
{
t=s[j];
s[j]=s[j+1];
s[j+1]=t;
}
if(b==1)
for(j=0;j<n/2;j++)
{
t=s[j];



char s[100];
int i;
gets(s);
for(i=0;s[i]!='\0';i++)
if(s[i]==' ')
putchar('\n');
else
putchar(s[i]);
}

