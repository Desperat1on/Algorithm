/*
10 3
3 4
4 5
5 6
value[i][j]=max{value[i-1][j-w[i]]+c[i],value[i-1][j]} ǰi�������������Ϊj�ı���������ֵ
�����i�����壺value[i-1][j-w[i]]+c[i]
�������i�����壺value[i-1][j]
*/
#include<stdio.h>
#define N 100
int w[N],c[N];
int value[N][N]={0};
int main()
{
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&w[i],&c[i]);
	}
	for(i=1;i<=n;i++) { //һ����n������ 
		for(j=w[i];j<=m;j++) {  //Ϊ���ܷ���������С������w[i]��ʼ 
			int p=value[i-1][j-w[i]]+c[i];//�����i������ļ�ֵ 
			int q=value[i-1][j];  //������ 
			value[i][j]=p>q ? p:q;
		}
	}
	printf("%d\n",value[n][m]);
}