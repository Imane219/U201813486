#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct
{
 int a[N];
 int top;
}stack;

stack tran;//����ȫ��ջ
int a[N]={0};//����һ���������ڴ��ԭ��˳��
int b[N];//����һ���������ڴ������ĳ�ջ�Ļ�
int len;//���ڴ�Ż𳵵�����

void init(stack *p)
{
 p->top=0;
}

int is_empty(stack *p)
{
 if(p->top==0)
  return 1;
 else
  return 0;
}

int push(stack *p,int x)
{
 if(p->top>=N)
 {
  printf("˳��ջ������\n");
  return 0;
 }

 p->a[p->top+1]=x;//��ջa[1]��ʼ�� 
 p->top++;
 return 1;
}

int pop(stack *p)
{
 if(p->top<=0)
 {
  printf(" ˳��ջΪ�գ�\n");
  exit(1);
 }
 return p->a[p->top--];
}

void print()//���b,������֮����г���� 
{
 int i;
 for(i=0;i<len;i++)
 {
  printf("%d  ",b[i]);
 }
 printf("\n");
}

void arrange(int k,int m)//����ԭʼ�����еĵ�k��Ԫ�أ�m������ջ��Ӧ���ڵ�ǰ�������ĵ�seq_pos��λ��
{
	int pop_num;
	if(k<len)//����Ч��Χ����ջ  ������ջ��Ԫ�أ�1������ջ��2��ջ
	{
	 push(&tran,a[k]);//��ջ
	 arrange(k+1,m);//ѡ��1 ��һ�л���ջ
	 pop(&tran);//������ջǰ����� �Ա�ѡ��2 ��ջ
	}
	 
	if(!is_empty(&tran))//ջ���л𳵳�ջ  ���ڳ�ջ��Ԫ�أ� 1������ջ��2��ջ
	{
	 pop_num=pop(&tran); 
	 b[m]=pop_num;  // ����b[]�У�׼�����
	 m++;     
	 arrange(k,m);   //������ǰ������ջǰ����ǰ���л𳵲�û��ջ�����Է��ص�ǰ��������ջ
	 push(&tran,pop_num);//���س�ջǰ�����  �Ա�ѡ�� 2 
	}
	 
	if(k>=len&&is_empty(&tran))//�����һ�л���ջ�������л��ѳ�ջ   һ������������
	{
	 print();
	}
}

void main()
{
	int i;
	init(&tran);
	printf("������𳵵�������");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
	 a[i]=i+1;
	}
	arrange(0,0);
}


