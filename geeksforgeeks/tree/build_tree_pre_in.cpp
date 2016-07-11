//====== BUILD BINARY TREE FROM THE GIVEN INORDER AND PREORDER

/*
e.g.
Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

In a Preorder sequence, leftmost element is the root of the tree.
So we know ‘A’ is root for given sequences.
By searching ‘A’ in Inorder sequence, we can find out all elements on left side of ‘A’ are in left subtree and elements on right are in right subtree.

Logic:
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call.
2) Create a new tree node tNode with the data as picked element.
3) Find the picked element’s index in Inorder. Let the index be inIndex.
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
6) return tNode.

TC : O(n^2)		// searching an element is taking O(n) time... If the tree is skewed then searching time will be n+(n-1)+(n-2)+...+1
SC : O(height)
*/

#include<iostream>
using namespace std;
struct node_n
{
	char data;
	struct node_n *left,*right;
};
typedef struct node_n node;

node *makeNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
}

int search(char in[],int start,int end,char c)
{
	for(int i=start;i<=end;i++)
		if(in[i]==c)
			return i;
}

node *buildBT(char pre[],char in[],int start, int end)
{
	if(start>end)			// CORNER CASE...TAKE CARE...
		return NULL;

	static int preIndex=0;

	// making root for the tree
	node *t = makeNode(pre[preIndex]);
	preIndex++;			// REMEMBER THIS INCREMENT IS DONE BEFORE CHECKING THE CONDITION BELOW... 

	if(start==end)	// single node...... CORNER CASE... TAKE CARE...
		return t;
	
	int i = search(in,start,end,t->data);	// searching the char in inorder array

	t->left = buildBT(pre,in,start,i-1);	// start to i-1 will in the left subtree
	t->right = buildBT(pre,in,i+1,end);		// i+1 to end will be in right subtree

	return t;			// return the root
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
	char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
	int size = sizeof(in)/sizeof(in[0]);
	
	node *root = buildBT(pre,in,0,size-1);	
	inorder(root);
		
	return 0;
}
