/*
	判断所给二叉树是不是完全二叉树 
*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}node;

int treedepth(node *root)//求树的深度 
{
	int ldepth,rdepth,max;
	if(root)
	{
		ldepth = treedepth(root->lchild);
		rdepth = treedepth(root->rchild);
		max = ldepth>rdepth?ldepth:rdepth;
		return max+1;
	}
	else
		return 0;
}

void pop(node *q,int *front,int *rear)
{
	if(*front == *rear)printf("the queue is empty");
	else
	{
		printf("%3d",q[*front].data);
		(*front)++;
	}
	return;
}

void push(node *q,int *front,int *rear,node *root)
{
	if(!root)return;
	q[*rear] = *root;
	(*rear)++;
}

void leveltraverse(node *root,int *rear,int *front,node *q)
{
	push(q,front,rear,root);
	for(;*rear!=*front;)
	{
		push(q,front,rear,q[*front].lchild);
		push(q,front,rear,q[*front].rchild);
		pop(q,front,rear);
	}
	
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
	

	return 0;
}
