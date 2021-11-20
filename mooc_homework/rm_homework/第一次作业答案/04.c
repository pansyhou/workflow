#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int a, b, i;
float c;

int main(){
    printf("猜大小，请输入范围");
    scanf("%f", &c);

    printf("猜大小，请输入数字");
    srand((unsigned long)time(0));
    a = rand() * c / RAND_MAX;
    //或者 a = rand() % c + 1;
    while (a > b || a < b){
        scanf("%d", &b);
        if (a > b){
            printf("猜小了\n");
        }
        else if (a < b){
            printf("猜大了\n");
        }
        i++;
    }
    printf("正确\n\n");
    printf("GAME OVER! !\n");
    return 0;
}
