
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int wcount(char *s)
{
        int k = 0;
	int j=0;
	for (int i = 0; i < strlen(s); ++i)
	{
		s[i] != ' ' ? j++ : (j != 0 ? (k++, j = 0) : j = 0);
	}
	return k;
}

int main()
{
	char string[256];
	gets(string);
	printf("%d", wcount(string));

	return 0;
}
