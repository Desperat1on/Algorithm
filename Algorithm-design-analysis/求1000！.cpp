#include<stdio.h>
#define Max 10000
int main()
{   
	int result[Max]={0};
 	int len=1;    //��ʼλ��Ϊ1 
 	int flag=0;    //��λ��ֵ
    result[0]=1;   //��ʼ���Ϊ1
    int num;
    printf("������һ������:\n"); 
    scanf("%d",&num);
	for(int j=2;j<=num;j++) 
	{
		for(int i=0;i<len;i++)
		{
			int sum=result[i]*j+flag;  
            result[i]=sum%10;  
            flag=sum/10;  
        } 
        while(flag!=0)
		{//���λ��λֵ��Ϊ0ʱ,����λ�� 
            result[len]=flag%10;  
            len++;
            flag/=10;  
        }  
    }
	printf("%d�Ľ׳˽��Ϊ:\n",num);
    for(int i=len-1;i>=0;i--)
		printf("%d",result[i]); 
 }
