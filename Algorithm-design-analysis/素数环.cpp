#include<stdio.h>
#include<math.h>
#include<string.h>
int a[40],c[21];
int n,count;
int sum=0;//�ڼ���������� 

void prime(int num)
{//������� 
	int i,j;
	for(i=2;i<=num;i++) {
		for(j=i+i;j<=num;j+=i) {
			a[j]=1;
		}
	}
}

int set(int i) {
//�ж�ǰ���Ƿ��Ѿ����ڸ����� 
	int j;
	for(j=1;j<i;j++) {
		if(c[j]==c[i])
			return 0;
	}
	return 1;	
}

void traceback(int row)
{
	int i,j;
	c[0]=1;
	//��Ϊ��һ����������Ҫ�ж����һ���͵�һ������Ƿ�Ϊ����
	if(row==n && a[1+c[n-1]]==0) { 
		count++;
		for(i=0;i<n;i++) {
			if(i==0)
				printf("%d",c[0]);
			else {
				printf(" %d",c[i]);
			}
		}
		printf("\n");
		return ; 
	}
	for(i=2;i<=n;i++){
		c[row]=i;
		int temp=c[row]+c[row-1];
		if(a[temp]==0 && set(row))
			traceback(row+1);
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF) {
		sum++;
		printf("Case %d:\n",sum);
		if(n>1 && n%2!=0) {   //���ڴ���1����������û�������� 
		}
		else {
			count=0;
			memset(a,0,sizeof(a));
			memset(c,0,sizeof(c));
			prime(n*2);
			traceback(1);
			printf("the result is %d\n",count);
		}
		printf("\n");
	}
	return 0;
} 
