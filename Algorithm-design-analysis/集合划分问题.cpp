#include<stdio.h>
int set(int n,int m)
{
	if(m==n || m==1)
		return 1;
	//1:��ǰn-1��Ԫ�طֳ�m-1�ݣ�Ȼ���n��Ԫ�ص����š�
    //2:��ǰn-1��Ԫ�طֳ�m�ݣ�Ȼ���n���طֱ���뵽��m��������
	return set(n-1,m-1)+m*set(n-1,m);
}
int main()
{
	int m,n;
	int count=0;
	printf("������Ԫ�ظ���:\n"); 
	scanf("%d",&n);
	for(m=1;m<=n;m++)
	{
		count+=set(n,m);
	}
	printf("�ǿ��Ӽ���Ϊ��%d\n",count);
}