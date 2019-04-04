/*3.21 将中缀表达式转换成逆波兰式（后缀表达式）

思路：
    将中缀表达式存入一个数组a，用另一个数组b存逆波兰式，并用一个栈的push与pop实现顺序的改变
    1.若遇到非运算符，数字字母等，直接存到目标数组b
    2.若遇到（，则push入栈
    3.若遇到），则将栈中元素一个个pop并存入b，直到遇到（。其中（）不存入b
    4.若遇到运算符，则与栈顶的运算符比较优先级：
        （1）若优先级大于栈顶运算符的优先级，则push
        （2）若优先级小于栈顶运算符优先级，则pop栈顶运算符并存入b，比较的运算符继续与新的栈顶运算符比较
             直到优先级大于栈顶push入为止
    5.a走到了末尾，将栈内剩余运算符pop存入b

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
        printf("栈满");
    *s->top++ = x;
}

void pop(pstack s,char *px)
{
    if(s->base == s->top)
        printf("栈空");
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
