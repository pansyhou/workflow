#include <stdio.h>

int num[100];
int order,count,temp;

int main(){
	scanf("%d%d",&order,&count);
	for (int i = 0; i < count; i++) {
		scanf("%d", &num[i]);
	}
	
	//Ã°ÅİÅÅĞò
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (order == 1 && num[i] > num[j]) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
            if(order == 0 && num[i] < num[j]){
                temp = num[i];
				num[i] = num[j];
				num[j] = temp;
            }
		}
	}
	
	//Êä³ö
	for (int i = 0; i < count; i++) {
		printf("%d ", num[i]);
	}
	
	return 0;
}