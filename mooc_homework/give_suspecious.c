#include <stdio.h>
int main()
{
    int inp_num;
    scanf("%d",&inp_num);
    int i,j,k;

    i=inp_num;
    while(i<=inp_num+3)
    {
        j=inp_num;
        while (j<=inp_num+3)
        {
            k=inp_num;
            while (k<=inp_num+3)
            {
                if (i!=j)
                {
                    if (i!=k)
                    {
                        printf("%d%d%d\n",i,j,k);0
                    }

                }
                k++;
            }
            
            j++;
        }
        i++;
    }
}