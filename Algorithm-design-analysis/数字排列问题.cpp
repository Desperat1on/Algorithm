/*
�������С������֡����������������⡣
��������ģʽ����Ŀ�����Ǵ�ͷ��β���뷶Χ�ڵ����֣��Ը�λ�õ����ֽ����ж��Ƿ����������
����˵�� ���ݰ�ı���������������ȫ�����������ٽ����жϡ� 
����άʱ���к��н������룬�ж�ʱ���ж���Ԫ�أ� 
*/ 
#include<stdio.h>
#define n 14
int a[n]={0};
int set(int num)
{//�жϵ���ǰλ���Ƿ��Ѿ�ʹ�ù������� 
	int i;
	for(i=0;i<num;i++) {
		if(a[i]==a[num])
			return false;
	}
	return true;
} 
void traceback(int num)
{
	int i,j;
	if(num==n) {
		for(i=0;i<n;i++) {
			printf("%d",a[i]);
		}
		printf("\n");
		return ;
	}
	if(a[num]==0) {
		for(i=1;i<7;i++) {
			a[num]=i;
			if(a[num+i+1]==0 && set(num)) {//�ж��Ƿ��������� 
				a[num+i+1]=i;//ͬʱ����������ͬ������ 
				traceback(num+1);
				a[num+i+1]=0;
			}	
			a[num]=0;
		}
	}
	else
		traceback(num+1);
} 
int main()
{
	a[0]=7,a[1]=4,a[6]=4,a[8]=7;
	traceback(2);
	return 0;
} 