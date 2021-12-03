#include <stdio.h>
void main(void)
{
    int num[10],i=0;
    char s;
    printf("请输入十个数字，回车结束");
    for (i=0;i<10&&s!='\n';i++)//循环获得十个数字，具体为，数字先在缓冲区被scanf扫到，后面有一个空格作为char被get到结束一次循环
    {
        scanf("%d",&num[i]);
        s=getchar();
    }
    int *p,max_num=num[0],max_mark=0;
    p=&num;//p指针指向数组的第0个
    for (int k=0;k<i;k++)
    {
        if (*(p+k)>max_num) 
        {
            max_num=*(p+k);
            max_mark=k;
        }
    }
    printf("最大值=%d 序号=%d",max_num,max_mark+1);
    //12 45 89 50 40 62 50 666 82 87
}