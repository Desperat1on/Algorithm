//row�����ˣ�����i�����˰��ŵ�j������ 
#include<stdio.h>
int a[100][100]={0};
int b[100]={0};
int n;
int sum=0;
int min=100000;
void traceback(int row)
{
	int i,j;
	if(sum>=min)  //ֻҪsum>=min��ֱ���жϣ����м�֦ 
		return ;
	if(row==n) { 
		min=sum;
		return ;
	}
	for(j=0;j<n;j++) {
		if(b[j]==0) {  //����һά��������ǵ�j�������Ƿ񱻷���
			b[j]=1;
			sum+=a[row][j];
			traceback(row+1);
			b[j]=0;
			sum-=a[row][j];
		}
	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	traceback(0);
	printf("%d\n",min);
	return 0;
}