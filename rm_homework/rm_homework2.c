#include <stdio.h>
int main(void)
{
    double ini_height=0;
    int drop_times=0;

    printf("the initial height is ");
    scanf("%lf",&ini_height);

    double pass_length=ini_height;
    double new_height=ini_height;
    
    scanf("%d",&drop_times);

    //计算部分
    while (drop_times>0)
    {
        drop_times--;//每跳一次减一次直至减完为止
        new_height=new_height/2.0;//下一次跳的高度
        pass_length=pass_length+new_height;//总共经历的高度
    }
    printf("the total of road is %f\n",pass_length);
    printf("the tenth is %f meter",new_height);
 
    return 0;
}