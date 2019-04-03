/* 3.19 在给定的表达式中 判断出现的括号是否配对
   思路：
        在遍历表达式数组a时,若出现([{,则push入栈中,若出现)]},则判断与栈顶元素是否匹配
        匹配则将栈顶元素pop出栈,若不匹配,则这个表达式的括号不会匹配（如“[{]]”则不匹配
        若遍历完表达式数组a,pop == base,栈空,则匹配,否则不匹配

*/

#include <stdio.h>
#include <stdlib.h>

typedef char selemtype;

typedef struct stack
{
    selemtype *base;//顺序栈的首地址
    selemtype *top;//指向栈顶上一个元素的指针
}sqstack;

void init(sqstack * s)
{
    s->base = (selemtype *)malloc(20*sizeof(selemtype));//开一个以base为首地址的数组
    if(!s->base)exit(1);//没有成功malloc
    s->top = s->base;
}

void push(sqstack *s ,char x)
{
    if(s->top - s->base>= 20)//注意s是指针，要用->而不是.
    {
        printf("栈满");
        exit(1);
    }
    *s->top = x;
    s->top++;
}

void pop(sqstack * s)
{
    if(s->base == s->top)
    {
        printf("栈空");
        exit(1);
    }
    s->top--;
}

selemtype gettop(sqstack * s)
{
    if(s->base == s->top)//记住判断栈空还是满
    {
        //printf("栈空");//一般malloc没有分配到才exit（1） 因为实在没有办法啊
        return NULL;
    }
    char x;
    x = *(s->top-1);
    return x;
}

selemtype match(char *a,sqstack * s)
{
    char *p = a;
    for(;*p;p++)
    {
        if(*p == '('||*p == '['||*p == '{')
            {
                push(s,*p);
            }
        else if(*p == ')'||*p == ']'||*p == '}')
        {
            switch(*p)
            {
                case ')':
                {
                    if(gettop(s) == '(')pop(s);
                    else return 'N';
                    break;
                }
                case ']':
                {
                    if(gettop(s) == '[')pop(s);
                    else return 'N';
                    break;
                }
                case '}':
                {
                    if(gettop(s) == '{')pop(s);
                    else return 'N';
                    break;
                }
            }
        }
    }
    if(gettop(s) == NULL)return 'Y';
    else return 'N';
}

int main()
{
    char a[20] = {"([a+b]){[]}c"};
    sqstack s;
    init(&s);//给栈开一个长度为20的空间

    selemtype x = match(a,&s);
    if(x == 'N')printf("no");
    else printf("yes");

    return 0;
}
