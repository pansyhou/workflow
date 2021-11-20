#include <stdio.h>
void main()
{
    int fir_num=0;
    printf("输入一个整数");
    scanf("%d",&fir_num);
    printf("反转后的整数");
    while (fir_num>0)
    {
        printf("%d",(fir_num%10));//获取个位数
        fir_num/=10;//除10后之前的十位数变个位，不断循环获取个位数
    }
    
}