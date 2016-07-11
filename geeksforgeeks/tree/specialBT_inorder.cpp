//====== BUILD A SPECIAL BINARY TREE FROM GIVEN INORDER...

/*

Given Inorder Traversal of a Special Binary Tree in which key of every node is greater than keys in left and right children,
construct the Binary Tree and return root.

Examples:

Input: inorder[] = {5, 10, 40, 30, 28}
Output: root of following tree
         40
       /   \
      10     30
     /         \
    5          28 

Let the given array is {1, 5, 10, 40, 30, 15, 28, 20}.
The maximum element in given array must be root.
The elements on left side of the maximum element are in left subtree and elements on right side are in right subtree.

         40
      /       \  
   {1,5,10}   {30,15,28,20}

We recursively follow above step for left and right subtrees, and finally get the following tree.

          40
         /   \
       10     30
      /         \
     5          28
    /          /  \
   1         15    20

Logic:
1) Find index of the maximum element in array. The maximum element must be root of Binary Tree.
2) Create a new tree node ‘root’ with the data as the maximum value found in step 1.
3) Call buildTree for elements before the maximum element and make the built tree as left subtree of ‘root’.
4) Call buildTree for elements after the maximum element and make the built tree as right subtree of ‘root’.
5) return ‘root’.

TC: O(n^2)		// if the array is sorted then searching will take n^2 time.... (each search takes O(n) time)
SC: O(height)  

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

int searchMax(int *in, int start,int end)
{
	int maxInd=start,maxV=in[start];
	for(int i=start+1;i<=end;i++)
		if(in[i]>maxV)
		{
			maxInd = i;
			maxV = in[i];
		}
	return maxInd;
}

node *buildBT(int *in,int start,int end)
{
	if(start>end)
		return NULL;

	int maxInd = searchMax(in,start,end);	// finding the index of max element
	node *t = makeNode(in[maxInd]);			// creating the root...

	if(start==end)		// only one node..
		return t;

	t->left = buildBT(in,start,maxInd-1); // creating left subtree by updating the end index as maxInd-1
	t->right = buildBT(in,maxInd+1,end);  // creating right subtree by updating the start index as maxInd+1	

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
	int *in,n;
	cin >> n;
	in = new int[n];
	
	for(int i=0;i<n;i++)
		cin >> in[i];

	node *root = buildBT(in,0,n-1);
	inorder(root);
	cout << endl;
	
	return 0;
}
