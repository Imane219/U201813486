/* 3.19 �ڸ����ı��ʽ�� �жϳ��ֵ������Ƿ����
   ˼·��
        �ڱ������ʽ����aʱ,������([{,��push��ջ��,������)]},���ж���ջ��Ԫ���Ƿ�ƥ��
        ƥ����ջ��Ԫ��pop��ջ,����ƥ��,��������ʽ�����Ų���ƥ�䣨�硰[{]]����ƥ��
        ����������ʽ����a,pop == base,ջ��,��ƥ��,����ƥ��

*/

#include <stdio.h>
#include <stdlib.h>

typedef char selemtype;

typedef struct stack
{
    selemtype *base;//˳��ջ���׵�ַ
    selemtype *top;//ָ��ջ����һ��Ԫ�ص�ָ��
}sqstack;

void init(sqstack * s)
{
    s->base = (selemtype *)malloc(20*sizeof(selemtype));//��һ����baseΪ�׵�ַ������
    if(!s->base)exit(1);//û�гɹ�malloc
    s->top = s->base;
}

void push(sqstack *s ,char x)
{
    if(s->top - s->base>= 20)//ע��s��ָ�룬Ҫ��->������.
    {
        printf("ջ��");
        exit(1);
    }
    *s->top = x;
    s->top++;
}

void pop(sqstack * s)
{
    if(s->base == s->top)
    {
        printf("ջ��");
        exit(1);
    }
    s->top--;
}

selemtype gettop(sqstack * s)
{
    if(s->base == s->top)//��ס�ж�ջ�ջ�����
    {
        //printf("ջ��");//һ��mallocû�з��䵽��exit��1�� ��Ϊʵ��û�а취��
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
    init(&s);//��ջ��һ������Ϊ20�Ŀռ�

    selemtype x = match(a,&s);
    if(x == 'N')printf("no");
    else printf("yes");

    return 0;
}
