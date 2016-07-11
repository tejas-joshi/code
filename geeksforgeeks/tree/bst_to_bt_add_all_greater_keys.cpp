//======= Convert a BST to a Binary Tree such that sum of all greater keys is added to every key

/*
Examples:

Input: Root of following BST
						  5
		                /   \
		               2     13

Output: The given BST is converted to following Binary Tree
                18
               /   \
             20     13
		   
Solution: Do reverse Inoorder traversal. Keep track of the sum of nodes visited so far. 
Let this sum be sum. For every node currently being visited, first add the key of this node to sum, i.e. sum = sum + node->key. 
Then change the key of current node to sum, i.e., node->key = sum.
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
	node  *temp = new node;
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = createNode(data);
	else if(((*nd)->data)<data)
		insert(&((*nd)->right),data);
	else
		insert(&((*nd)->left),data);
}

void changeTree(node *nd)
{
	
}

void reverseInorder(node *nd,int &sum)
{
	if(nd)
	{
		reverseInorder(nd->right,sum);

		sum = sum + nd->data;
		nd->data = sum;

		reverseInorder(nd->left,sum);
	}
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
	int sum=0;
	reverseInorder(root,sum);
	inorder(root);
	return 0;
}
