#include <stdio.h>
#include <math.h>
/*
����һ��Ӣ�ľ��ӣ���������еĵ��ʣ������ڵ���֮���û��и���
��1��
����: Deep Dark Fantasies
���: Deep
	  Dark
	  Fantasies

��2: 
����: My name is Van
���: My
	  name
	  is
	  Van
*/
int main(){
	char string[100];
	gets(string);
	for(int i=0;string[i];i++){
		if(string[i]==' ')putchar('\n');
		else putchar(string[i]);
	}
    return 0;
}