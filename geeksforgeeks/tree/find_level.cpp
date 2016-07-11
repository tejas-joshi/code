//======== GET THE LEVEL OF AN ELEMENT OF THE TREE

/*
 * 
 * Check the logic which is implemented here... It is recursive...
 * 
 * 
 * Iterative method is using BFS.. and Increment the count while inserting the current level elements...
 * and print the level when you find the element while inserting...
 *  
 * TC will always be O(n)
 * Recursive SC : O(height)
 * Iterative SC : O(n/2)   // max elements in the leaf level is n/2
 *
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

int getLevel(node *nd,int d)
{
	if(!nd)
		return 0;
	else if(nd->data==d)	// found data on current level
		return 1;	// return 1 to the parent 
	else 
	{
		// finding on left
		int ansLeft = getLevel(nd->left,d);
		if(ansLeft) 	// found on left
			return 1 + ansLeft;	// go up with level+1
		
		// if not found then right will be computed ... to avoid other calls after finding the answer..
		int ansRight = getLevel(nd->right,d);
		if(ansRight)	// found on right
			return 1 + ansRight;	// go up with level+1
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

	int d;
	cin >> d;
	cout << getLevel(root,d) << endl;
	return 0;
}
