#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int a, b, i;
float c;

int main(){
    printf("�´�С�������뷶Χ");
    scanf("%f", &c);

    printf("�´�С������������");
    srand((unsigned long)time(0));
    a = rand() * c / RAND_MAX;
    //���� a = rand() % c + 1;
    while (a > b || a < b){
        scanf("%d", &b);
        if (a > b){
            printf("��С��\n");
        }
        else if (a < b){
            printf("�´���\n");
        }
        i++;
    }
    printf("��ȷ\n\n");
    printf("GAME OVER! !\n");
    return 0;
}
