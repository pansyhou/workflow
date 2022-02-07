#include <stdio.h>
int decTobin(int n);
int main()
{
    int n;
    decTobin(n);
}
int decTobin(int n)
{
    int binary=0,i = 1;
	scanf("%d",&n); 
    while(n != 0)
    {
        if(n % 2 != 0)
        {
            binary = binary + 1 * i;//如果模二不等于0，进1存进最高位
        }
        n=n/2,i=10*i;
    }
    printf("%d\n",binary);
    return 0;
}