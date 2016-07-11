//====== FIND THE SIZE OF LARGEST INDEPENDENT SET IN THE TREE

/*
  
  		5
       / \
      3   9
     /   / \
    1	6   10 
	     \
	     12

Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. 
A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.

For this tree.. ans is 4.. (1,5,6,10)

Logic : THE STRATEGY YOU HAVE LEARNT IN THE DIAMETER PROBLEM...

Find size of LIS for current node ..including and excluding..
* You can achieve this by getting the same values for left and right subtrees.
* 
* You have implemented this type of logic in DirectI online test.. To check the max sum for the nodes which are not connected by the edge.
* 
* Comments are here in the code to explain if you didnt get.
* 
*/

#include<iostream>
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

// excl will have the size of LIS excluding current node
// incl will have the size of LIS including current node
void LIS(node *nd,int *excl,int *incl)
{
	if(!nd)		
	{
		*excl = *incl = 0;		// node is null so.. both excl and incl would be 0.
		return;
	}	
	
	int leftIncl,leftExcl;		// for the left subtree
	int rightIncl,rightExcl;	// for the right subtree
	
	LIS(nd->left,&leftExcl,&leftIncl);		// call for left subtree
	LIS(nd->right,&rightExcl,&rightIncl);	// call for right subtree
	
	*incl = 1 + leftExcl + rightExcl;		// include current node.. so we cant include children nodes.. so leftExcl and rightExcl
	
	// exclude current node.. so we can take max in the left subtree + max in right subtree
	*excl = max(leftIncl,leftExcl) + max(rightIncl,rightExcl);
}

int LISWrapper(node *root)
{
	int excl,incl;
	LIS(root,&excl,&incl);
	// here excl will have size of LIS excluding root node
	// and incl will have size of LIIS including root node

	return max(incl,excl);	// returning max of both
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,7);
	insert(&root,9);
	insert(&root,10);
	insert(&root,6);
	insert(&root,4);

	cout << LISWrapper(root) << endl;


	return 0;
}	
