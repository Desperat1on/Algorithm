/*
ѭ��һ�飬�����ܰ��������ֻҪʱ�䲻��ͻ������ͬһ���᳡
��������ѭ��һ�飬����ʣ�µĻ������һ���᳡ 
....
ֱ�����л��������
*/ 
#include<stdio.h>
struct node {
	int begin;
	int end;
	int flag;//��Ǹû�Ƿ񱻰��ţ�0��ʾδ���ţ�1��ʾ�Ѱ��� 
};
int main()
{
	int i,j,n;
	node temp,t[100];
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d%d",&t[i].begin,&t[i].end);
		t[i].flag=0;
	}
	for(i=0;i<n-1;i++) {  //����ÿ����Ľ���ʱ������������� 
		for(j=0;j<n-i-1;j++) {
			if(t[j].end>t[j+1].end) {
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
	}
	int sum=0;//�ܹ���Ҫ�Ļ᳡���� 
	int count=0;//��ǰ�Ѿ������˵Ļ���� 
	while(n-count>0) {
		int cur=0;//��ǰʱ�� 
		for(i=0;i<n;i++) { //��ÿһ�����ʱ���뵱ǰʱ����бȽ� 
			if(t[i].begin>cur && t[i].flag==0) { 
				t[i].flag=1;
				cur=t[i].end;
				count++;	
			} 
		}
		sum++;
	}
	printf("%d\n",sum);
	return 0;
}