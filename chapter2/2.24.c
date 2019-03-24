/*������ֵ�����ĵ�������ԭ�ռ�ϲ���һ��ֵ�ݼ��ĵ�����

�㷨���£���b��˳�����a�У��پ͵�����

*/



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

void inverse(Node* head)//�͵�����
{
    Node* p = head->next->next;
    Node *q = head ->next,*tmp;
    for(;p;)
    {
        tmp = p->next;
        p->next = head->next;
        head->next = p;
        p=tmp;
    }
    q->next = NULL;
}

int main()
{
    Node* heada = creata();
    Node* headb = creatb();

    Node* p = heada,*q = headb->next,*tmp;
    for(;q&&p->next;)
    {
        tmp = q->next;
        if(q->data<=p->next->data)
        {
            tmp = q->next;
            q->next = p->next;
            p->next = q;
            q=tmp;
        }
        else
        {
            p=p->next;
        }
    }
    for(;q;p=p->next)
    {
        tmp = q->next;
        q->next = p->next;
        p->next = q;
        q=tmp;
    }

    print_list(heada);
    inverse(heada);
    print_list(heada);

    return 0;
}
