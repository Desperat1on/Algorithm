/*
����¼�͵ݹ�һ����Ҳ�ǴӶ����׹��죬��Ҫ���������ݣ����м�¼ 
ABCBDAB
BDCABA
*/ 
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 100 
char a[N],b[N];
int temp[N][N]={0};
int p,q;
int memorize(int m,int n)
{
	if(m<0 || n<0) {
		return 0;
	}
	if(temp[m][n]!=0)
		return temp[m][n];
	else {
		if(a[m]==b[n]) {
			temp[m][n]=memorize(m-1,n-1)+1;
			return temp[m][n];
		}
		else {
//			temp[m-1][n]=memorize(m-1,n);������bug������д�� 
//			temp[m][n-1]=memorize(m,n-1);
			p=memorize(m-1,n);
			q=memorize(m,n-1);
			temp[m][n]=q > p ? q:p;
			return temp[m][n];
		}
	}
}

int main()
{
	int len_a,len_b;
	scanf("%s",a);
	scanf("%s",b);
	len_a=strlen(a);
	len_b=strlen(b);
	printf("%d\n",memorize(len_a-1,len_b-1));
	return 0;
} 
