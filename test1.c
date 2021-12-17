#include <stdio.h>
int main()
{
	int a[3][2] = { 0 }, (*ptr)[2], i, j;
	for ( i = 0; i < 2; i++ )
	{
		ptr = a + i; scanf( "%d", ptr ); ptr++;
	}
	for ( i = 0; i < 3; i++ )
		for ( j = 0; j < 2; j++ )
			printf( "%d", a[i][j] );
	return(0);
}