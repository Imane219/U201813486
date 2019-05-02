/*

  �õݹ��㷨��Ҷ�ӽڵ�����ݣ�ͨ�����ֵݹ����+Ҷ�ӽڵ������ж���ȷ��Ҷ�ӽڵ�data��� 


*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}node;

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

void LDRtraverse(node *root)//������� 
{
	if(root)
	{
		LDRtraverse(root->lchild);
		printf("%3d",root->data);
		LDRtraverse(root->rchild);
	}
	return;
}

void LRDtraverse(node *root)//������� 
{
	if(root)
	{
		LRDtraverse(root->lchild);
		LRDtraverse(root->rchild);
		printf("%3d",root->data);
	}
	return;
} 

void DLRtraverseleaf(node* root)
{
	if(root)
	{
		if(root->lchild == NULL&&root->rchild == NULL)
			printf("%3d",root->data);
		DLRtraverseleaf(root->lchild);
		DLRtraverseleaf(root->rchild);
	}
	return;
}

void LRDtraverseleaf(node *root)//������� 
{
	if(root)
	{
		LRDtraverseleaf(root->lchild);
		LRDtraverseleaf(root->rchild);
		if(!root->lchild&&!root->rchild)
			printf("%3d",root->data);
	}
	return;
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
	
	DLRtraverse(root);
	LDRtraverse(root);
	LRDtraverse(root);
	printf("\n");
	DLRtraverseleaf(root);
	printf("\n");
	LRDtraverseleaf(root);
	
	return 0;	
}
