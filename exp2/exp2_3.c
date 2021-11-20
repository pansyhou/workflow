#include<stdio.h>
int main() 
{
    double start_money=20000.0,interests,tax,last;
    interests=start_money*0.03;
    tax=interests*0.2;
    last=start_money+(interests-tax);
    printf("%f",last);

}