/*
row������������̨�׼�����step�������Ĳ����� 
*/
#include<stdio.h>
#define n 39
int count=0;

void traceback(int row,int step)
{
	if(row>n)  //�ߵ�̨�׼�������n����ֹ 
		return ;
	if(row==n && step%2==0) { //����n�����Ҳ���Ϊż������������ 
		count++;
		return ;
	}
	for(int i=1;i<=2;i++) {  //����ѭ��ģ��ÿ����һ��̨�׻�������̨�� 
		traceback(row+i,step+1);
	}
}

int main()
{
	traceback(0,0);
	printf("%d\n",count);
	return 0;
}