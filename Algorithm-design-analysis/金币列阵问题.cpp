#include<stdio.h>
#include<iostream>  
#define N 100
using namespace std;  
  
int a[N][N],b[N][N],c[N][N];  
int count,m,n;  
  
void change1(int row)  
{//�б任
	int i; 
    for(i=0;i<n;i++)  
        c[row][i]=c[row][i]^1;  
    count++;  
}  
   
void change2(int col1,int col2)  
{//�б任
	int i;
    if(col1!=col2) {  
        for(i=0;i<m;i++)  
            swap(c[i][col1],c[i][col2]);  
        count++;  
    }  
}  
  
bool same(int col1,int col2)  
{//�Ƚ������Ƿ���ȫ��ͬ  
	int i;
    for(i=0;i<m;i++)  
        if(b[i][col1]!=c[i][col2])  
            return false;  
    return true;  
} 
   
int main()  
{  
    int min;
	int i,j,k;
	scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){  
        for(j=0;j<n;j++)  
            scanf("%d",&a[i][j]);  
    }       
    for(i=0;i<m;i++){  
        for(j=0;j<n;j++)  
            scanf("%d",&b[i][j]);  
    }           
    for(k=0;k<n;k++){//���Ƶ�k����Ϊ���� 
    	min=1000000;
        count=0;  
        for(i=0;i<m;i++){  
            for(j=0;j<n;j++)  
                c[i][j]=a[i][j];  
        } 
        change2(0,k);    
        for(i=0;i<m;i++) {  
            if(c[i][0]!=b[i][0])  
                change1(i);  
        }     
        int flag=0; 
        for(i=1;i<n;i++){  //�б任ʹ��Ŀ�������0����ͬ
        	flag=0;
            for(j=i;j<n;j++){  
                if(same(i,j)){//��ͬ��ֻ�����б任 
                    flag=1; 
                    change2(i,j);  
                    break;  
                }  
            }  
            if(!flag)  
                break;  
        }    
        if(flag && min>count) {   
            min=count;  
        }   
    }
    if(min<1000000)  
        printf("%d\n",min);  
    else   
        printf("-1\n");  
    return 0;  
}  
