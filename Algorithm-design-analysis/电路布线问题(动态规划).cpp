/*
1)��i=1ʱ��size(i,j)={0, ��j<p(1)
					  {1, ��j>=p(1)
2)��i>1ʱ��size(i,j)={size(i-1,j), ��j<p(i)
					{max{size(i-1,j),size(i-1,p(i)-1)+1},��j>=p(i)
10
8 7 4 2 5 1 9 3 10 6
*/
#include<stdio.h>
#define N 100 
int main()
{
	int i,j,n;
	int a[N],p[N][N];
	scanf("%d",&n);
	for(i=1;i<=n;i++) {//�±��1��ʼ
		scanf("%d",&a[i]);
	}
	for(j=1;j<=n;j++) {
		if(j<a[1])
			p[1][j]=0;
		else
			p[1][j]=1;
	}
	for(i=2;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(j<a[i])//��j<c[i]������  
				p[i][j]=p[i-1][j];
			else
				p[i][j]=p[i-1][j]>p[i-1][a[i]-1]+1 ? p[i-1][j] : p[i-1][a[i]-1]+1;
		}
	}
	printf("%d\n",p[n][n]);
	return 0;
} 