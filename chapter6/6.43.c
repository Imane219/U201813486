/*

  �õݹ��㷨�����������е��������� �������б����������£���visit()��Ҳ����printf���ɽ���������� 

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}node;

void DLRshift(node * root) //�����򽻻� 
{
	if(root)
	{
		node * temp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = temp;
		DLRshift(root->lchild);
		DLRshift(root->rchild);
	}
	return;
}

void DLRtraverse(node* root)//������� 
{
	if(root)
	{
		printf("%3d",root->data);
		DLRtraverse(root->lchild);
		DLRtraverse(root->rchild);
	}
	//return; ��дreturnҲ���Է�����һ�����õ� 
}

int main()
{
	node *root = (node *)malloc(5*sizeof(node));
	int i;
	for(i=0;i<5;i++)
	{
		root[i].lchild = NULL;
		root[i].rchild = NULL;
	}

	root->data = 0;
	root->lchild = root+1;
	root->rchild = root+4;
	root[1].data = 1;
	root[2].data = 9;
	root[3].data = 3;
	root[4].data = 4;
	
	root[1].lchild = root+2;
	root[1].rchild = root+3;
	
	DLRshift(root);
	DLRtraverse(root);
	
	return 0;
}
