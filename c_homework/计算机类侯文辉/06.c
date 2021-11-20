#include <stdio.h>
int main()
{
    int point[]={1,8,6,2,5,4,8,3,7};
    int point_num=0,j=0,i=0;
    int Square=0,temp=0;
    while (point[point_num]!='\0')//计算数组有多少元素
    {
        point_num++;
    }
    for (i=0 ;i<point_num;i++)
    {
        for (j=0;j<point_num;j++)
        {
            if (point[i]<point[j])//判断两个垂线哪个低，以最低的为标准作面积
            {
                temp=(point[i]*(abs(i-j)));
            }
            else if (point[i]>=point[j])
            {
                temp=(point[j]*(abs(i-j)));
            }
            if (temp>Square)//temp作为暂时值以获取最大的面积（本来还想把temp存进数组里然后一个个比较，笑死
            {
                Square=temp;
            }
        }

    }
    printf("%d",Square);
    return 0;
}
