/*
  ʵ��Concat(&T,s1,s2)
  ��s1��s2��������������T 
  
  debug����
    1.strassign����ֻ�ǰ���֪���ַ�������һ���Ѿ����˿ռ�������ڣ�
	  ��strassign�����в���malloc����Ϊ�˳��������ݾͻ����������malloc�ķ���ֵ��void
	 

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


