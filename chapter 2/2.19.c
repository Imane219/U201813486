/*��������ֵ������ʽ���У�ɾ����������ֵ����minkС��maxk��Ԫ��

����˵����lΪ���ף����ֵΪ0��û��ͷ���

*/

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct Node
{
    datatype data;
    struct Node *next;
} List;

List *init()//û��ͷ��㣬��ʼ��һ�����
{
    List *L = (List *)malloc(sizeof(List));
    L->next = NULL;
    L->data = 0;
    return L;
}

List *findkth(int k, List *L)//�ҵ���k����㲢��ָ��ָ��
{
    List *p = L;
    int i = 1;
    while (p != NULL && i < k)//��k������ڱ���ʱ������ѭ���������ڣ�p����ΪNULL�˳�
    {
        p = p->next;
        ++i;
    }

    if ( i == k )//�ҵ���k��
    {
        return p;
    }
    else//û�ҵ�
    {
        return NULL;
    }
}

List * insert(List *L, int i, datatype x)//�ڵ�i�����֮ǰ�����㣬����dataΪx
{
    List *p, *s;

    if (i==1)//�ڵ�һ�����֮ǰ����
    {
        s = (List *) malloc( sizeof(List) );
        s->data = x;
        s->next = L;
        return s;
    }

    p = findkth(i-1, L);//��pָ���i-1�����
    s = (List *) malloc( sizeof(List) );
    s->data = x;
    s->next = p->next;
    p->next = s;
    return L;
}

void print_list(List *L)//��˳���ӡ�����data
{
    List *p = L;
    while (NULL != p)//p==NULLʱ������ӡ
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");//һ���ڴ�ӡ����� �Ժ��溯��Ҫ��Ĵ�ӡ�ȽϷ���
}

List* findvalue(List* l,int data)//�ҵ����е�һ���������ֵ�Ľ�� ������ָ������ָ��
{
    List* p = l;
    for(;p->data!=data&&p!=NULL;p=p->next);//�Ҳ����Ļ�pΪNULL
    return p;
}

void deletekafter(List*k)//ɾ��ָ��kָ��Ľ��ĺ�һ����� ����������������
{
    List* p = k->next;//��p�洢ɾ���Ľ���ַ������free
    k->next = k->next->next;
    free(p);
}

void deletedata(List*l,int mink,int maxk)//ɾ��dataֵmink��maxk֮�������Ԫ��
{
    if(mink>maxk)//mink����maxkʱ
    {
        printf("error");
        return;
    }
    List* p=findvalue(l,mink);
    List* q=findvalue(l,maxk);
    if(p == q)//mink == maxkʱ
    {
        printf("none deleted data");
        return;
    }
    for(;p->next->data == mink;p=p->next);//��mink��ֹһ�� ��pָ�����һ��
    if(p->next == q)//mink��maxk֮��û�н��
    {
        printf("none deleted data");
        return;
    }
    for(;p->next!=q;)//p�ĺ������q���˳�ѭ��������
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
