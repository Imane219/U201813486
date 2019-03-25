#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node
{
	datatype key;
	int num;
	struct node* next;
}person;

person* add()
{
	person* p = (person*)malloc(sizeof(person));
	if (p == NULL)
	{
		printf("no enough memory");
		exit(1);
	}
	printf("please input key:");
	scanf("%d", &p->key);
	p->next = NULL;

	return p;
}

person* creat(int *pn)
{
	person* head;
	head = add();
	head->num = 1;
	person* p = head;
	int i;
	printf("please input n:");
	scanf("%d", pn);
	for (i = 1; i < *pn; p = p->next)
	{
		p->next = add();
		p->next->num = i + 1;
		i++;
	}
	p->next = head;
	return head;
}

person* delete(person* head, int n, int m, int *key, int *num)
{

	int i = 1;
	person* p = head;
	if(m == 1)
	{
		m = m+n;
	}
	for (; i < m - 1; i++)p = p->next;
	person* q = p->next;
	p->next = p->next->next;
	*key = q->key;
	*num = q->num;
	free(q);
	return p->next;
}

int main()
{
	int n, m, key, num, i;

	person* head = creat(&n);
	person* p = head;

	printf("please input m:");
	scanf("%d", &m);
//	m %= n;

	int *sequence;
	sequence = (int *)malloc(n * sizeof(int));

	int len = n;

	for (i = 0; i < len; i++)
	{
		p = delete(p, n, m, &key, &num);
		m = key;
		n -= 1;
	//	m %= n;
		sequence[i] = num;
	}

	for (i = 0; i < len; i++)
		printf("%d ", sequence[i]);

	system("pause");
	return 0;
}
