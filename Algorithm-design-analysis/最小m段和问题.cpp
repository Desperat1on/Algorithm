/*
n�����֣��ֳ�m�Σ�ʹ��m�������еĺ͵����ֵ�ﵽ��С
 
״̬ת�Ʒ��̣�s[i][j]=min{max{s[i][1]-s[k][1],s[k][j-1]}}
*/

#include<stdio.h>
#include<string.h>
int a[20];
int s[100][100];
int set(int n,int m)
{
	int i,j,k,temp,maxsum;
	for(i=1;i<=n;i++) {  //s[i][1]��ʾǰi�����ֳַ�1�ε�ֵ,��ǰi������֮��   
		s[i][1]=s[i-1][1]+a[i];
	}
	for(j=2;j<=m;j++) {    //��2��ʼ,�ָ�Ϊm�� 
		//��ǰi�����ַָ��j��(��С��Ҫj������,��i=j��ʼ���ɣ������2��ʼ)
		for(i=j;i<=n;i++) {
			temp=10000000;
			for(k=j;k<i;k++) {
				maxsum=(s[i][1]-s[k][1])>s[k][j-1]?(s[i][1]-s[k][1]):s[k][j-1];
				if(temp>maxsum) {
					temp=maxsum;
				}
			}
			s[i][j]=temp;
		}
	}
	return s[n][m];
}

int main()
{
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	memset(s,0,sizeof(s));
	printf("%d\n",set(n,m));
	return 0;
}