#include<stdio.h> 
int main()
{
	int i,j,m,n,max=0;
	int a[10000]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&j);//������Ͱ��������ʱ����Ԫ�ط����Ӧ��Ͱ�� 
		a[j]++;
		if(a[j]>max) {
			max=a[j];
			m=j;
		}	
	} 
	printf("%d %d",m,max);
	return 0;
}