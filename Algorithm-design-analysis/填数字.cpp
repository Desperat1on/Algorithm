#include<stdio.h>
#define n 12
int a[n+1]={0}; //ͳ���Ѿ�ʹ�ù������֣�0����δʹ�� 
int temp[n]={0};//ͼ�е�ÿ��λ�� 
void traceback(int num)
{
	int i,j;
	if(num==10) {
		int b[6]={0};
		b[0]=1+temp[1]+temp[4]+temp[6];
		b[1]=1+temp[2]+temp[5]+temp[9];
		b[2]=temp[6]+temp[7]+temp[8]+temp[9];
		b[3]=8+temp[1]+temp[2]+temp[3];
		b[4]=8+temp[4]+temp[7]+3;
		b[5]=3+temp[3]+temp[5]+temp[8];
		for(j=0;j<5;j++) {
			if(b[j]!=b[j+1])
				return ;
		}
		printf("%d\n",temp[4]); 
	}
	for(i=2;i<=12;i++) { //1-9��λ��������������ַ�Χ
		temp[num]=i; //���������  
		if(a[i]==0) { //���������δʹ�ù���traceback��+1 
			a[i]=i;//��¼һ�¸������Ѿ�ʹ���� 			
			traceback(num+1);			
			a[i]=0;
		}	
		temp[num]=0; 
	}
}
int main()
{
	int i,j;
	a[1]=1,a[3]=3,a[8]=8;
	traceback(1);
	return 0;
} 
