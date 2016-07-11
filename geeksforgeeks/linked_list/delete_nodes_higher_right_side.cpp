//====== DELETE THE NODES WHICH HAS HIGHER ELEMENTS ON RIGHT SIDE...

/*
Logic :

1. Reverse the list.
2. Traverse the reversed list. Keep max till now.
   If next node < max, then delete the next node, otherwise max = next node.
3. Reverse the list again to retain the original order. 

TC : O(n)

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

node *reverse(node *nd)
{
	if(!nd || !(nd->next))
		return nd;

	node *prev,*curr,*next;
	prev=NULL;
	curr = nd;

	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;	// When curr reaches NULL, prev will point to the head of the reversed LL.
}

node *deleteRightSide(node *nd)
{
	node *revHead = reverse(nd);	// reversing the original list

	node *curr = revHead;	
	node *temp;
	node *maxND = curr;		// maxND points to the node contains the max. element till now..
	
	while(curr && curr->next)		// here you cannot design algo by taking single node e.g. curr ..because we are deleting nodes
									// we have to connect prev to the next of the deleting node.
	{
		if(maxND->data > curr->next->data)		// delete the current node as element is lesser than max
		{
			temp = curr->next;
			curr->next = temp->next;
			delete temp;			
		}
		else          // go to next node and update the maxND as we found new max
		{
			curr = curr->next;
			maxND = curr;
		}
	}
	return reverse(revHead);	// reversing the reversed and updated list..which is answer...
}


int main()
{	
	node *head = NULL;
	insert(&head,12);
	insert(&head,15);
	insert(&head,10);
	insert(&head,11);
	insert(&head,5);
	insert(&head,6);
	insert(&head,2);
	insert(&head,3);

	printLL(head);
	head = deleteRightSide(head);	
	printLL(head);
	
	return 0;
}	
