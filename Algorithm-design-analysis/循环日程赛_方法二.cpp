#include<stdio.h>
#define max 100
#define n 8 
int main()
{
	int i,j,k,p,q,index;
	k=1;              //ÿ�δ�������� 
	index=1;          //����ڼ��� 
	int direction;   //���Ʒ��� 
	int a[max][max];
	for(i=0;i<n;i++) {   //��ʼ����һ�� 
		a[0][i]=i+1;
	}
	while(k<n) {
		direction=1;
		i=0; 
		while(i<n) { 
			for(p=index;p<index+k;p++) {  //������ 
				for(q=i;q<i+k;q++) {   //������ 
					a[p][q]=a[p-k][q+direction*k];
				}	
			}
			direction*=-1;
			i+=k;
		}
		index+=k;
		k*=2;
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++)
			printf("%3d",a[i][j]);
		putchar('\n');
	}
	return 0;
}
