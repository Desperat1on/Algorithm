/*
traceback(int col)�У�col���Ƶ��ǵ�һ�е���Ԫ�� 
����ȷ����һ�е�ÿһ�����֣�ȷ����һ��֮���������ɸ����ֶ�Ӧ��һ��б�� 
*/ 
#include<stdio.h>
int n;
int count=0,sum=0;
int a[100][100]={0};
int half;
char c[2]={'+','-'};
void traceback(int col)
{
	int i,j,k; 
	if(col==n) {
		count++;
		for(i=0;i<n;i++) {
			for(j=0;j<n-i;j++) {
				printf("%c",c[a[i][j]]);
			}
			printf("\n");
		}
		return ;
	}
	for(k=0;k<2;k++) {//����forѭ������kֵ��0��1֮��ı任 
		a[0][col]=k;
		sum+=k;
		for(i=1;i<=col;i++) {
			a[i][col-i]=a[i-1][col-i]^a[i-1][col-i+1];
			sum+=a[i][col-i];
		}
		if(sum<=half/2 && (col+1)*(col+2)/2-sum<=half/2) {//1��0�ĸ���ҪС�ڵ���һ�����col+1 
			traceback(col+1);
		}
		for(i=1;i<=col;i++) {
			sum-=a[i][col-i];
		}
		sum-=k;
	}
}

int main()
{
	scanf("%d",&n);
	half=n*(n+1)/2;
	if(half%2!=0) {
		printf("not have.\n");
		return 0;
	}	
	traceback(0);
	printf("%d\n",count);
	return 0;
}