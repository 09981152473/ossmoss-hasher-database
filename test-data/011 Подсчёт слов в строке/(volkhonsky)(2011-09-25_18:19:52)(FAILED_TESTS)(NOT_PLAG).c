#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    int f, i, sum;
    i=0;
    f=0;
    sum=0;

    while(s[i]!=0)
    {
        if (s[i]!=' ' && s[i+1]==' ' && s[i+1]!=0)
        {
            sum++;
        }
        i++;
    }
    printf("%d",sum+1);
}

int main(int argc, char **argv)
{
    char s[500];
    gets(s);
    wcount(s);
    return 0;
}

