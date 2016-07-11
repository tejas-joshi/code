//====== CREATE BALANCED BST FROM SORTED ARRAY...

/*
Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

Input:  Array {1, 2, 3}
Output: A Balanced BST
     2
   /  \
  1    3

Logic :

1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.

TC : O(n)
SC : O(logn)	// stack space will be logn because of balanced BST...
*/

#include<iostream>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node *makeNode(int data)
{
	node *t = new node;
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

node *array2BST(int *A,int start,int end)
{
	if(start>end)
		return NULL;

	int mid = (start+end)/2;	// middle element will be the root of current tree... index in the array will be mid

	node *t = makeNode(A[mid]);	// creating the root

	if(start==end)	// only one element in the range so one node.. return it
		return t;

	t->left = array2BST(A,start,mid-1);		// recursively call for creating left subtree in first half of the array.. i.e. start TO mid-1
	t->right = array2BST(A,mid+1,end);		// recursively call for creating right subtree in second half of the array.. i.e. mid+1 to end

	return t;		// return the root
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
	int *A,n;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	node *root = array2BST(A,0,n-1);
	inorder(root);
	cout << endl;
	return 0;	
}
