#include<stdio.h>
int a[100]={0};
int set(int n)           //����һ 
{
	if(a[n]>0)
		return a[n];   //��Ϊ0ʱ���˳��ݹ� 
	else 
	{
		a[n]=1;
		for(int i=1;i<=n/2;i++) 
		{
			a[n]+=set(i);
		}
		return a[n];
	}
}
int set2(int n)            //������ 
{
	if(n==1)
		return 1;
	return set2(n/2*2-1)+set2(n/2);
}
int main()
{
	int n;
	printf("������һ����Ȼ����\n");
	scanf("%d",&n);
	int count=set(n);
	int count1=set2(n);
	printf("set(n)�����İ������ĸ���Ϊ��%d\n",count);
	printf("set2(n)�����İ������ĸ���Ϊ��%d\n",count1);
} 
