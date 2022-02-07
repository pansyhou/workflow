#include <stdio.h>
int main()
{
    printf("=========饮料自动售卖机=====\n");
    printf("    1-苹果汁   6元\n");
    printf("    2-西瓜汁   5元\n");
    printf("    4-可乐     3元\n");
    printf("    5-雪碧     2元\n");
    printf("    0-退出\n");
    printf("==============================\n");
    printf("请输入饮料编号和数量：n  m");
    int n=0,m=0;
    scanf("%d %d",&n,&m);
    int rmb=0;
    switch (n)
    {
    case 0 :
        break;
    case 1:
        rmb=6*m;
        printf("你本次购买苹果汁饮料，需要支付%d元。",rmb);
        break;
    case 2:
        rmb=5*m;
        printf("你本次购买西瓜汁饮料，需要支付%d元。",rmb);
    case 3:
        rmb=4*m;
        printf("你本次购买葡萄汁饮料，需要支付%d元。",rmb);
    case 4:
        rmb=3*m;
        printf("你本次购买可乐饮料，需要支付%d元。",rmb);
    case 5:
        rmb=2*m;
        printf("你本次购买雪碧饮料，需要支付%d元。",rmb);
        break;
    }
    return 0;
}