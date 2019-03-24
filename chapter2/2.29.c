#include <stdio.h>
#include <stdlib.h>


typedef int datatype;

typedef struct node
{
    datatype data;
    struct node * next;
}Node;

Node* initialize()//��һ��ͷ���
{
    Node* l = (Node*)malloc(sizeof(Node));
    if(l == NULL)
    {
        printf("no memory");
        exit(1);
    }
    l->next = NULL;//important!
    return l;
}

Node* findkth(Node*l,int k)//�ҵ���k����㣬����ָ������ָ��
{
    int i;
    Node* p = l;
    for(i=0;i<k&&p;p=p->next,i++);
    if(i==k&&p)
    {
        return p;
    }
    else
        printf("cannot find kth");
        exit(1);
}

void insert(Node*l,int k,datatype data)//��k֮�����
{
    Node* p = findkth(l,k);
    Node* q = (Node*)malloc(sizeof(Node));
    if(q == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    q->data = data;
    q->next = p->next;
    p->next = q;
}

void print_list(Node* l)//��˳���ӡ�����е�data
{
    Node* p=l->next;
    for(;p;p=p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");
}

Node* creata()//����a����
{
    Node* heada = initialize();
    insert(heada,0,1);
    insert(heada,1,3);
    insert(heada,2,7);
    insert(heada,3,7);
    insert(heada,4,9);
    insert(heada,5,17);
    return heada;
}

Node* creatb()//����b����
{
    Node* headb = initialize();
    insert(headb,0,0);
    insert(headb,1,2);
    insert(headb,2,3);
    insert(headb,3,8);
    insert(headb,4,9);
    insert(headb,5,18);
    insert(headb,6,19);
    return headb;
}

Node* creatc()//����c����
{
    Node* headc = initialize();
    insert(headc,0,1);
    insert(headc,1,3);
    insert(headc,2,7);
    insert(headc,3,7);
    insert(headc,4,9);
    insert(headc,5,17);
    return headc;
}

void delete(Node*p)//ɾ��p֮���һ�����
{
    Node* tmp = p->next;
    p->next = p->next->next;
    free(tmp);
}
int main()
{

    Node* heada = creata(),*p = heada;
    Node* headb = creatb(),*q = headb;
    Node* headc = creatc(),*r = headc;
    Node* tag1,*tag2;
    print_list(heada);
    for(;p&&q&&r;p=p->next)
    {
        for(;q->next->data<p->next->data&&q;q=q->next);
        if(q->next->data == p->next->data&&q)
        {
            tag1 = p;
        }
        else if(q->next->data > p->next->data&&q)
        {
            tag1 = NULL;
        }
        for(;r->next->data<p->next->data&&r;r=r->next);
        if(r->next->data == p->next->data&&r)
        {
            tag2 = p;
        }
        else if(r->next->data > p->next->data&&r)
        {
            tag2 = NULL;
        }
        if(tag1 == tag2&&tag1)
        {
            delete(tag1);
        }
    }
    print_list(heada);

    return 0;
}
