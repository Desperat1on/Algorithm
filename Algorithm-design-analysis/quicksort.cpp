#include<stdio.h>
int a[101];
void quicksort(int *a,int left,int right)
{
	int index,temp;
	if(left>=right)
		return ;
	
	index=a[left];  //index�д�ľ��ǻ�׼�� 
	int i=left;
	int j=right;
	while(i!=j)
	{
		while(a[j]>=index && i<j)
			j--;
			a[i]=a[j];
		while(a[i]<=index && i<j)
			i++;
			a[j]=a[i];
	}
	a[i]=index; //����׼����λ 
	quicksort(a,left,i-1);
	quicksort(a,i+1,right);
}
int main()
{
	int i,n;
	printf("�������������ֵĸ���:\n");
	scanf("%d",&n);
	printf("�������������:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("������Ϊ:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	getchar();getchar();
	return 0;
}
