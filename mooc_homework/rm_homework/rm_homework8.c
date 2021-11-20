#include <stdio.h>
int gcd(int a,int b);//声明函数
void lcm(int c,int d,int e);
void main()
{
    int num_gcd=0,fir=0,sec=0;
    scanf("%d %d",&fir,&sec);

    printf("Their greatest common divisor is:%d\n",gcd(fir,sec));
    lcm(fir,sec,gcd(fir,sec));

}
int gcd(int a,int b)//最小公约数函数
{
    int temp=0,num_gcd=0;
    while (b!=0)//辗转相除法
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    
    
    return num_gcd=a;

}
void lcm(int c,int d,int e)//最大公倍数函数
{
    printf("Their least common multiple is:%d",(c*d)/e);
}