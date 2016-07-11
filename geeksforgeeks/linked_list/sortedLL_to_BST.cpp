//====== SORTED LINKED LIST TO BALANCED BINARY SEARCH TREE

/*
Input:  Linked List 1->2->3
Output: A Balanced BST 
     2   
   /  \  
  1    3 


Input: Linked List 1->2->3->4->5->6->7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  4   7

Logic :
Construct from leaves to root. The idea is to insert nodes in BST in the same order as the appear in Linked List,
so that the tree can be constructed in O(n) time complexity.
We first count the number of nodes in the given Linked List. Let the count be n.
After counting nodes, we take left n/2 nodes and recursively construct the left subtree.
After left subtree is constructed, we allocate memory for root and link the left subtree with root.
Finally, we recursively construct the right subtree and link it with root.

While constructing the BST, we also keep moving the list head pointer to next so that we have the appropriate pointer in each recursive call.

TC : O(n)
SC : O(logn) // balanced BST
*/

#include<iostream>
using namespace std;

struct node_LL
{
	int data;
	struct node_LL *next;
};

typedef struct node_LL nodeLL;

struct node_BT
{
	int data;
	struct node_BT *left,*right;
};

typedef struct node_BT nodeBT;


nodeLL *makeNodeLL(int data)
{
	nodeLL *temp = new nodeLL;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

nodeBT *makeNodeBT(int data)
{
	nodeBT *temp = new nodeBT;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(nodeLL **nd,int data)
{
	if(!(*nd))
		*nd = makeNodeLL(data);
	else
	{
		nodeLL *temp = *nd;
		while(temp->next)
			temp = temp->next;
		temp->next = makeNodeLL(data);
	}
}

int countNodes(nodeLL *nd)
{
	int count=0;
	while(nd)
	{	
		count++;
		nd = nd->next;
	}
	return count;
} 

nodeBT *LLtoBST(nodeLL **head,int n)
{
	if(n<=0)
		return NULL;

	nodeBT *leftChild = LLtoBST(head,n/2);	// recursive call for left with left half nodes

	nodeBT *root = makeNodeBT((*head)->data);	// creating root... Here *head was updated by upper left child calls and reach in the middle of the LL
	(*head) = (*head)->next;	// go to next element in LL

	root->left = leftChild;				// setting the left child to left of root
	root->right = LLtoBST(head,n-n/2-1);	// recursive call for right child.. with right half-1 nodes.. that -1 is for the node created for the root in the code above...
		
	return root;		// returning the root of the current tree
}

nodeBT *sortedLLtoBST(nodeLL **head)
{
	int n = countNodes(*head);	// count the nodes of LL
	return LLtoBST(head,n);
}

void inorder(nodeBT *nd)
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
	nodeLL *head = NULL;
	insert(&head,2);
	insert(&head,4);
	insert(&head,6);
	insert(&head,8);
	insert(&head,10);
	insert(&head,12);
	insert(&head,14);
	
	nodeBT *root = sortedLLtoBST(&head);
	inorder(root);	
	cout << endl;
	
	return 0;
}
