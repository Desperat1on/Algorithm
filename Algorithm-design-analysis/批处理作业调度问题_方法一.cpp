/*
�÷���δʹ��ȫ���У������õ��ҽ������Ŀ��ͨ�ý���˼· 
��ȻĿǰ�ܶ�����ȫ���ж�д���������ܸо�����ȫ���У���û�г����׵�����
�侫�衣 
*/
#include<stdio.h>
#define N 100
int n;
int a[N]={0},b[N]={0};
int c[N]={0},bestc[N]={0};
int flag[N]={0};//��һ���������Ѿ�ʹ�ù������֣�1��ʾ�Ѿ�ʹ�ã�0��ʾδʹ�� 
int f1=0,f2=0,count=0;//f2ʹ�ñ������������� 
int best=1000000;

void traceback(int num)
{
	int i;
	if(num>n) {
		if(count<best) {
			best=count;
			for(i=1;i<=n;i++)
				bestc[i]=c[i];
		}
		return ;
	}
	//��ȫ���в�ͬ�ĵط� 
	for(i=1;i<=n;i++) { //һ����1--n����ҵ�ɹ�ѡ�� 
		if(flag[i]==0 && count<best) {
			flag[i]=1;
			f1+=a[i];
			/*ȫ����ʱ�õ�һά����f2[]������ʱ���軹ԭ������ʹ����ͨ�ı���f2��Ҫ���м�¼��
			�����Թ������olddirection*/
			int old=f2;
			f2=(f2>f1 ? f2 : f1) + b[i];
			c[num]=i;
			count+=f2;
			traceback(num+1);
			count-=f2;
			//c[num]=i;���軹ԭ 
			f2=old;
			f1-=a[i];
			flag[i]=0;
		}
	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
	}
	traceback(1);
	printf("%d\n",best);
	for(i=1;i<=n;i++) {
		printf("%d ",bestc[i]);
	}
	printf("\n");
	return 0;
} 
