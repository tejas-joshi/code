//========= MORRIS TRAVERSAL FOR PREORDER

/*
First refer morris traversal for inorder if you haven't checked it out...
This is the same logic used for inorder but the order of printing is changed... 
Refer the code for more clarity...
*/

#include<iostream>
using namespace std;

typedef struct node_n
{
	int data;
	struct node_n *left,*right;
} node;

node *createNode(int data)
{
	node *temp = new node;
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = createNode(data);
	else if((*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);	
}

void morrisPreorder(node *nd)
{
	node *pre;
	while(nd)
	{
		if(!nd->left)
		{
			cout << nd->data << " ";
			nd = nd->right;
		}
		else
		{
			pre = nd->left;
			while(pre->right && pre->right!=nd)
				pre = pre->right;

			if(pre->right==nd)	// this case happens when the whole left subtree of nd has been printed
			{
				pre->right  = NULL;
				nd = nd->right;
			}
			else	// this case happens when the whole left subtree is remaining to be printed... so print the root..
			{	// setting the inorder predecessor and go to left...
				cout << nd->data << " ";
				pre->right = nd;
				nd = nd->left;
			}
		}
	}	
}

void preorder(node *nd)
{
	if(nd)
	{
		cout << nd->data << " ";
		preorder(nd->left);
		preorder(nd->right);
	}
	
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,4);
	insert(&root,7);
	insert(&root,6);
	morrisPreorder(root);
	cout << endl;
	return 0;	
}
