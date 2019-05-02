/*

  用递归算法交换二叉树中的左右子树 ：在三中遍历的条件下，将visit()，也就是printf换成交换的命令即可 

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}node;

void DLRshift(node * root) //按先序交换 
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

void DLRtraverse(node* root)//先序遍历 
{
	if(root)
	{
		printf("%3d",root->data);
		DLRtraverse(root->lchild);
		DLRtraverse(root->rchild);
	}
	//return; 不写return也可以返回上一级调用的 
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
