#include <stdio.h>
#include <stdlib.h>
int main ()
{
    void *p;
    int count=0;
    while ((p=malloc(100*1024*1024)))
    {
        count++;
    }
    printf("%d00mb",count);
}