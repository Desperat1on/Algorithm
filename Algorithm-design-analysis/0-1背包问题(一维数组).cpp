/*
10 3
3 4
4 5
5 6
ʹ�ö�ά����ʱ���Ǵ�ǰ�����죬������ǰ������ݡ�
������ʹ��һά���飬Ϊ�˱�֤ǰ������ݲ���ʧ��ֻ�ܴӺ���ǰ���� 
*/
#include<stdio.h>
#define N 100
int w[N],c[N];
int value[N]={0};//ʹ��һά���� 
int main()
{
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&w[i],&c[i]);
	}
	for(i=1;i<=n;i++) { //һ����n������ 
		for(j=m;j>=w[i];j--) { //�Ӻ���ǰ����  
			if(value[j]<value[j-w[i]]+c[i])
				value[j]=value[j-w[i]]+c[i];
		}
	}
	printf("%d\n",value[m]);
}