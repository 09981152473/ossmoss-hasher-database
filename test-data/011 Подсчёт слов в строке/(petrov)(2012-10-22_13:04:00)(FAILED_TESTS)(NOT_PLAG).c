
#include <stdio.h>
#include <string.h>
int main()
{
        int a;
        int wcount(char *s)
        {
                int k,i,n,h;
                k=0;
                h=0;
                n=strlen(s);
                for (i=0;i<n;i++)
                        if (s[i]==' ') h+=1;
                for (i=0;i<(n-1);i++)
                        if ((s[i]==' ')&&(s[i+1]!=' ')) k+=1;
                if (s[0]!=' ') k+=1;
                if (h==0) k=1;
                if (s=="") k=0;
                return k;
        }
        a=wcount("   dfvgdfgf   g  ghg   ghg   ");
        printf("%d",a);
        return 0;
}
