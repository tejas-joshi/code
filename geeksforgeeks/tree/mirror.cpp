//===== MIRROR OF A BINARY TREE

/*********

CHECK BOTH THE LOGICS..
* First creates another tree which is mirror of current tree.
* Second converts the same tree to its mirror tree.

Recursively mirror left and right subtree and then swap.

LOGIC :
(1)  right = Mirror(left-subtree)
(2)  left = Mirror(left-subtree)

Checking can be done by printing inorder.
Mirror tree will print reverse of sequence than original tree.

TC : O(n)
SC : O(height of tree) (stack space)

*********/
 

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

node *mirror(node **nd)
{
	if(!(*nd))
		return NULL;

	node *t;
	t = makeNode((*nd)->data);	
	t->right = mirror(&(*nd)->left);
	t->left = mirror(&(*nd)->right);

	// if we are not allowed to create another tree then we have to follow bottom-up manner i.e. first of all we have to start mirroring from
	// leaf level then we have to swap on parent level.. in that case we dont have to return anything because we have to work on original tree...
	// so we call mirror for left and  then right (this function wont return anything) then swap the left and right

	return t;	
}

void mirror2(node **nd)
{
	if(!(*nd))
		return;
		
	mirror2(&((*nd)->left));
	mirror2(&((*nd)->right));
	
	node *temp = (*nd)->left;
	(*nd)->left = (*nd)->right;
	(*nd)->right = temp;
}


void inorder(node *nd)
{
	if(!nd)
		return;
	else
	{
		inorder(nd->left);
		cout << nd->data << " ";
		inorder(nd->right);
	}
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

	inorder(root1);
	cout << endl;
	inorder(mirror(&root1));
	cout << endl;
	return 0;
}

