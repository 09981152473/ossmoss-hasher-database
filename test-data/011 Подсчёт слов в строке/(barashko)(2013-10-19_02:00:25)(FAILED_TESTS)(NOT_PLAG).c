#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s) 
{ 
        int i, total, f;
        char ww;
	char *j;
	if (strlen(s) == 0) return 0;
	total = ww = 0;
	for (j = s; *j != '\0'; j++) {
		if (*j != ' ') {
			ww = 1;
			f++;
		}
		if ((*j == ' ') && (ww == 1)) {
			ww = 0;
			total++;
		}
	}
	if (ww == 1) total ++;
	if (f == strlen(s) - total) total++;
	return total;
}

int main()
{
	char *string;
	int a;
	string = malloc(1000);
	gets(string);	
	a = wcount(string);
	printf("%d\n", a);
	free(string);
	return 0;
}