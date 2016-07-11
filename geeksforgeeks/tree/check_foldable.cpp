//====== CHECK WHETHER TREE IS FOLDABLE OR NOT....

/*
Given a tree, check whether it is foldable or not...

Here (a) and (b) are foldable.. but not (c) and (d)... 
i.e. The structure left and right subtree of root should be mirror of each other...

(a)
	       10
	     /    \
	    7      15
	     \    /
	     9  11
b)
        10
       /  \
      7    15
     /      \
    9       11

(c)
       10
      /  \
     7   15
    /    /
   5   11

d)
        10
       /   \
      7     15
    /  \    /
   9   10  12

Logic :
If root is null then it is foldable...
else
	if left and right are null
		return true..
	else if left and right are not null
		return func(left of left,right of right) && (left of right,right of left)
	else
		return false
Refer code for more understanding... It's easy logic...

TC : O(n)
SC : O(n)  // stack space

Think for iterative solution...
===============================

*/

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

bool isFoldable(node *nd1,node *nd2)
{
	if(!nd1 && !nd2)
		return true;
	else if(nd1 && nd2)
		return isFoldable(nd1->left,nd2->right) && isFoldable(nd1->right,nd2->left);
	else
		return false;
}

int main()
{
	node *root=NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,4);
	insert(&root,7);
	insert(&root,6);

	if(!root)
		cout << 1 << endl;
	else
		cout << isFoldable(root->left,root->right) << endl;
	
	return 0;
}
