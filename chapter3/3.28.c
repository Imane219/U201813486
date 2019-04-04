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
    
    //head->data = NULL;//is this ok?

    return head;
}

pnode in(pnode head,datatype x,pnode rear)//��ӣ���ĩβ����ӽ�㣻 
{
    pnode q = (pnode)malloc(sizeof(node));
    q->data = x;
    if(q == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    if(head->next == NULL)//����������ͷ���֮����׸��ڵ㣬������ָ���Լ� �Դ���ѭ������
    {
        head->next = q;
        q->next = q;
        rear=rear->next;//����rear++ 
    }
    else
    {
	    pnode tmp = rear->next;//�����׸��ڵ㣬����н����ӣ��ǵ���tmp��rear->next
	    rear->next = q;
	    q->next = tmp;
	    rear=rear->next;
	}
    return rear;
}

void out(pnode head,pnode rear)
{
	if(head->next!=rear)
	{
		rear->next = head->next->next;
		pnode tmp = head->next;
		head->next = head->next->next;
		free(tmp);
	}
	else
	{
		rear = head;
		free(head->next);
		head->next = NULL;
		printf("Ŀǰ���п�");
	}
	
}

int main()
{
    pnode head = init();
    pnode rear = head;
    rear = in(head,1,rear);
    rear = in(head,2,rear);
    printf("%d\n",head->next->data);
    printf("%d\n",rear->data);
    out(head,rear);
    printf("%d",rear->data);
    out(head,rear);
    
    return 0;
}
