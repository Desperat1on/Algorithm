#include<stdio.h>
#include<string.h>
int combine(int m,int n)
{//���������ֵ 
	int sum1=1;
	int sum2=1;
	if(m>n)
		return 0;
	if(2*m>n)
		m=n-m;
	for(int i=1;i<=m;i++){
		sum1*=n-i+1;
		sum2*=i;
	}
	return sum1/sum2;
}
int count(char str[],int low)
{
	int sum=0;
	char high=str[0];
	int len=strlen(str);
	int temp=low;
	for(int k=1;k<=high-'a'-low;k++)
	{//���Ⱥ��ַ�����ȵģ�������ĸ֮ǰ�� 
		sum+=combine(len-1,26-temp-k);
	}
	if(len>1)
	{
		sum+=count(&str[1],high-'a'+1);  //�ݹ�,���ȼ�һ 
	}	
	return sum;
}
int main()
{
	int n;
	printf("�������ַ����ĸ���:\n"); 
	scanf("%d",&n);
	while(n--){
		printf("�������ַ�����"); 
		char str[10];
		scanf("%s",str);
		int sum=0;
		for(int i=1;i<strlen(str);i++){  //����С���ַ������ȵ�ֵ 
			sum+=combine(i,26);
		}
		printf("���ַ����ı���Ϊ��%d\n",sum+count(str,0)+1);
	}
}
