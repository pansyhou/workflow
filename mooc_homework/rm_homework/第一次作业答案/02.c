#include<stdio.h>

float h;
int n = 0;
float ret = 0;
float sum = 0;

int main()
{
    scanf("%f%d", &h,&n);
	for(int i = 0; i <  n; i++)
	{
		sum += h;
		ret = h / 2;
		h = ret;
	}
	printf("%f ", sum);
	printf("%f", ret);
	return 0;
}