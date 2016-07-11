//====== POPLULATE INORDER SUCCESSOR-PREDECESSOR FOR ALL THE NODES

/*
Logic :
Traverse the given tree in reverse inorder traversal and keep track of previously visited node.
When a node is being visited, assign previously visited node as next.

TC : O(n)
SC : O(height) // stack space
*/

#include<iostream>
using namespace std;
struct node_n
{
	int data;
	struct node_n *left,*right,*next;
};
typedef struct node_n node;

node *makeNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = temp->next = NULL ;
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

// sets the predecessor node to next
void setInorderPred(node *nd,node **pred)	// for predecessor.. inorder
{
	if(nd)
	{
		setInorderPred(nd->left,pred);

		nd->next = *pred;
		*pred = nd;

		setInorderPred(nd->right,pred);
	}	
}

// sets the successor node to next
void setInorderSucc(node *nd,node **succ)	// for successor... reverse inorder
{
	if(nd)
	{
		setInorderSucc(nd->right,succ);

		nd->next = *succ;
		*succ = nd;

		setInorderSucc(nd->left,succ);
	}	
}


void inorder(node *nd)
{
	if(nd)
	{	
		inorder(nd->left);
		if(nd->next) 	cout << nd->data << " " << nd->next->data << " " << endl;
		inorder(nd->right);
	}
}

int main()
{
	node *root=NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,4);
	insert(&root,7);
	insert(&root,6);

	cout << "inorder predecessors : " << endl;
	node *pred = NULL;
	setInorderPred(root,&pred);	
	inorder(root);

	cout << endl;

	cout << "inorder successors : " << endl;
	node *root2=NULL;
	insert(&root2,5);
	insert(&root2,3);
	insert(&root2,4);
	insert(&root2,7);
	insert(&root2,6);

	node *succ = NULL;	
	setInorderSucc(root2,&succ);	
	inorder(root2);
	
	return 0;
}
