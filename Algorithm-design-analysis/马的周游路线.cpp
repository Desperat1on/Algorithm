#include<stdio.h>  
#include<stdlib.h>  
#define max 101   
  
int m,n;//���̴�С  
int start_x,start_y;//���λ��  
int dx[8]={-2,-1,1,2,-2,-1,2,1};  
int dy[8]={-1,-2,-2,-1,1,2,1,2};  
int board[max][max]={0};  
  
int finish(int x,int y)  
{//�ж��Ƿ�����·   
    if(x<1 || y<1 || x>m || y>n || board[x][y]!=0)  
        return 0;  
    else  
        return 1;  
}  
int next_move(int x,int y)  
{//�ж���һ���ܷ�ص����   
    for(int i=0;i<8;i++)  
        if(x+dx[i]==start_x && y+dy[i]==start_y)   
            return 1;  
    return 0;  
}  
void show(int n,int m)  
{//���·��   
    for(int i=1;i<=m;i++) {  
        for(int j=1;j<=n;j++)  
            printf("%3d",board[i][j]);  
        printf("\n");  
    }         
}  
void move(int x,int y,int num)  
{  
    if(num==n*m && next_move(x,y)) {  
        show(n,m);  
        exit(1);  
    }  
    for(int i=0;i<8;i++) {  
        int next_x=x+dx[i];  
        int next_y=y+dy[i];  
        if(finish(next_x,next_y)) {  
            board[next_x][next_y]=num+1;  
            move(next_x,next_y,num+1);  
            board[next_x][next_y]=0;  
        }  
    }  
}  
int main()  
{  
    printf("���������̵�����������:\n");  
    scanf("%d%d",&m,&n);  
    printf("��������ʼ����:\n");  
    scanf("%d%d",&start_x,&start_y);  
    board[start_x][start_y]=1;  
    int number=1;
    printf("�������·��Ϊ:\n");  
    move(start_x,start_y,number);  
    return 0;  
}
