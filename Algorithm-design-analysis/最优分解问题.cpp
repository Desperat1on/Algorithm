#include<stdio.h>
int main()
{
	int j,k,n,count;
	int index=0,sum=0;
	int i=2;
	int a[100]={0};
	a[2]=2;
	scanf("%d",&n);
	while(n-sum>=i) { //��2��ʼ����n���зֽ� 
		sum+=i;
		a[i]=i;
		i++;
		index++;
	} 
	//���磺19
	// 2��3��4��5   ʣ��5��ȫ����1����ʣ1�����һλ��1���ɡ� 
	int p=(n-sum)/index; //����ȫ���ۼ� 
	int q=(n-sum)%index; //ֻ�Ӻ���ǰ�������ʣ��� 
	for(j=i-1;j>=2;j--) {
		a[j]+=p;
	}
	for(k=i-1;k>i-1-q;k--) {
		a[k]++;
	}
	for(j=2;j<index+2;j++) {
		printf("%d  ",a[j]);	
	} 
}