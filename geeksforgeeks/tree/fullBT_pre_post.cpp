//====== BUILD A FULL BINARY TREE FROM GIVEN PREORDER AND POST ORDER..

/*

Given two arrays that represent preorder and postorder traversals of a full binary tree, construct the binary tree.
A Full Binary Tree is a binary tree where every node has either 0 or 2 children

	e.g.
			  1
			/   \
		  2       3
		/  \     /  \
	   4    5   6    7
	 /  \  
	8    9 

Let us consider the two given arrays as pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
In pre[], the leftmost element is root of tree. Since the tree is full and array size is more than 1.

The value next to 1 in pre[], must be left child of root. So we know 1 is root and 2 is left child. 
(Above one is the reason why tree is possible to build by this combination...)

How to find the all nodes in left subtree? We know 2 is root of all nodes in left subtree.
All nodes before 2 in post[] must be in left subtree. Now we know 1 is root, elements {8, 9, 4, 5, 2} are in left subtree,
and the elements {6, 7, 3} are in right subtree.


                  1
                /   \
               /      \
     {8, 9, 4, 5, 2}     {6, 7, 3}

We recursively follow the above approach and get the following tree.

Logic :
Rest of the logic is in the comments

TC : O(n^2)	// searching is done linearly... worst case for n elements .. O(n^2).. found in the end..
SC : O(height)	// stack space

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
}

int searchPost(int *post, int start,int end,int key)
{
	for(int i=start;i<=end;i++)
		if(post[i]==key)
			return i;
}

node *buildBT(int *pre,int *post,int start,int end,int size)
{
	static int preInd=0;

	if(start>end || preInd>=size)
		return NULL;

	node *t = makeNode(pre[preInd]);			// creating the root...
	preInd++;

	if(start==end)		// only one node...
		return t;

	int ind = searchPost(post,start,end,pre[preInd]);	// finding the index in the post order array	

	t->left = buildBT(pre,post,start,ind,size); // creating left subtree by updating the end index as ind
	t->right = buildBT(pre,post,ind+1,end-1,size);  // creating right subtree by updating the start index as ind+1	

	return t;	// returning the root
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
	int *post,n,*pre;
	cin >> n;

	post = new int[n];
	pre = new int[n];
	
	for(int i=0;i<n;i++)
		cin >> pre[i];
	for(int i=0;i<n;i++)
		cin >> post[i];
		

	node *root = buildBT(pre,post,0,n-1,n);
	inorder(root);
	cout << endl;
	
	return 0;
}
