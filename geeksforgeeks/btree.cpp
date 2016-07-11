#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
};

typedef struct node Node;

Node *root = NULL;

Node *makeNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* insert(Node* nd,int data)
{
	if(nd==NULL)
	{
		nd = makeNode(data);
		return nd;
	}
	else if(nd->data<data)
		return insert(nd->right,data);
	else
		return insert(nd->left,data);
}

bool search(Node *nd,int data)
{
	if(nd==NULL)
		return false;
	else if(nd->data<data)
		return search(nd->right,data);
	else
		return search(nd->left,data);
}

void inorder(Node* nd)
{
	if(nd==NULL)
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
	insert(root,5);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,9);

	inorder(root);
	
	cout << search(root,0) << endl;
	cout << search(root,9) << endl;
	
	return 0;
}
