#include<stdio.h>
#include<string.h> 
int main()
{
	char a[100];
	int i,j,k,n;
	while(scanf("%s%d",a,&n)!=EOF) {
		int len=strlen(a);
		for(i=1;i<=n;i++) {  //ɾ��n�����֣�ѭ��n�� 
			for(j=1;j<=len-i;j++) { //ÿ�δ�ͷ��ʼ�ҽ��� 
				if(a[j]<a[j-1]) {
					for(k=j;k<=len-i;k++) { //�ҵ�����㣬����ɾ�� 
						a[k-1]=a[k];
					}
					break;
				}
			}
		}
		//len���ȵ����֣�ɾ��n����������len-n������ 
		for(i=0;i<(len-n);i++)
			printf("%c",a[i]);
		printf("\n"); 
	}
	return 0;
} 
