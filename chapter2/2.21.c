/*�͵�����ʵ��
�ȴ���һ�����������initialize+insert����2.21updat��
��ͷ���
*/


#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct Node
{
    datatype data;
    struct Node * next;
}Node;

Node * creat_link();
void inverse(Node* head);
void print_linkdata(Node* head);

int main()
{
    Node *head = creat_link();
    print_linkdata(head);
    inverse(head);
    printf("\n");
    print_linkdata(head);
    return 0;
}

Node * creat_link()//����һ��ʮ�����ĵ�����
{
    int i;
    Node *q;//��for֮�ⴴ��q�����������forʹq = NULL
    Node * head = (Node *)malloc(sizeof(Node));//����ͷ���
    if(head == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    head->next = NULL;//��ͷ����ÿ��Ա�ѭ�����жϸ�ֵ
    for(i=0;i<10;i++)
    {
        Node * p = (Node *)malloc(sizeof(Node));//������
        if(p == NULL)
        {
            printf("no enough memory");
            exit(1);
        }
        scanf("%d",&p->data);//������������ֵ
        //getchar();
        if(head->next == NULL)//���head == NULL������ǰ������ǵ�һ�����
        {
            head->next = p;//headָ���һ�����
            q = p;//qָ���һ�������ں���ȡ��
        }
        else//����Ĳ��ǵ�һ�����
        {
            q->next = p;//��һ�����ָ���½��
            q = p;//qָ������ڵ�
        }
    }
    q->next = NULL;//β���nextΪNULL
    return head;
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


void print_linkdata(Node* head)
{
    Node * p = head->next;
    for(;p->next!=NULL;p = p->next)//����p++
    {
        printf("%3d",p->data);
    }
    printf("%3d",p->data);
}
