/*单链表以值递增方式排列，删除表中所有值大于mink小于maxk的元素

变量说明：l为表首，存的值为0，没有头结点

*/

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct Node
{
    datatype data;
    struct Node *next;
} List;

List *init()//没有头结点，初始化一个结点
{
    List *L = (List *)malloc(sizeof(List));
    L->next = NULL;
    L->data = 0;
    return L;
}

List *findkth(int k, List *L)//找到第k个结点并用指针指向
{
    List *p = L;
    int i = 1;
    while (p != NULL && i < k)//第k个结点在表内时，进行循环。若不在，p会作为NULL退出
    {
        p = p->next;
        ++i;
    }

    if ( i == k )//找到第k个
    {
        return p;
    }
    else//没找到
    {
        return NULL;
    }
}

List * insert(List *L, int i, datatype x)//在第i个结点之前插入结点，结点的data为x
{
    List *p, *s;

    if (i==1)//在第一个结点之前插入
    {
        s = (List *) malloc( sizeof(List) );
        s->data = x;
        s->next = L;
        return s;
    }

    p = findkth(i-1, L);//用p指向第i-1个结点
    s = (List *) malloc( sizeof(List) );
    s->data = x;
    s->next = p->next;
    p->next = s;
    return L;
}

void print_list(List *L)//按顺序打印链表的data
{
    List *p = L;
    while (NULL != p)//p==NULL时结束打印
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");//一般在打印完空行 对后面函数要求的打印比较方便
}

List* findvalue(List* l,int data)//找到表中第一个出现这个值的结点 并返回指向他的指针
{
    List* p = l;
    for(;p->data!=data&&p!=NULL;p=p->next);//找不到的话p为NULL
    return p;
}

void deletekafter(List*k)//删除指针k指向的结点的后一个结点 并将链表连续起来
{
    List* p = k->next;//用p存储删掉的结点地址，便于free
    k->next = k->next->next;
    free(p);
}

void deletedata(List*l,int mink,int maxk)//删除data值mink到maxk之间的所有元素
{
    if(mink>maxk)//mink大于maxk时
    {
        printf("error");
        return;
    }
    List* p=findvalue(l,mink);
    List* q=findvalue(l,maxk);
    if(p == q)//mink == maxk时
    {
        printf("none deleted data");
        return;
    }
    for(;p->next->data == mink;p=p->next);//若mink不止一个 让p指向最后一个
    if(p->next == q)//mink与maxk之间没有结点
    {
        printf("none deleted data");
        return;
    }
    for(;p->next!=q;)//p的后面紧接q是退出循环的条件
    {
        deletekafter(p);
    }
}

int main()
{
    List* l = init();
    insert(l,2,1);
    insert(l,3,2);
    insert(l,4,2);
    insert(l,5,3);
    insert(l,6,5);
    print_list(l);
    deletedata(l,2,5);
    printf("\n");
    print_list(l);
    return 0;
}
