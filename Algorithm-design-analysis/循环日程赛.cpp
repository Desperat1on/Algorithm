#include<stdio.h>
#define max 1000
int a[max][max];
void show_table(int sum) {
	printf("��������ճ�:\n"); 
	for(int i=1;i<=sum;i++) {
		for(int j=1;j<=sum;j++) {
			printf("%3d",a[i][j]);
		}
		putchar('\n');
	}
}
void input_table(int k)
{
	int i,j;
	int n=1;
	for(i=1;i<=k;i++)
		n*=2;
	int sum=n;//��������¼���� 
	for(int i=1;i<=n;i++)
		a[1][i]=i;    //�����ճ̱��һ��
	int m=1;  //ÿ�����ʱ����ʼλ�� 
	for(int s=1;s<=k;s++) {  //�����Ϊk���� 
		n/=2;   //ÿһ�����ַ�ΪnС�� 
		for(int t=1;t<=n;t++) {  
			for(int i=m+1;i<=2*m;i++) {       //������ 
				for(int j=m+1;j<=2*m;j++) {  //������ 
					a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];//���½ǵ������Ͻǵ�ֵ  
                    a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];//���½ǵ������Ͻǵ�ֵ  
				}
			}
		}
		m*=2;
	}
	show_table(sum);
}
int main()
{
	int k;
	printf("������k��ֵ:\n");
	scanf("%d",&k);
	input_table(k);
	return 0;
} 
