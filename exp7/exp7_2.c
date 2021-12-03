#include <stdio.h>
#define M 5
void input(int i, int (*nums)[5]);
int main()
{
    int curriculum_Mark[5][M]={0};
    int (* nums)[5]=curriculum_Mark, i = 5;
    for (int cot = 0; cot < i; cot++)
    {
        input(cot,nums);//cot为行数
    }
    for (int hang = 0; hang < 5; hang++)
    {
        int fail = 0;
        for (int lie = 0; lie < M; lie++)
        {
            if (curriculum_Mark[hang][lie] < 60)
            {
                fail = 1;
                break;
            }
        }
        if (fail == 1)
        {
            for (int a = 0; a < M; a++)
            {
                if(a!=M-1) printf("%d ", curriculum_Mark[hang][a]);
                else printf("平均成绩=%d",curriculum_Mark[hang][a]);
            }
        }
        printf("\n");
    }
}
void input(int i, int (*nums)[5])
{
    int k = 0;
    char s;
    printf("请输入学号 语文 数学 英语成绩");
    for (; k < M-1 && s != '\n'; k++)
    {
        scanf("%d",*(nums+i)+k);
        s = getchar();
    }
    s='0';
    int sum = 0;
    for (k = 0; k < M - 1; k++)
    {
        sum = sum + *(*(nums + i) + k);
    }
    double avarg=(double)sum/5.0;
    *(*(nums + i) + M-1)=avarg;
}
