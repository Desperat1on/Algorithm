#include<stdio.h>
#define m 5   //m������
#define n 4   //n����ɫ
int a[5][5]={
0,1,1,1,0,
1,0,1,1,1,
1,1,0,1,0,
1,1,1,0,1,
0,1,0,1,0};

int color[m]={0};//�洢m���������ɫѡ�񣬿���ѡ�����ɫΪ1��n
int count=0;

bool ok(int num) 
{
	int i; 
	for(i=0;i<num;i++)  { //ǰnum�����num���ڵĵ��У������г�ͻ����ɫ 
		if(a[num][i]==1 && color[i]==color[num]) {
			return false;
		}			 
	}
	return true;
}

void traceback(int num)
{
	int i;
	if(num==m) {
		count++;
		for(i=0;i<m;i++)
			printf("%d ",color[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++) {
		color[num]=i;
		if(ok(num))
			traceback(num+1);
		//color[num]=0   ÿ��ֻ����ǰnum���������Ƿ��г�ͻ��ɫ�����������ٸ�Ϊ0			
	}
}

int main()
{
	int i,j;
	traceback(0);
	printf("%d\n",count);
	return 0;
}