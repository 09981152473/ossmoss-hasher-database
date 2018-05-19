#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prefix(char *s,char *c)
{
    int i,k,j,t=0;
        k=strnlen(s,10000);
	int a[k+1];
	a[0]=0;
	for(i=1;i<=k;i++){
		while(t>=1 && c[t]!=s[i-1]){
			t=a[t-1];
		}
		if(c[t]==s[i-1]){
			if(t>0 && c[t-1]!=s[i-2]){t=0;}
			else{t++;}		
		}
		a[i]=t;
	}
	if(c[1]==s[k-1] && c[0]==s[k-2]  && a[k]<2){a[k]=2;}
	return a[k];
}
int Permut(char **a,int n){
	int i,k[n],d,j;
	char *g[n];
	for(i=0;i<n;i++){
		char *b;
		for(j=0;j<n;j++){
			g[j]=a[j];
		}
		b=g[i];
		g[i]=g[n-1];
		g[n-1]=b;
		k[i]=Permut_rec(g,n-1,b,strnlen(b,10000));
	}
	d=k[0];
    for(i=0;i<n;i++){
		if(k[i]<d){d=k[i];}
	}
	return d;
}
int Permut_rec(char **a,int n,char *s,int c){
    int i,k[n],d,q,j;
	char *g[n];
	if(n==0){
		return c;		
	}
	else{
		for(i=0;i<n;i++){
			char *b;
			for(j=0;j<n;j++){
				g[j]=a[j];
			}
			b=g[i];
			g[i]=g[n-1];
			g[n-1]=b;
			q=strnlen(b,10000);
			j=prefix(s,b);
			k[i]=Permut_rec(g,n-1,b,c+q-j);
		}
		d=k[0];
		for(i=0;i<n;i++){
			if(k[i]<d){d=k[i];}
		}
		return d;
	}
}
int main()
{
	int i,n;
	scanf("%d\n",&n);
	char *s[n];
	for(i=0;i<n;i++){
		s[i]=(char *)malloc(10000);
	}
	for(i=0;i<n;i++){
		gets(s[i]);
	}
	printf("%d",Permut(s,n));
	for(i=0;i<n;i++){
		free(s[i]);
	}
	return 0;
}