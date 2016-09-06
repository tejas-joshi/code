// SWAP THE NODES OF LL IN PAIRWISE MANNER

/*
Logic :
Refer the code... Nice logic without recursion...
Try to implement using recursion..

TC : O(n)
SC : O(1)
*/

#include<iostream>
using namespace std;

struct node_n 
{
	int data;
	struct node_n *next;
};
typedef struct node_n node;

node *makeNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else
	{		
		node *temp = *nd;
		while(temp->next)
			temp = temp->next;
		temp->next = makeNode(data);
	}		
}

void printLL(node *nd)
{
	while(nd)
	{
		cout << nd->data << " ";
		nd = nd->next;
	}
	cout << endl;
}

node *reversePair(node *head)
{
	if(!head || !(head->next))	// at least two nodes is necessary
		return head;

	node *newHead = head->next;	// new head pointer to be returned
	node *nd = head;		
	node *nxt,*nxtnxt;	

	while(nd && nd->next)
	{
		nxt = nd->next;
		nxtnxt = nd->next->next;

		nxt->next = nd;

		// taking care about the next of nd
		if(nxtnxt && nxtnxt->next)	
			nd->next = nxtnxt->next;
		else		
			nd->next = nxtnxt;

		// setting first node of next swap
		nd = nxtnxt;
	}
	return newHead;
}

int main()
{	
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	
	printLL(reversePair(head));

	return 0;
}
