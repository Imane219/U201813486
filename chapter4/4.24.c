/*
  实现Concat(&T,s1,s2)
  将s1，s2连接起来，存在T 
  
  debug历程
    1.strassign函数只是把已知的字符串存入一个已经开了空间的数组内，
	  但strassign函数中不能malloc，因为退出函数数据就会清除，所以malloc的返回值是void
	 

*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char * ch;
	int length;
}str;

void strassign(str *s,char * pstr)
{
	int i;
	for(i=0;pstr[i];i++)s->ch[i]=pstr[i];
	s->length = i;
	s->ch[i] = 0;
}

void Concat(str *T,str s1,str s2)
{
	int i,j;
	for(i=0;i<s1.length;i++)
	{
		T->ch[i]=s1.ch[i];
	}
	for(j=0;i<s1.length+s2.length;i++,j++)
	{
		T->ch[i]=s2.ch[j];
	}
	T->ch[i]=0;
} 

int main()
{
	str s1,s2;
	s1.ch = (char *)malloc(10*sizeof(char));
	s2.ch = (char *)malloc(10*sizeof(char));
	
	strassign(&s1,"abcdeee");
	strassign(&s2,"+=-%^&yfg");
	
	str T;
	T.length = s1.length +s2.length;
	T.ch = (char *)malloc(T.length*sizeof(char));
	
	Concat(&T,s1,s2);
	
	printf("%s",T.ch);
}


