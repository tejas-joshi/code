#include<iostream>
#include<stack>
using namespace std;

typedef struct node_n
{
	int data;
	struct node_n *left,*right;
} node;

node *createNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;	
}

void insert(node **nd,int data)
{
	while(*nd)
	{
		if((*nd)->data > data)
			nd = &((*nd)->left);
		else
			nd = &((*nd)->right);
	}		
	*nd = createNode(data);
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

// PREORDER WITH 1 STACK ITERATIVE - EASY
void preorder_stack(node *nd)
{
	stack<node *> S;
	while(1)
	{
		while(nd)
		{
			cout << nd->data << " ";	// printing root
			S.push(nd);
			nd = nd->left;		// go to left
		}	
		
		if(S.empty())	// check stack before popping from it
			break;
		
		nd = S.top();
		S.pop();
		nd = nd->right;		// go to right	
	}
	cout << endl;
}

// INORDER WITH 1 STACK ITERATIVE -- EASY
void inorder_stack(node *nd)
{
	stack<node *> S;
	while(1)
	{
		while(nd)			
		{
			S.push(nd);
			nd = nd->left;	// go to left
		}
		
		if(S.empty())	// checking the stack before popping
			break;
			
		nd = S.top();
		cout << nd->data << " ";	// print nd data
		S.pop();	
		
		nd = nd->right;		// go to right
	}	
	cout << endl;
}

// POSTORDER WITH 1 STACK ITERATIVE - EASY
void postorder_stack(node *root)
{
	if(!root)
		return;
		
	stack<node *> S;
	
	do
	{
		while(root)	
		{
			if(root->right)				// pushing the right
				S.push(root->right);
			S.push(root);				// pushing itself
			root = root->left;			// go to left
		}
		
		root = S.top();		// root will be top of the stack 
		S.pop();			// pop 
		
		if(!S.empty() && root->right==S.top()) // checking the top of the stack is right child of root
		{
			S.pop();				// pop ----> (i.e. right child will be popped)
			S.push(root);			// push the root
			root = root->right;		// make root as the right child
		}
		else
		{
			cout << root->data << " ";	// printing the root data.. as we dont need to go to right child
			root = NULL;				// set root to NULL to process from top the stack in the next iteration
		}
		
	} while(!S.empty());
	cout << endl;
}
int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,4);
	insert(&root,8);
	insert(&root,6);
	insert(&root,9);
	insert(&root,10);
	
	preorder_stack(root);
	inorder_stack(root);
	postorder_stack(root);
	
//	inorder(root);	
	return 0;
}
