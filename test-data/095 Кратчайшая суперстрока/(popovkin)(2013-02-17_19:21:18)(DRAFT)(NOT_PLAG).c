#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void func(char **a, int n)
{
        int i, j, count, k, l,s1,s2, res, temp=0;
	int **b=malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
		b[i]=calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		s1=strlen(a[i]);
		for(j=0;j<n;j++){
			if(j==i)
				if(j<n-1)
					j++;
			s2=strlen(a[j]);
			k=s1;
			l=0;
			while(a[i][k]==a[j][l]){
				b[i][j]++;
				l++;
				k--;
			}
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
				printf("%d", b[i][j]);
	return;
	count=0;
	for(i=0;i<n;i++){
		temp=0;
		if(count=n)
			break;
		for(j=0;j<n;j++)
			if(b[i][j]>temp){
				temp=b[i][j];
				k=i;
				l=j;
				count++;
			}
		for(j=0;j<n;j++)
			b[j][l]=0;
	}
	i=0;
	count=0;
	again:
	for(;;){
		if (count==n)
			break;
		for(j=0;j<n;j++)
			if(b[i][j]!=0){
				temp=b[i][j];
				res+=strlen(a[i])-temp*2;
				i=j;
				goto again;
				count++;
			}
	}
	res+=strlen(a[i])-temp;
	printf("%d", res);
	for(i=0;i<n;i++)
		free(b[i]);
	free(b);
}
int main()
{
	int i, n;
	scanf("%d\n", &n);
	char **a=malloc(n*sizeof(char*));
	for(i=0;i<n;i++){
		a[i]=malloc(20*sizeof(char));
		gets(a[i]);
	}
	func(a, n);
	for(i=0;i<n;i++)
		free(a[i]);
	free(a);
	return 0;
}