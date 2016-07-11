// FLATTEN THE LINKED LISTS

/*
Logic :

Given a linked list where every node represents a linked list and contains two pointers of its type:
(i) Pointer to next node in the main list (we call it ‘next’ pointer in below code)
(ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
All linked lists are sorted. See the following example

	5 - 7 - 8 - 30
	|
    10- 20
    |
    19- 22- 50
    |
    28- 35- 40- 45

Write a function flatten() to flatten the lists into a single linked list.
The flattened linked list should also be sorted.
For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.

Logic :
We use merge() to merge lists one by one.
We recursively merge() the current list with already flattened list.
The down pointer is used to link nodes of the flattened list.

If you know the merge sort well in deep. This will be just 1 minute play...
* Divide the list by down...
* Merge the lists by next

TC : O(mnlogn)   // where m=no. of nodes in each list.. n=no. of lists
SC : O(log n)

*/

#include<iostream>
using namespace std;

struct node_n 
{
	int data;
	struct node_n *next,*down;
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

node *mergeLL(node *a,node *b)	// MERGING THE LISTS 
{
	if(!a)
		return b;
	if(!b)
		return a;

	node *temp,*newHead=NULL,*nd=NULL;
	while(a && b)
	{
		if(a->data < b->data)
		{
			temp = a;
			a=a->next;
		}
		else
		{
			temp = b;
			b=b->next;
		}
		
		if(!newHead)
			newHead = nd = temp;
		else
		{
			nd->next = temp;
			nd = nd->next;
		}
	}

	if(!a)
		nd->next = b;
	else if(!b)
		nd->next = a;
	else
		nd->next = NULL;

	return newHead;
}

void splitLL(node *source,node **frontLL,node **backLL)	// SPLITTING THE LISTS BY down pointer
{
	if(!source || !source->down)
	{
		*frontLL = source;
		*backLL = NULL;
	}
	else
	{
		node *slow = source;
		node *fast = source->down;

		while(fast && fast->down)
		{		
			slow = slow->down;
			fast = fast->down->down;
		}

		*frontLL = source;
		*backLL = slow->down;
		slow->down = NULL;
	}	
}

node *flatten(node *hd)
{
	if(!hd || !hd->down)	// no list or single list
		return hd;

	node *a,*b;
	splitLL(hd,&a,&b);		// split the lists using down pointer
	return mergeLL(flatten(a),flatten(b));	// merge the flattened sublists a and b
}

int main()
{	
	node *head1 = NULL;
	insert(&head1,5);
	insert(&head1,7);
	insert(&head1,8);
	insert(&head1,30);

	node *head2 = NULL;
	insert(&head2,10);
	insert(&head2,20);

	node *head3 = NULL;
	insert(&head3,19);
	insert(&head3,22);
	insert(&head3,50);

	node *head4 = NULL;
	insert(&head4,28);
	insert(&head4,35);
	insert(&head4,40);
	insert(&head4,45);

	
	head1->down = head2;
	head2->down = head3;
	head3->down = head4;
	head4->down = NULL;

	node *headLL = 	flatten(head1);
	printLL(headLL);

	return 0;
}
