#include<stdio.h>
int main()
{
    int inp_num,fir1,sec1,thr1;
    printf("输入");
    scanf("%d",&inp_num);
    fir1=(inp_num/100+6)%10;
    sec1=((inp_num/10)%10+6)%10;
    thr1=((inp_num%10)+6)%10;
    printf("%d%d%d",thr1,sec1,fir1);
    return 0;
}