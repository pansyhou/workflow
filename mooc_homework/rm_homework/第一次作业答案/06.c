#include<stdio.h>
#include<stdlib.h>
#include <string.h>
 
void swap(char*str1,char*str2){
    char tem[20];
    strcpy(tem,str1);
    strcpy(str1,str2);
    strcpy(str2,tem);
}
int main(){
    char str1[20],str2[20],str3[20];
    printf("������3���ַ���,ÿ���ַ����Իس�����!:\n");
    scanf("%s%s%s",str1,str2,str3);

    if(strcmp(str1,str2)>0)swap(str1,str2);
    if(strcmp(str2,str3)>0)swap(str2,str3);
    if(strcmp(str1,str2)>0)swap(str1,str2);

    printf("�����Ľ��Ϊ��\n");
    printf("%s %s %s",str1,str2,str3);
    return 0;
}
