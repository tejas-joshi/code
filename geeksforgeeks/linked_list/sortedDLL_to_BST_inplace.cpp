//====== SORTED DOUBLY LINKED LIST TO BALANCED BINARY SEARCH TREE INPLACE

/*

Examples:

Input:  Doubly Linked List 1 <--> 2 <--> 3
Output: A Balanced BST 
     2   
   /  \  
  1    3 


Input: Doubly Linked List 1 <--> 2 <-->3 <--> 4 <-->5 <--> 6 <--> 7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  4   7  

Logic :

Construct from leaves to root. The idea is to insert nodes in BST in the same order as the appear in Doubly Linked List,
so that the tree can be constructed in O(n) time complexity. We first count the number of nodes in the given Linked List.
Let the count be n. After counting nodes, we take left n/2 nodes and recursively construct the left subtree.
After left subtree is constructed, we assign middle node to root and link the left subtree with root.
Finally, we recursively construct the right subtree and link it with root.

While constructing the BST, we also keep moving the list head pointer to next so that we have the appropriate pointer in each recursive call.

TC : O(n)
SC : O(logn) // balanced BST

*/

#include<iostream>
using namespace std;

struct node_DLL
{
	int data;
	struct node_DLL *next,*prev;
};

typedef struct node_DLL nodeDLL;

nodeDLL *makeNodeDLL(int data)
{
	nodeDLL *temp = new nodeDLL;
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insert(nodeDLL **nd,int data)
{
	if(!(*nd))
		*nd = makeNodeDLL(data);
	else
	{
		nodeDLL *temp = *nd;
		while(temp->next)
			temp = temp->next;
		temp->next = makeNodeDLL(data);
		temp->next->prev = temp;
	}
}

int countNodes(nodeDLL *nd)
{
	int count=0;
	while(nd)
	{	
		count++;
		nd = nd->next;
	}
	return count;
} 

nodeDLL *LLtoBST(nodeDLL **head,int n)
{
	if(n<=0)
		return NULL;

	nodeDLL *leftChild = LLtoBST(head,n/2);	// recursive call for left with left half nodes

	nodeDLL *root = *head;	// setting root... Here *head was updated by upper left child calls and reach in the middle of the DLL
	(*head) = (*head)->next;	// go to next element in DLL

	root->prev = leftChild;				// setting the left child to left of root (prev)
	root->next = LLtoBST(head,n-n/2-1);	// recursive call for right child.. with right half-1 nodes.. that -1 is for the node assigned for the root in the code above...
		
	return root;		// returning the root of the current tree
}

nodeDLL *sortedDLLtoBST(nodeDLL **head)
{
	int n = countNodes(*head);	// count the nodes of DLL
	return LLtoBST(head,n);
}

void inorder(nodeDLL *nd)
{
	if(nd)
	{
		inorder(nd->prev);
		cout << nd->data << " ";
		inorder(nd->next);
	}
}

int main()
{
	nodeDLL *head = NULL;
	insert(&head,2);
	insert(&head,4);
	insert(&head,6);
	insert(&head,8);
	insert(&head,10);
	insert(&head,12);
	insert(&head,14);
	
	nodeDLL *root = sortedDLLtoBST(&head);
	inorder(root);	
	cout << endl;
	
	return 0;
}
