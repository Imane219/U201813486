/*求串所含的不同字符的总数和每种字符的个数

  思想:将串s从头开始扫描，每扫到一个不同的字符，则存如入串record（初值为0）的末尾，并将数组count对应位置值+1
  若相同，则将对应的数组值+1，不存入record 

  debug历程：calculate中的i,j一开始搞反了，以为s是i 

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



