/*
�������������һ���Ĵ���ʽ��һ��һ�е��ߡ�
������bug���������������֣��ٽ��и����жϣ�������ֹ����row==n-1��col==n-1������n 
*/ 
#include<stdio.h>
#define n 9 
int a[n][n]={
0, 0, 5, 3, 0, 0, 0, 0, 0,
8, 0, 0, 0, 0, 0, 0, 2, 0,
0, 7, 0, 0, 1, 0, 5, 0, 0,
4, 0, 0, 0, 0, 5, 3, 0, 0,
0, 1, 0, 0, 7, 0, 0, 0, 6,
0, 0, 3, 2, 0, 0, 0, 8, 0,
0, 6, 0, 5, 0, 0, 0, 0, 9,
0, 0, 4, 0, 0, 0, 0, 3, 0,
0, 0, 0, 0, 0, 9, 7, 0, 0
};

bool ok(int x,int y) 
{
	int i,j,x0,y0;
	x0=x/3*3; 
	y0=y/3*3;
	for(i=0;i<n;i++) {  //���ڵ�����û����ͬ���� 
		if(i!=x && a[i][y]==a[x][y])
			return false;
	}
	for(j=0;j<n;j++) {  //���ڵ�����û����ͬ����
		if(j!=y && a[x][j]==a[x][y])
			return false;
	} 
	for(i=x0;i<x0+3;i++) {  //3*3�ķ�����û����ͬ���� 
		for(j=y0;j<y0+3;j++) {
			if(i!=x || j!=y) 
				if(a[i][j]==a[x][y])
					return false;
		}
	} 
	return true; 
} 

void traceback(int row,int col)
{
	int i,j,k;
	if(a[row][col]==0) { //��ǰ����Ҫ��� 
		for(k=1;k<=n;k++) { //���1~9 
			a[row][col]=k;
			if(ok(row,col))
			{
				if(col==n-1) //�ж���һ�����ڵ����Ƿ���� 
				{		
					if(row==n-1) //�ж����Ƿ���� 
					{
						for(i=0;i<n;i++) {
							for(j=0;j<n;j++)
								printf("%d ",a[i][j]);
							printf("\n");
						}
						return ;		
					} 
					else 
					{
						traceback(row+1,0);
					}
				} 
				else 
				{
					traceback(row,col+1);
				}
			}
			a[row][col]=0;
		}
	} else {
		if(col==n-1) 
		{		
			if(row==n-1)
			{
				for(i=0;i<n;i++) {
					for(j=0;j<n;j++)
						printf("%d ",a[i][j]);
					printf("\n");
				}
				return ;		
			} 
			else 
			{
				traceback(row+1,0);
			}
		} 
		else 
		{
			traceback(row,col+1);
		}
	}
}

int main()
{
	int i,j;
	traceback(0,0);	
	return 0;
}