#include<stdio.h>
int main()
{
	int i,j,k,m,n;
	int min;
	while(scanf("%d",&n)!=EOF) {
		int a[100][100]={0};
		for(i=1;i<n;i++) {
			for(j=i+1;j<=n;j++) {
				scanf("%d",&a[i][j]); 
			} 
		}
		for(m=2;m<=n;m++) {   //����m��վ�� 
			for(i=1;i<=n-m+1;i++) {  //��ÿһ��վ�㿪ʼ 
				j=m+i-1;   //r(i,j)�ĳ���Ϊj 
				for(k=i;k<=j;k++) {  //�ҳ�ĳһվk��ʹr(i,k)+r(k,j)��С 
					min=a[i][k]+a[k][j];
					if(a[i][j]>min) {
						a[i][j]=min;
					}
				} 
			}
		}
		printf("%d\n",a[1][n]);
		putchar('\n');
	} 
	return 0;
}