/*�����������д�1--len���д�1--k 
1)  m(i,j)=w(1,i)������j=1ʱ�� 
2)  m(i,j)=max{m(k,j-1)*w(k+1,i),m(i,j)};  (2<j<=i)
    ����1<=k<i (��k��1��ʼһֱ��i-1�������ֵ)
*/ 
#include<stdio.h>
#include<math.h>
#define N 100 
int max[N][N]={{0,0}};  //max[i][j]��ǰiλ(1--i)�ֳ�j�����õ����˻�
int w[N][N]={{0,0}}; // w[i][j]�ӵ�iλ����jλ����ɵ�ʮ������
int a[N]={0};
int main()
{
	int i,j,m,n,k,len;
	scanf("%d%d",&len,&m);
	scanf("%d",&n);
	for(i=len;i>0;i--) {
		a[i]=n%10;
		n/=10; 
	}
	for(i=1;i<=len;i++) { //������ӵ�iλ����jλ��ɵ�ʮ������
		w[i][i]=a[i];
		for(j=i+1;j<=len;j++) 
			w[i][j]=w[i][j-1]*10+a[j];
	}
	for(i=1;i<=len;i++) {  //�ֳ�1�Σ��Ƚ���һ�й���� 
		max[i][1]=w[1][i];
	}
	for(i=2;i<=len;i++) { //�ӵڶ��п�ʼ������������ڵ�ÿһ����Ԫ�� 
		for(j=2;j<=i;j++) {  //ǰi�����֣�����Ϊ2--i�� 
			for(k=1;k<i;k++) {
				if(max[k][j-1]*w[k+1][i]>max[i][j])
					max[i][j]=max[k][j-1]*w[k+1][i];
			}
		}
	}
	for(i=1;i<=len;i++) {
		for(j=1;j<=m;j++) {
			printf("%7d",max[i][j]);
		}
		printf("\n");
	} 
	printf("%d\n",max[len][m]);
	return 0;
}
