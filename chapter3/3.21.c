/*3.21 ����׺���ʽת�����沨��ʽ����׺���ʽ��

˼·��
    ����׺���ʽ����һ������a������һ������b���沨��ʽ������һ��ջ��push��popʵ��˳��ĸı�
    1.���������������������ĸ�ȣ�ֱ�Ӵ浽Ŀ������b
    2.������������push��ջ
    3.������������ջ��Ԫ��һ����pop������b��ֱ�������������У���������b
    4.�����������������ջ����������Ƚ����ȼ���
        ��1�������ȼ�����ջ������������ȼ�����push
        ��2�������ȼ�С��ջ����������ȼ�����popջ�������������b���Ƚϵ�������������µ�ջ��������Ƚ�
             ֱ�����ȼ�����ջ��push��Ϊֹ
    5.a�ߵ���ĩβ����ջ��ʣ�������pop����b

*/


#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef char selemtype;

typedef struct stack
{
    char * base;
    char * top;
}stack,* pstack;

pstack initstack()
{
    stack op;
    pstack s = &op;
    op.base = (char*)malloc(N*sizeof(char));
    op.top = op.base;
    if(op.base == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    return s;
}

void push(pstack s,char x)
{
    if(s->top - s->base >= N )
        printf("ջ��");
    *s->top++ = x;
}

void pop(pstack s,char *px)
{
    if(s->base == s->top)
        printf("ջ��");
    *px = *(--s->top);
}

char gettop(pstack s)
{
    char x;
    if(s->base == s->top)
        x = '0';
    else
        x = *(s->top-1);
    return x;
}

char compare(pstack s,char x)
{
    if(gettop(s) =='0'&&(x<'a'||x>'z'))
        return '3';
    /*else if(x == '+'||x == '-')
        return '+';
    else if((x == '*'||x == '/')&&(gettop(s) == '+'||gettop(s) == '-'))
        return '>';
    else if((x == '*'||x == '/')&&(gettop(s) == '*'||gettop(s) == '/'))
        return '<';
    else return '0';
*/
}

int main()
{
    //char a[N] = {"-"};
    //char b[N]= {0};
    //char *pb = b;
    pstack s = initstack();
    //char *p = a;

	char m = '*';
	if(gettop(s) =='0'&&(m<'a'||m>'z'))
		printf("%c",'=');
    char x = compare(s,'*');
    printf("%c",x);

    /*for(;*p;p++)
    {
        switch(compare(s,*p))
        {
            case '>':  push(s,*p); break;
            case '<':  pop(s,pb);pb++;p--;break;
            default :  *pb = *p;pb++;break;
        }
    }

    for(;s->top!=s->base;pb++)pop(s,pb);
    printf("%s",b);
    */return 0;
}
