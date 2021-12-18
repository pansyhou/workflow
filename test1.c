#include <stdio.h>
int main()
{
	int a=0;
	int *q;
	q=a;
	int b;
	b=(*q)+1;
	printf("%d",b);

}
