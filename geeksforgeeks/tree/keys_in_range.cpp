//====== PRINT THE ELEMENTS FROM BST IN GIVEN RANGE

/*

Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree.
Print all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2
and x is a key of given BST. Print all the keys in increasing order.

Logic :

1) If value of root’s key is greater than k1, then recursively call in left subtree.
2) If value of root’s key is in range, then print the root’s key.
3) If value of root’s key is smaller than k2, then recursively call in right subtree.

Modification of inorder traversal...

TC : O(n)
SC : O(height) // stack space

*/

#include<iostream>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node *makeNode (int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
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

void printInRange(node *nd,int start,int end)
{
	if(nd)
	{
		if(nd->data>=start)
			printInRange(nd->left,start,end);

		if(nd->data>=start && nd->data<=end)
			cout << nd->data << " ";

		if(nd->data<=end)
			printInRange(nd->right,start,end);
	}
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,7);
	insert(&root,9);
	insert(&root,4);

	int start,end;
	cin >> start >> end;
	printInRange(root,start,end);
	cout << endl;
	
	return 0;
}
