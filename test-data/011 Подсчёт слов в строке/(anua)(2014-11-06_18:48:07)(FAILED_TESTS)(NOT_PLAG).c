#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    int flag = 0, i, k = 0;
    for( i = 0; i != ' '; i++)
        {
		if (s[i] == ' ')
		{
			flag = 0;
			continue;
		}
		if (flag == 0)
		{
			k++;
			flag = 1;
		}
    }
    return k;
}

int main()
{
	char *s;
	s =(char*)malloc(1000*sizeof(char));
	gets(s);
	int k = wcount(s);
    printf("%d", k);
	free(s);
    return 0;
}
