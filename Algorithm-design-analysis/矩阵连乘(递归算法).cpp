#include<stdio.h>
#include<string.h>
#define Num 100
int p[Num],s[Num][Num];

void traceback(int i,int j) 
{
	if(i==j)
		return;
	traceback(i,s[i][j]);     
	traceback(s[i][j]+1,j);
	printf("%d-%d��%d-%d\n",i,s[i][j],s[i][j]+1,j);
}
int set(int i,int j)
{
	if(i==j)
		return 0;
	int m=set(i,i)+set(i+1,j)+p[i-1]*p[i]*p[j];//�ݹ�
	s[i][j]=i;//��¼�����ŵ�λ��
	for(int k=i+1;k<j;k++) {
		int t=set(i,k)+set(k+1,j)+p[i-1]*p[k]*p[j];
		if(t<m)
		{//ѡ����Сֵ 
			m=t;
			s[i][j]=k;
		}
	} 
	return m;
}
int main()
{
	int n;
	scanf("%d",&n); 
	for(int i=0;i<=n;i++) {
		scanf("%d",&p[i]);
	}
	printf("%d\n",set(1,n));
	traceback(1,n);
	return 0;
}