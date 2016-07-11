//== FIND THE HEIGHT OF THE BT ITERATIVELY....
// root is at height 1

/*
Logic :

Use BFS logic.
Push NULL to indicate the end of the level and increment the height.
When only NULL remains in the queue then you have height as the answer
	because no nodes would be there in the queue.
	
Refer code for more clarity.

TC : O(n)
SC : O(n)	// because at most (n/2) nodes (leaf level) can be pushed..
*/

#include<iostream>
#include<queue>
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

int heightItr(node *nd)
{
	if(!nd)
		return 0;
	
	queue<node *> Q;
	Q.push(nd);
	Q.push(NULL);	// this indicates the end of the level 1
	int height=0;
	
	while(Q.size()>1)
	{
		while(1)
		{
			node *temp = Q.front();
			if(temp)
			{
				if(temp->left)
					Q.push(temp->left);
				if(temp->right)
					Q.push(temp->right);
				Q.pop();
			}	
			else
			{
				Q.pop();	// popping the NULL for the previous level
				height++;	// increment the height
				Q.push(NULL);	// pushing the NULL for the current level
				break;
			}
		}
	}
	return height;
}

void insert(node **root,int data)
{
	if(!(*root))
	{
		*root = createNode(data);
		return;
	}
	
	node *temp = *root;
	while(1)
	{
		if(temp->data < data)
			if(temp->right)
				temp = temp->right;
			else
			{
				temp->right = createNode(data);
				break;
			}
		else
			if(temp->left)
				temp = temp->left;
			else
			{
				temp->left = createNode(data);
				break;
			}
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
	insert(&root,4);
	insert(&root,1);
	insert(&root,7);
	insert(&root,9);
	insert(&root,11);
	//inorder(root);			
	cout << heightItr(root) << endl;
	return 0;
}
