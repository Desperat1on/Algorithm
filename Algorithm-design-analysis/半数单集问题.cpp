#include<stdio.h>
int a[100]={0};
int set(int n)
{
	if(a[n]>0)
		return a[n];   //��Ϊ0ʱ���˳��ݹ� 
	else 
	{
		a[n]=1;
		for(int i=1;i<=n/2;i++) 
		{
			a[n]+=set(i);
			if(i>10 && (2*(i/10)<=i%10))  //�������λ��������ʮλ�ȸ�λ��һ��С��������ظ�Ԫ��
				a[n]-=a[i/10];
		}
		return a[n];
	}
}
int main()
{
	int n;
	printf("������һ����Ȼ����\n");
	scanf("%d",&n);
	int count=set(n);
	printf("�����İ������ĸ���Ϊ��%d\n",count);
} 
