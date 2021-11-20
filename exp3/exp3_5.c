#include <stdio.h>
int main ()
{
    int num=0;
    printf("请输入数字1-7:");
    scanf("%d",&num);
    switch (num)
    {
    case 1:
        printf("今天周一，老赵值班");
        break;
    case 2:
        printf("今天周二，老钱值班");
        break;
    case 3:
        printf("今天周三，小李值班");
        break;
    case 4:
        printf("今天周四，老周值班");
        break;
    case 5:
        printf("今天周五，小刘值班");
        break;
    case 6:
        printf("今天周六，小孙值班");
        break;
    case 7:
        printf("今天周日，不值班");
        break;
    default:
        break;
    }
    return 0;
}
