/*�������Ĳ�ͬ�ַ���������ÿ���ַ��ĸ���

  ˼��:����s��ͷ��ʼɨ�裬ÿɨ��һ����ͬ���ַ���������봮record����ֵΪ0����ĩβ����������count��Ӧλ��ֵ+1
  ����ͬ���򽫶�Ӧ������ֵ+1��������record 

  debug���̣�calculate�е�i,jһ��ʼ�㷴�ˣ���Ϊs��i 

*/ 


#include <stdio.h>
#include <stdlib.h>

int sub(char x,char *record)
{
	int i;
	for(i=0;record[i];i++)
	{
		if(record[i]==x)
			return i;
	}
	return -1;
}

void calculate(char *s,char *record,int *count)
{
	int i,j,m;
	for(i=0,j=0;s[j];i++,j++)
	{
		if(i==0||(m=sub(s[j],record))==-1)
		{
			record[i]=s[j];
			count[i]++;
		}
		else
		{
			count[m]++;
			i--;
		}
	}
}


int main()
{
	char s[20] = {"abbcdfg*&^5(99)"};
	char record[20]={0};
	int count[20]={0};
	
	calculate(s,record,count);
	
	printf("%s\n",record);
	int i;
	for(i=0;count[i];i++)
	{
		printf("%3d",count[i]);
	}
} 



