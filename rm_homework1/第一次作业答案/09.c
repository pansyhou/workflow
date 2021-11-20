#include <stdio.h>
#include <math.h>
/*
输入一串英文句子，输出句子中的单词，且相邻单词之间用换行隔开
例1：
输入: Deep Dark Fantasies
输出: Deep
	  Dark
	  Fantasies

例2: 
输入: My name is Van
输出: My
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