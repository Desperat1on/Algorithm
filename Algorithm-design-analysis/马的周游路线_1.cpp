#include <stdio.h>
#include <stdlib.h>
#define N 15
int chess[N][N]={0}; //����
int move[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int count=0;//�Խ�ĸ�������

int finish(int x, int y)
{//�ж��Ƿ�����· 
    if (x>=0 && x<N && y>=0 && y<N && chess[x][y]==0)
        return 1;
    return 0;
}
int weight(int x,int y)
{//��Ȩֵ
    int count=0;
    for (int i=0;i<8;++i)
    {
        if(finish(x+move[i][0],y+move[i][1]))
            count++;
    }
    return count;
}
void sort(int a[],int b[],int n)
{//Ȩֵ����
    if (n<0) return;
    for (int i=0;i<n;++i)
    {
        for (int j=i;j>0;--j)
        {
            if (a[j]<a[j-1])
            {
                int temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
                temp=b[j-1];
                b[j-1]=b[j];
                b[j]=temp;
            }
        }
    }
}
void output()
{//������
    int i;
    for(i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            printf("%3d ",chess[i][j]);
        putchar('\n');
    }
}
void BackTrace(int t,int x,int y)
{//����
    if(t>=N*N)
    {
        count++;
        output();
        exit(1);
    }
    else
    {
        int i;
        int count[8],next[8];
        int k=0;
        for(i=0;i<8;++i)
        {
            if(finish(x+move[i][0],y+move[i][1]))
            {
                count[k]=weight(x+move[i][0],y+move[i][1]); //��Ȩֵ
                next[k++]=i;//������һ���������
            }
        }
        sort(count,next,k);
        for(i=0;i<k;++i)
        {
            int m=next[i];
            x+=move[m][0];
            y+=move[m][1];
            chess[x][y]=t+1;
            BackTrace(t+1,x,y);
            chess[x][y]=0;
            x-=move[m][0];
            y-=move[m][1];  
        }
    }
}
int main()
{ 
    int x=0;
    int y=0;
    int number=1;
    chess[x][y]=1;
    printf("�������·��Ϊ:\n");
    BackTrace(number,x,y);
}
