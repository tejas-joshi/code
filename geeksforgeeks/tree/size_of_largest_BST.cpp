//====== SIZE OF BIGGEST BST IN THE BINARY TREE

/*
e.g.
		5
       / \
      3   7
     / \   \
    1   4   0

  Size of biggest BST is 3...   1-3-4

Logic :
AWESOME LOGIC... AGAIN THE SAME STRATEGY WHEN MORE THAN ONE PARAMTER IS NEEDED TO SOLVE THE PROBLEM BUT YOU CAN ONLY RETURN ONE PARAMETER WHICH IS ANSWER..

Here you need 3 extra parameters to solve the problem except the return value.
1) Min value 2) max value 3) bool that indicate current tree is BST or not
Pass the min and max and address of the that bool in the function .. and return the answer

function will 
	return max(size found on left,size found on right)		if left/right/both are not BST / current node cannot build BST
	return 1 + size found on left + size found on right 		if left is bst  and right is bst and current element can be included...

Enjoyed coding of this problem.... WOOOHAAAA

TC : O(n)
SC : O(height) // stack space

*/

#include<iostream>
#include<limits.h>
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

int sizeMaxBST(node *nd,bool *b,int minV,int maxV)
{	
	if(!nd)
	{
		*b = true;
		return 0;
	}

	// isLeftBST - indicates if left subtree is bst or not
	// isRightBST - indicates if right subtree is bst or not
	// sLeft - size of biggest BST found on left
	// sRight - size of biggest BST found on right

	bool isLeftBST,isRightBST;
	int sLeft,sRight;
	
	sLeft = sizeMaxBST(nd->left,&isLeftBST,minV,nd->data);		// this call will update isLeftBST and return the size of BST if it is there
	sRight = sizeMaxBST(nd->right,&isRightBST,nd->data,maxV);	// 		"" 	 isRightBST			""
	
	*b = ((nd->data)>minV) && ((nd->data)<maxV) && isLeftBST && isRightBST;
	
	if(*b)	// add the size of left bst,right bst and current element... 
		return 1 + sLeft + sRight;
	else	// as bst cannot be built including this element so return max(sLeft,sRight)
		return max(sLeft,sRight);
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,4);
	insert(&root,7);
	//insert(&root,9);
	root->right->right = makeNode(0);
	
	bool b;
	cout << sizeMaxBST(root,&b,INT_MIN,INT_MAX) << endl;

	return 0;
}
