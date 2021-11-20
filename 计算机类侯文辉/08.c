#include <stdio.h>
#include <string.h>
void main(void)
{
    char str[100];
    gets(str);
    strlwr (str);
    for (int l=0;str[l]!='\0';l++)
    {
        for (int i=0;str[i]!='\0';i++)
        {
            if (str[i]==str[i+1])
            {
                for (int k=i;str[k]!='\0';k++)
                {
                    str[k]=str[k+1];
                }
            }
            
        }
    }
    puts(str);
    return 0;
}