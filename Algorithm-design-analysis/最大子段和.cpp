/*
6
-2 11 -4 13 -5 -2
*/ 
#include<stdio.h>
int a[100]={0};
void show(int begin,int end,int sum)
{//�������Ӷ��Լ�sumֵ 
	for(int i=begin;i<=end;i++) {
		printf("%d  ",a[i]);
	}
	printf("\n");
	printf("%d\n",sum);
}
void MaxSum1(int n,int *a)
{//3��forѭ��
	int sum=0;
	int i,j,k,begin,end;
	for(i=0;i<n;i++) {
		for(j=i;j<n;j++) {
			int count=0;
			for(k=i;k<=j;k++)
				count+=a[k];
				if(count>=sum) {
					sum=count;
					begin=i;
					end=j;
				}
		}
	}
	show(begin,end,sum);
}
void MaxSum2(int n,int *a)
{//2��forѭ��
	int i,j,begin,end;
	int sum=0;
	for(i=0;i<n;i++) {
		int count=0;
		for(j=i;j<n;j++) {
			count+=a[j];
			if(count>=sum) {
				sum=count;
				begin=i;
				end=j;
			}
		}
	} 
	show(begin,end,sum);
}
void MaxSum3(int n,int *a)
{//һ��forѭ��
	int i,begin,end;
	int sum=0,count=0;
	begin=0;
	for(i=0;i<n;i++) {
		count+=a[i];
		if(count<0) {
			count=0;
			begin=i+1;
		}
		if(count>sum) {
			sum=count;
			end=i;
		}
	} 
	show(begin,end,sum);
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	printf("3��forѭ����\n");
	MaxSum1(n,a);
	printf("2��forѭ����\n");
	MaxSum2(n,a);
	printf("1��forѭ����\n");
	MaxSum3(n,a);
	return 0;
}
