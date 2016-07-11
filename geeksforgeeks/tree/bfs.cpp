//=== BREADTH FIRST TRAVERSAL

#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node *makeNode(int data)
{
	node *t = (node *)malloc(sizeof(node));
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);		
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,4);
	insert(&root,7);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);

	queue<node *> Q;

	Q.push(root);

	while(!Q.empty())
	{
		node *t = Q.front();
		Q.pop();
		if(t)	// handle the case when t is not null
		{
			cout << t->data << " "; 
			Q.push(t->left);
			Q.push(t->right);
		}	
	}

	return 0;
}
