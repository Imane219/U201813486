/*实现 replace（&S，T，V） 用V替换S中出现的T 

基本函数：strassign， strinsert,kmp

debug历程：
  1.strassign里面不要判断s.ch是不是存在，存在就free（不要被书上伪代码骗了）
  2.strassign里面忘了给定s.length的值
  3.c是从0开始为第一个字符，那么next[0] = -1，j = -1，kmp函数没找到子串return的时候也得return -1 了，因为0代表子串在第一位 

*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char *ch;
	int length;
}Str;

void strassign(Str *s,char *ptr)//将ptr指向的字符串赋给s.ch 
{
	int i;
	for(i=0;ptr[i];i++)
		s->ch[i] = ptr[i];
	s->ch[i] = 0;//注意\0 
	s->length = i;
}

void getnext(Str t,int *next)
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<t.length)
	{
		if(j == -1||t.ch[i]==t.ch[j])
		{
			i++;j++;
			next[i]=j;
		}
		else
		j = next[j];
	}
}

int str_kmp(Str s,Str t,int pos)
{
	int i=pos;
	int j=0;
	int next[t.length];
	getnext(t,next);
	while(i<s.length&&j<t.length)
	{
		if(s.ch[i] == t.ch[j]||j==-1)
		{
			i++;j++;
		}
		else
		j=next[j];
	}
	if(j>=t.length) return i-t.length;
	else return -1;
}

int strinsert(Str *s,Str t,Str v)
{
	int m = str_kmp(*s,t,0);
	if(m!=-1)
	{
		if(v.length-t.length>=0)
		{
			int i,j = v.length-t.length;
			for(i=s->length;i>m;i--)//v比t长时，将数组pos之后向后移动，便于v插入 ,注意\0也要后移 
			{
				s->ch[i+j] = s->ch[i];
			}
			for(j=0;j<v.length;i++,j++)
			{
				s->ch[i]=v.ch[j];
			}
		}
		else//t比v长时 
		{
			int i,j;
			for(i=m,j=0;j<v.length;i++,j++)
			{
				s->ch[i]=v.ch[j];
			}
			j = t.length-v.length;
			i = m+v.length;
			for(;i+j<=s->length;i++)
			{
				s->ch[i] = s->ch[i+j]; 
			} 
		}
		return 1;
	}
	else
	return 0;
}

int main()
{
	Str s,t,v;
	s.ch = (char*)malloc(30*sizeof(char));
	t.ch = (char*)malloc(5*sizeof(char));
	v.ch = (char*)malloc(5*sizeof(char));
	
	//printf("please input s,t,v string");
	//scanf("%s",s.ch);getchar();
	//scanf("%s",t.ch);getchar();
	//scanf("%s",v.ch);
	
	strassign(&s,"abccdef k");
	strassign(&t,"c");
	strassign(&v,"mv");
	
	/*int next[5],i;
	getnext(t,next);
	for(i=0;i<t.length;i++)
	{
		printf("%3d",next[i]);
	}
	*/
	
	//int m = str_kmp(s,t,0);
	//printf("%d",m);
	
	int i = 0,j;
	for(i=0;;i++)
	{
		if(!strinsert(&s,t,v))
		break;
	}
	printf("%s",s.ch);



}





