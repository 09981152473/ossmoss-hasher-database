#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s)
{
    int i, count = 0;
    int len=strlen(s);
    for (i=0; i<len; i++) {
        if (s[i]!=' '){
            count++;
            do i++; while ((s[i]!=' ') || (s[i]!='\0') || (s[i]!='\t'));
        }
    }
    return count;
}
    
int main()
{
    char *s=(char*)malloc(1000*sizeof(char));
    gets(s);
    printf("%d\n", wcount(s));
    free(s);
    return 0;
}
