#include <stdio.h>
int main()
{
    int i,j,k,n;
    printf("输入i j k n（各自放n个: ");
    scanf("%d %d %d %d",&i,&j,&k,&n);
    int count=1;
    int i1=n,j1=n,k1=n;
    int sec=1;
    while (i1>0||j1>0||k1>0)
    {
        if (sec==1)
        {
            count++;
            i1--;
            j1--;
            k1--;

        }
        else if ((sec%(i+1)==0&&i1>0)||(sec%(j+1)==0&&j1>0)||(sec%(k+1)==0&&k1>0))
        {
            count++;
            if (sec%(i+1)==0&&i1>0)
            {
                i1--;
            }
            if (sec%(j+1)==0&&j1>0)
            {
                j1--;
            }
            if (sec%(k+1)==0&&k1>0)
            {
                k1--;
            }
        }
        sec++;
    }
    count--;
    printf("%d",count);
    return 0 ;
}