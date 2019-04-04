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
    
    //head->data = NULL;//is this ok?

    return head;
}

pnode in(pnode head,datatype x,pnode rear)//入队，在末尾处添加结点； 
{
    pnode q = (pnode)malloc(sizeof(node));
    q->data = x;
    if(q == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    if(head->next == NULL)//如果创造的是头结点之后的首个节点，则让他指向自己 以创造循环链表
    {
        head->next = q;
        q->next = q;
        rear=rear->next;//不能rear++ 
    }
    else
    {
	    pnode tmp = rear->next;//不是首个节点，则进行结点添加，记得用tmp存rear->next
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
		printf("目前队列空");
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
