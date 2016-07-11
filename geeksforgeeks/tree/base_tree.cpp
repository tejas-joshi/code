//====== BASE TREE STRUCTURE	

#include<iostream>
using namespace std;
struct node_n
{
	int data;
	struct node_n *left,*right;
};
typedef struct node_n node;

node *makeNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if( (*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}

int main()
{
	node *root=NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,4);
	insert(&root,7);
	insert(&root,6);

	
	return 0;
}
