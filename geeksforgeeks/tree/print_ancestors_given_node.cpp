//======= PRINT ALL THE ANCESTORS OF THE GIVEN NODE

/*
Given a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree.

For example, if the given tree is following Binary Tree and key is 7, then your function should print 4, 2 and 1.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7

Logic :
In the code...

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

/* If target is present in tree, then prints the ancestors
   and returns true, otherwise returns false. */
bool printAncestors(node *nd,int d)
{
	if(!nd)
		return false;
	if(nd->data==d)
		return true;

	/* If target is present in either left or right subtree of this node,
    then print this node because this node will be ancestor in any case */
	if(printAncestors(nd->left,d) || printAncestors(nd->right,d))
	{
		cout << nd->data << " ";
		return true;
	}
	else
		return false;
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
	printAncestors(root,d);
	
	cout << endl;
	
	return 0;
}
