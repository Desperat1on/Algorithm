#include <stdio.h>
#include <string.h>
#define Max 1001
int main()
{
    char str1[Max],str2[Max];
    char str[Max]={0};
    int flag=0;
    int i,j,k,m,n,len;
    printf("�������һ������:\n");
    scanf("%s",str1);
    printf("������ڶ�������:\n");
    scanf("%s",str2);
    m=strlen(str1);
    n=strlen(str2);
    len=(m>n)?m:n;
    for(i=m-1,j=n-1,k=len-1;i>=0 && j>=0;i--,j--,k--) 
    {//���ȳ��ȵĲ������,ʣ�µĲ��ֵ������� 
        str[k]=((str1[i]-'0')+(str2[j]-'0')+flag)%10+'0';
        flag=((str1[i]-'0')+(str2[j]-'0')+flag)/10;
    }
    while(i>=0)
    {//���str1�ĳ��ȱ�str2�ĳ��ȳ�,����str1ʣ�µĳ���
        str[k]=((str1[i]-'0')+flag)%10+'0';
        flag=((str1[i]-'0')+flag)/10;
        i--;
        k--;
    }
    while(j>=0)
    {//���str2�ĳ��ȱ�str1�ĳ��ȳ�,����str2ʣ�µĳ���
        str[k]=((str2[j]-'0')+flag)%10+'0';
        flag=((str2[j]-'0')+flag)/10;
        j--;
        k--;
    }
    if(flag!=0)
    {//���λ��λֵ��Ϊ0ʱ,���ȼ�1 
        for(k=len;k>0;k--)
            str[k]=str[k-1];
        str[0]=flag+'0';
    }
    printf("%s\n",str);
}
