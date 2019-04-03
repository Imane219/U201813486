#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}node,*pnode;

pnode init()//����ѭ�����е�ͷ���
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

void add(pnode p)//��ǰһ����������ӽ��,��ͷ�����ѭ��
{
    pnode q = (pnode)malloc(sizeof(node));
    if(q == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    if(p->next == NULL)//����������ͷ���֮����׸��ڵ㣬������ָ���Լ� �Դ���ѭ������
    {
        p->next = q;
        q->next = q;
    }
    pnode tmp = p->next;//�����׸��ڵ㣬����н����ӣ��ǵ���tmp��p->next
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
    for(int i = 0;i<7;i++)//����һ����7��Ԫ�ص�ѭ������
    {
        add(p);
        p = p->next;
    }


    return 0;
}
