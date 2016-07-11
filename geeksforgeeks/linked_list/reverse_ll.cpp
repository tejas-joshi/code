//======= REVERSE THE LINKED LIST

/**
Given a linked list, reverse it.
This can be done recursively as well as iteratively.

Logic:
Take 3 node pointers prev,curr and temp

prev points to previous node.
curr points to current node.
temp points to next to current node.

	we iterate through all the nodes until curr become NULL
		temp = curr->next
		curr->next = prev	// change the direction
		
		// these two steps are for going one step further.
		prev = curr	
		curr = temp
	
	in the end prev will point to first node (last node in original LL).
	so head = prev

TC : O(n)
SC : O(1)

**/

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
		insert(&((*nd)->next),data);
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

int main()
{
	node *head=NULL;

	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);

	printLL(head);

	node *prev = NULL;
	node *curr = head;
	node *next;

	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}	
	head = prev;		// dont forget this...

	printLL(head);

	return 0;
}
