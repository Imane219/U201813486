#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct Node
{
    datatype data;
    struct Node * next;
}Node;

Node * initialize()
{
    Node * l = (Node *)malloc(sizeof(Node));
    l->next = NULL;
    return l;
}

Node* findkth(Node* l,int i)
{
    int j;
    for(j=0;j!=i;l = l->next)j++;
    return l;
}

void insert(Node*l,int i,datatype data)
{
    Node* p = findkth(l,i);
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = data;
    q->next = p->next;
    p->next = q;
}

void reverse(Node* l)//有头结点的就地逆置
{
    Node* p,*q,*m;//不能*p,q,m
    m = l->next;
    p = l->next->next;
    for(;q;)
    {
      q = p->next;
      p->next = l->next;
      l->next = p;
      p = q;
    }
    m->next = NULL;
}

Node* inverse(Node *L)//无头结点的就地逆置
{
    Node *p = L;
    Node *q = NULL;
    Node *head = NULL;

    while (p)
    {
        q = p->next;
        p->next = head;
        head = p;
        p = q;
    }

    return head;
}

void print(Node* l)
{
    for(l=l->next;l;l=l->next)
    {
        printf("%3d",l->data);
    }
}
int main()
{
    Node* l = initialize();
    insert(l,0,3);
    insert(l,1,2);
    insert(l,2,1);
    print(l);
    reverse(l);
    printf("\n");
    print(l);
    return 0;
}
