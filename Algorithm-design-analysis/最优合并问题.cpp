/*
1.����������ͽ��� 
2.�����ݴ������ø��ǣ����ö�̬������������
for(m=0;m<n-1;m++)
	a[m+1]+=a[m];
���磺5  12  6  2
��һ������2,5,6,12�� 2+5=7��  ��Ϊ2,7,6,12    min=6
�ڶ�������2,6,7,12;  6+7=13,  ��Ϊ2,6,13,12   min=6+12=18
����������2,6,12,13, 12+13=25,��Ϊ2,6,12,25   min=18+24=42 
*/ 
#include<stdio.h>
#include<algorithm>
using namespace std;
int m;
int a[100]={0},b[100]={0};

int cmp(int a,int b)
{//���� 
	return a>b;
}
void min(int *a,int n)
{//������� 
	int min=0;
	for(m=0;m<n-1;m++) { //n��������Ҫ����n-1�� 
		sort(a+m,a+n);//���� 
		a[m+1]+=a[m];//�������� 
		min+=a[m+1]-1;	
	}
	printf("min=%d\n",min);
}
void max(int *b,int n)
{//������ 
	int max=0;
	for(m=0;m<n-1;m++) {
		sort(b+m,b+n,cmp);//���� 
		b[m+1]+=b[m];
		max+=b[m+1]-1;	
	}
	printf("max=%d\n",max);
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	min(a,n);
	max(b,n);
	return 0;
}