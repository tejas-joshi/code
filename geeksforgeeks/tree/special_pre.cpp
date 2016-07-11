// Construct a special tree from given preorder traversal

/*

Given an array ‘pre[]‘ that represents Preorder traversal of a spacial binary tree where every node has either 0 or 2 children. 
One more array ‘preLN[]‘ is given which has only two possible values ‘L’ and ‘N’. 
The value ‘L’ in ‘preLN[]‘ indicates that the corresponding node in Binary Tree is a leaf node 
	and value ‘N’ indicates that the corresponding node is non-leaf node.

Example:

Input:  pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
Output: Root of following tree
          10
         /  \
        30   15
       /  \
      20   5

Logic is in the code... Refer it.. :)
The strategy is same as other problems of building BT from preorder/postorder

TC : O(n)
SC : O(height) // stack space

*/

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	node *left,*right;
} node;

node *createNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

node *preArrayToBT(int *pre,char *preLN,int *indPtr,int size)
{
	// we are passing pointer as alternative of static.. 
	int ind = *indPtr;
	
	// done with the tree so setting leaf nodes
	if(ind==size)
		return NULL;
	
	// creating node for current index
	node *nd = createNode(pre[ind]);	
	
	// increment index for further calls
	(*indPtr)++;
	
	// non-leaf so call for left and right subttrees	
	// else nd will be returned as leaf
	if(preLN[ind]=='N')
	{
		nd->left = preArrayToBT(pre,preLN,indPtr,size);
		nd->right = preArrayToBT(pre,preLN,indPtr,size);
	}
	return nd;	
}

int main()
{
	int *pre,n;
	char *preLN;
	cin >> n;
	
	pre = new int[n];
	preLN = new char[n];
	
	for(int i=0;i<n;i++)
		cin >> pre[i];
	for(int i=0;i<n;i++)
		cin >> preLN[i];

	int ind=0;
	inorder(preArrayToBT(pre,preLN,&ind,n));					
	
	return 0;	
}
