/*就地逆置实现
先创好一个链表而不是initialize+insert（在2.21updat）
带头结点
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

Node * creat_link()//生成一个十个结点的单链表
{
    int i;
    Node *q;//在for之外创造q便于最后跳出for使q = NULL
    Node * head = (Node *)malloc(sizeof(Node));//创造头结点
    if(head == NULL)
    {
        printf("no enough memory");
        exit(1);
    }
    head->next = NULL;//将头结点置空以便循环内判断赋值
    for(i=0;i<10;i++)
    {
        Node * p = (Node *)malloc(sizeof(Node));//创造结点
        if(p == NULL)
        {
            printf("no enough memory");
            exit(1);
        }
        scanf("%d",&p->data);//给结点的数据域赋值
        //getchar();
        if(head->next == NULL)//如果head == NULL，即当前创造的是第一个结点
        {
            head->next = p;//head指向第一个结点
            q = p;//q指向第一个结点便于后续取用
        }
        else//创造的不是第一个结点
        {
            q->next = p;//上一个结点指向新结点
            q = p;//q指向这个节点
        }
    }
    q->next = NULL;//尾结点next为NULL
    return head;
}

void inverse(Node* head)//就地逆置
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
    for(;p->next!=NULL;p = p->next)//不能p++
    {
        printf("%3d",p->data);
    }
    printf("%3d",p->data);
}
