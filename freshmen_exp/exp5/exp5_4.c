#include <stdio.h>
void main(void)
{
    int n = 0, m = 0; //n行,m列
    char s;
    printf("请输入行 列");
    scanf("%d %d", &n, &m);
    int a[n][m];
    printf("请输入第一行(如100 200 29)\n");
    for (int i = 0; i < n; i++)
    {
        s = '0';
        for (int u = 0; u < m && s != '\n'; u++)
        {
            scanf("%d", &(a[i][u]));
            s = getchar();
        }
        if (i != n - 1)
            printf("请输入下一行\n");
    }
    int t = 0, l = 0, k = 0, i = 0, ret = 1;
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < m - 1; k++)
        {
            //先找每一行的最大值
            if (a[i][t + 1] > a[i][t])
            {
                t = k + 1;
            }
        }
        //找对应列数的最小值
        for (int v = 0; v < n - 1; v++)
        {
            if (a[l][t] > a[l + 1][t])
            {
                l = v;
            }
        }
        if (a[i][t] == a[l][t])
        {
            printf("%d %d\n", l, t);
            ret = 0;
        }
    }
    if (ret == 1)
        printf("不存在该特征的元素");
}
