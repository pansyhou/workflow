#include <stdio.h>
int main()
{
    int height=0;
    printf("请输入行数：");//试试不同行数更有挑战
    scanf("%d",&height);
    int lie=2*height;
    for (int i=1;i<=height;i++)
    {
        for (int j=1;j<lie;j++)
        {
            
            if(j==1||j==i||j==(lie-i)||j==lie-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }
    return 0;
}