//����˼�룺��������
#include<stdio.h>
int m,n;
int count=0;
int a[100][100]; 

bool set(int row,int col)
{//����row�е�col���ϵĸ�����������ϵ������Ƿ��ͻ 
	int i;
	for(i=0;i<row;i++) {
		if(a[i][col]==a[row][col])
			return false; 
	}
	return true;
}

void traceback(int row,int col)
{
	int i,j,k,temp;
	for(i=col;i<n;i++) {   //������(�ڸ����Ͻ���ȫ����)
		temp=a[row][col];
		a[row][col]=a[row][i];
		a[row][i]=temp;
		if(set(row,col)) {
			//���ж������ж�����4�ֿ��ܣ����к�����3�� 
			if(col==n-1) { //�д�����
				if(row==m-1) { //�д����� 
					count++;
					return ;
				} 
				else {
					traceback(row+1,0); //����������һ�� 
				}
			}
			else {
				traceback(row,col+1); //����������һ�� 
			}	
		} 
		temp=a[row][col];
		a[row][col]=a[row][i];
		a[row][i]=temp;
	}
}

int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	//�����ʼ�� 
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++){
			a[i][j]=j+1;
		}
	}	 
	traceback(0,0);
	printf("%d\n",count);
	return 0;
}