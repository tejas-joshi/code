// CHECK IF TWO TREES ARE IDENTICAL OR NOT...

/***********

Two trees are identical when they have same data and arrangement of data is also same.

To identify if two trees are identical, we need to traverse both trees simultaneously,
and while traversing we need to compare data and children of the trees.

LOGIC :

if (check both are null)
	return true;
else if (check both are not null)
	return (same data) && isIdentical(left of both) && isIdentical(right of both)
else
    return false;

TC : O( min(|V1|,|V2|) )
SC : O(height of tree) ( considering stack space )
	
************/

#include<iostream>
#include<stdlib.h>
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
	if((*nd)==NULL)
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

bool isIdentical(node *nd1,node *nd2)
{
	if(!nd1 && !nd2)
		return true;
	else if(nd1 && nd2)
		return ((nd1->data)==(nd2->data)) && isIdentical(nd1->left,nd2->left) && isIdentical(nd1->right,nd2->right);
	else
		return false;
}

int main()
{
	node *root1=NULL;
	insert(&root1,5);	
	insert(&root1,4);	
	insert(&root1,7);	
	insert(&root1,1);	
	insert(&root1,6);	
	insert(&root1,9);

	node *root2=NULL;
	insert(&root2,5);	
	insert(&root2,4);	
	insert(&root2,7);	
	insert(&root2,1);	
	insert(&root2,6);	
	insert(&root2,9);

	cout << isIdentical(root1,root2) << endl;	

	return 0;
}
