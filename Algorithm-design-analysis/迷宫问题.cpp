#include<stdio.h>
#define m 5
#define n 5
int dic[5][2]={0,0,-1,0,1,0,0,-1,0,1};//��������������4������ 
int olddic=0,change=0;
int x0,x1,y0,y1;//�����յ������ 
int max;  //���任����
int flag=0;
char p[m][n]={
    '.','.','.','*','*',
    '*','.','*','*','.',
    '.','.','.','.','.',
    '.','.','.','.','.',
    '*','.','.','.','.'
};

int set(int x,int y) 
{//�߽���ϰ� 
	if(x<0 || y<0 || x>=m || y>=n || p[x][y]=='*')
		return false;
	return true;
}

void traceback(int x,int y)
{
	int i,temp;
	if(flag)
		return ;
	if(change>max+1)
		return ;
	if(x==x1 && y==y1) { //�����յ� 
		flag=1;
		return ;
	}
	for(i=1;i<=4;i++) { //forѭ������4������ 
		x+=dic[i][0];
		y+=dic[i][1];
		temp=olddic; //��¼һ��ԭ���ķ��򣨷��㻹ԭ���� 
		//д����ʱ������bug�� 
		if(set(x,y)) {  //�ж�λ���Ƿ���� 
			if(i!=olddic) //�͵�ǰ����ͬ  
				change++;
			olddic=i;//���·��� 
			traceback(x,y);
			olddic=temp; 
			if(i!=olddic)
				change--;
		}		
		x-=dic[i][0];
		y-=dic[i][1];	
	}
}
int main()
{
	printf("�������任����������յ������:\n");
	scanf("%d%d%d%d%d",&max,&x0,&y0,&x1,&y1); 
	traceback(x0,y0);
	if(flag==0)
		printf("No!\n");
	else
		printf("Yes!\n");
	return 0;
} 
