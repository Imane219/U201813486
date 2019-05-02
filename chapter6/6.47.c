/*

	编写层序遍历的算法：队列 
	
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}node;

void creatbitree(node **proot,char *data)//创建一个二叉树  emmmmfailed
{
	if(*data==' ')*proot = NULL;
	else
	{
		if(!((*proot) = (node*)malloc(sizeof(node))))exit(1);
		(*proot)->data = *data;
		creatbitree((&(*proot)->lchild),data+1);
		creatbitree((&(*proot)->rchild),data+1);
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
	/*node *root = NULL;
	node **proot = &root;
	char data[15]={"019  3  4  "};
	creatbitree(proot,data);
	DLRtraverse(root);
	*/
	
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
	//DLRtraverse(root);
	
	node queue[5];
    int front = 0;
    int rear = 0;
    
    leveltraverse(root,&rear,&front,queue);
    
    return 0;
}
