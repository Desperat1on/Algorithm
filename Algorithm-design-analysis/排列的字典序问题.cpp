#include<stdio.h>
int set(int n)
{//��n�Ľ׳� 
    int sum=1;
    for(int i=2;i<=n;i++)
        sum*=i;
    return sum;
}
void reverse(int a[],int min,int n)
{//�������� 
	int i,j,temp;
	for(i=min,j=n-1;i<j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
void swap(int &a,int &b)
{//����Ԫ�� 
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void output(int a[],int n)
{//��� 
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	putchar('\n');
}
int num(int a[],int n)
{//���ֵ����ֵ 
    int count=0;
    int b[n];
    for(int i=0;i<n;i++)
    	b[i]=a[i];//�������飬���޸�ԭ�������ֵ����������һ���ֵ��� 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
		{
        	if(a[j]>a[i])
        		b[j]--;//����a[i],���a[i+1]��a[n-1]��ֵ�Ƿ��a[i]������ǣ����ֵ��1 
        }
        count+=set(n-i-1)*(b[i]-1);
    }
    return count;
}
void next(int a[],int n)
{//�����һ���ֵ��� 
    int min,max;
    for(int i=n-1;i>=0;i--)
    {//�ҳ������ֹ��������±� 
    	if(a[i-1]<a[i])
    	{
	        min=i-1;
	        break;
    	}
    }
	for(int i=n-1;i>=0;i--)
	{//�ҳ��ոձ�a[min]����� 
	    if(a[i]>a[min])
	    {
	        max=i;
	        break;
	    }
	}  
    swap(a[min],a[max]);
    reverse(a,min+1,n);//ע�⽻������a[min+1]��a[n] 
    output(a,n);
}
int main()
{
    int n;
    printf("Ԫ�ظ���:\n");
    scanf("%d",&n);
    int *a=new int[n];
    printf("�����뵱ǰ�ַ����У�\n");
    for(int i=0;i<n;i++)
    	scanf("%d",&a[i]);
   	getchar();
    int count=num(a,n);
    printf("��ǰ�ַ����ֵ���ֵΪ��%d\n",count);
    printf("��һ�ֵ�������Ϊ��");
    next(a,n);
    return 0;
} 
