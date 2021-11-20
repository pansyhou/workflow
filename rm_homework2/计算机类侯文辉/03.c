#include <stdio.h>
#include <string.h>
int main()
{
	char a[200];
	char b[200];
	char *p1,*p2;
	gets(a);//获取字符串
	//使指针1地址指向a
	p1=a;
	//使指针2地址指向字符串数组最后一位
	p2=b+strlen(a)-1;
	//互向交换内容
	for(;*p1!='\0';p1++,p2--)
		*p2 = *p1;
	for (int i=0;b[i]!='\0';i++)
	{
		printf("%c",b[i]);
	}
	return 0;
}