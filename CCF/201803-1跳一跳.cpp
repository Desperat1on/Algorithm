#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	int score=0;
	int count=0;//ͳ��������2�ĸ��� 
	while(scanf("%d",&n) && n!=0) {
		if(n==1) {
			score++;
			count=0;//��2�жϣ�count��0 
		}
		else if(n==2){
			count++;
			score+=count*2;
		}	
	}
	printf("%d\n",score);
	return 0;
} 
