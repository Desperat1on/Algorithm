#include<stdio.h>
#include<math.h>

void MaxCount(int num1,int num2)
{//������Լ������
    int max=0;
    for(int i=num1;i<=num2;i++)
    {
        int count=0;
        if(i*2<=num2)
            continue;
        else
        {
            for(int j=1;j<=sqrt(i);j++)
            {
                if(i%j==0)
                    count+=2;
                if(j*j==i)
                    count--; //��ȥһ����ͬ��
            }
            if(count>max)
                max=count;
        }
    }
    printf("%d",max);
}

int main()
{
    int i,j;
    scanf("%d%d",&i,&j);
    if(i>=j)
        return 0;
    MaxCount(i,j);
}
