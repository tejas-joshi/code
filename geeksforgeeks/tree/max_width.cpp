//======  WIDTH OF THE TREE ... 

/*
Width of a tree is maximum of widths of all levels. 
Width of level is the number of nodes at that level..

Logic :

Use BFS.
Push NULL in queue to indicate the end of current level
Increment the count for not null nodes for current level and After finding next null update max if count>max.

Refer code for more clarity...

TC : O(n)
SC : O(n)

*/

#include<iostream>
#include<queue>
using namespace std;

struct node_n
{
	int data;
	struct node_n *left,*right;
};

typedef struct node_n node;

node *makeNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if((*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,7);
	insert(&root,1);
	insert(&root,9);
	insert(&root,4);
	insert(&root,10);
	insert(&root,12);

	queue<node *> Q;

	if(!root)
		return 0;

	Q.push(root);
	Q.push(NULL);	// end of first level.. level at root...

	int max=-1;
	int count=0;
	while(1)
	{
		node *temp = Q.front();
		if(temp)
		{
			count++;	// increment count for current level
			if(temp->left)
				Q.push(temp->left);
			if(temp->right)
				Q.push(temp->right);
		}
		else	// end of current level.. 
		{
			if(count>max)	// update max if required
				max = count;

			count=0;	// reset the count
			
			if(Q.size()==1)	// only NULL for current level that ended was in the queue .. so end of tree.. break
				break;
			else		// more elements are there in the queue so push NULL for indication of termination of current level
				Q.push(NULL);
		}
		Q.pop();
	}

	cout << max << endl;


	return 0;
}
