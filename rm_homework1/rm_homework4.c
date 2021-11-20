#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int num_range=0;

    printf("猜大小，请输入范围");
    scanf("%d",&num_range);
    if (num_range=100)
    {
        int gus_num=(rand()%100)+6;//生成伪随机数
        int num=0;
        do//判断大小
        {
            printf("猜大小，请输入数字 ");
            scanf("%d",&num);
            if (num>gus_num)
            {
                printf("猜大了！");
            }
            else if (num<gus_num)
            {
                printf("猜小了！");
            }
        }
        while (num!=gus_num);
        printf("GAME OVER!!");
    }
    return 0;

}