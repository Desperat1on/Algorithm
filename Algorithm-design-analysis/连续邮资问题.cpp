/*
��������m����Ʊ�����Ի���ʱtracebackѡ�������ڼ�����Ʊ
count��1��ʼ 
*/ 
#include<stdio.h>
int n,m; 
int a[100];
int count=1,sum=0;
int flag;
void traceback(int num)
{
	int i;
	if(flag)
		return ;
	if(num==m) {   
		if(sum==count) {
			flag=1;
		}
		return ;
	}
	for(i=0;i<=n;i++) { //һ����n����Ʊ��ѡ,���ǻ����Բ��� 
		sum+=a[i];
		traceback(num+1);
		sum-=a[i];
	}
}

int main()
{
	int i;
	scanf("%d%d",&n,&m);
	a[0]=0;
	for(i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	while(1) {
		flag=0;
		traceback(0);
		if(flag==0) //��һ���������������Ʊ����ֹ 
			break;
		count++;
	}	
	printf("%d\n",count);
	return 0;
}