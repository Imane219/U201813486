#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}node,*pnode;

pnode init()//创建循环队列的头结点
{
    pnode head = (pnode)malloc(sizeof(node));
    if(head == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    head->next = NULL;
    head->data = NULL;//is this ok?

    return head;
}

void add(pnode p)//往前一个结点后面添加结点,除头结点外循环
{
    pnode q = (pnode)malloc(sizeof(node));
    if(q == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    if(p->next == NULL)//如果创造的是头结点之后的首个节点，则让他指向自己 以创造循环链表
    {
        p->next = q;
        q->next = q;
    }
    pnode tmp = p->next;//不是首个节点，则进行结点添加，记得用tmp存p->next
    p->next = q;
    q->next = tmp;

}

pnode addelem(pnode head)
{
    pnode p = head;
    if(!p->next->data)
    printf("please input data:");
    scanf("%d",&p->data);
}

int main()
{
    pnode head = init();
    pnode p = head;
    pnode rear;
    for(int i = 0;i<7;i++)//创建一个存7个元素的循环队列
    {
        add(p);
        p = p->next;
    }


    return 0;
}
