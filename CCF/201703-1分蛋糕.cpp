#include<iostream>
#include<cstdio>
int a[1001];
using namespace std;
int main()
{
	int n,k;
	int i,sum,num;
	while(~scanf("%d%d",&n,&k)) {
		sum=num=0;
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++) {
			sum+=a[i];
			if(sum>=k) {
				num++;
				sum=0;
			}
		}
		if(sum>0)//��sum=0,˵���������÷���;sum>0,˵����ʣ�൰��,��ָ����һ������ 
			num++;
		printf("%d\n",num);
	}
	return 0;
}
