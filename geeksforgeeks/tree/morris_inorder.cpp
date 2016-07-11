//========= MORRIS TRAVERSAL... 

/*****
1. Initialize current as root 
2. While current is not NULL
   If current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as right child of the rightmost node in current's left subtree
      b) Go to this left child, i.e., current = current->left
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

void morrisTraversal(node *nd)
{
	node *pre;	
	node *curr = nd;
	
	while(curr)
	{
		if(!(curr->left))
		{
			cout << curr->data << " ";
			curr = curr->right;
		}
		else
		{
			pre = curr->left;
			while(pre->right && pre->right!=curr)
				pre = pre->right;
			
			if(!pre->right)	 // this case happens when the whole left tree is remaining to be printed 
			{
				pre->right = curr;
				curr = curr->left;
			}
			else   // this case happens when the whole left subtree has been traversed and printed... so we remove the pointers we set for the successor.. (revert the changes..)
			{
				pre->right  = NULL;
				cout << curr->data << " ";
				curr = curr->right;
			}	
		}		
	}
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = createNode(data);
	else if((*nd)->data<data)
		insert(&((*nd)->right),data);
	else
		insert(&((*nd)->left),data);
}

void inorder(node *nd)
{
	if(nd)
	{
		inorder(nd->left);
		cout << nd->data << " ";
		inorder(nd->right);
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

	//inorder(root);
	morrisTraversal(root);
	cout << endl;
	return 0;	
}
