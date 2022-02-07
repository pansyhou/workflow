#include <stdio.h>
int main()
{
    double x1, x2, y1, y2, x3, y3;
    printf("P1(x1,y1):");
    scanf("%lf %lf", &x1, &y1);
    printf("P2(x2,y2):");
    scanf("%lf %lf", &x2, &y2);
    //计算部分
    x3 = (x1 + x2) / 2.0;
    y3 = (y1 + y2) / 2.0;
    printf("P1(%f,%f)和P2(%f,%f)构成的线段的中点为P3(%.2f,%.2f)", x1, y1, x2, y2, x3, y3);
    return 0;
}