#include<stdio.h>
#include<math.h>
int count=0;
int main()
{
	int i,j,num;
	for(i=0;i<=pow(2,14);i++) {
		int flower=0,store=0,drink=2;
		num=i;
		for(j=0;j<14;j++) {	//����2���ƣ�0����꣬1���� 
			if(num%2==1) {
				flower++;
				drink--;
			}
			if(num%2==0) {
				store++;
				drink*=2;
			}
			else {
				//ͨ���þ�ʣ��1����֤���һ�������� 
				if(flower==9 && store==5 && drink==1) {
					count++;
				}
			}
			num/=2;
		}
	}
	printf("%d\n",count); 
	return 0;
}