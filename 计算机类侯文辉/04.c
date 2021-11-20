//4  4  4  4  4  4  4
//  3  3  3  3  3
#include <stdio.h>
void main ()
{
    int num=0;
    scanf("%d",&num);
    int i=num*2-1;
    for(int l=0,p=0;l<i;l=l+2,p++)
    {
        for(int q=0;q<p;q++)
            {
                printf("   ");
            }
        for(int k=l;k<i;k++)
        {
            
            printf("%d  ",num-p);
        }
        printf("\n");
    }
    return 0;
}