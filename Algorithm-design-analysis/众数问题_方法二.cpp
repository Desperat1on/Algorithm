/*
ÿ�δ��м�����������ͬ�ģ�ͳ�Ƹ�����Ȼ��Ƚϴ�С������ 
*/ 
#include<stdio.h>
#include<algorithm>
#define N 100
using namespace std;
int a[N];
int temp=0,maxcount=0;

bool cmp(int m,int n)
{//sort�������������� 
	return m<n;
}

void set(int left,int right)
{
	int i,j;
	int count=1;
	int mid=(left+right)/2; 
	for(i=mid-1;i>=left;i--) { //���м����������ͬ�� 
		if(a[i]==a[mid])
			count++;
		else
			break; 
	}
	for(j=mid+1;j<=right;j++) {//���м����ұ�����ͬ�� 
		if(a[j]==a[mid])
			count++;
		else
			break;
	}
	if(count>maxcount)
	{
		maxcount=count;
		temp=a[mid];//��¼���� 
	}
	if(i-left>=maxcount)  //ֻ�е�������ֵĸ���>=��������벿�ֲ��п��ܴ��� 
		set(left,i);
	if(right-j>=maxcount)//ֻ�е��ұ����ֵĸ���>=�������Ұ벿�ֲ��п��ܴ���
		set(j,right);
}

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	for(i=0;i<n;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
	set(0,n-1);
	printf("����Ϊ��%d,����Ϊ��%d",temp,maxcount);
}
/*
10
3 6 89 3 4 5 3 1 6 3
*/