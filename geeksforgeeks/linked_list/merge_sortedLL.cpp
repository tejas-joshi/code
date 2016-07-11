//======= MERGE TWO SORTED LL 

/*
Return the head pointer of resultant LL

Logic :
Simple logic of merging... 
refer the code very carefully...

Code is given for inplace merging and also for new merged list...

TC : O(m+n)
SC : O(1)	// in case of inplace otherwise m+n

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

node *mergeLL_new(node *head1,node *head2)
{
	node *head= NULL;	// head pointer of resultant list
	node *newPtr=NULL;	// newPtr holds the address of last node of resultant list
	node *a = head1;
	node *b = head2;

	while(1)
	{
		if(!a)		// first list became empty
		{
			while(b)	// copy remaining elements in b to resultant list
			{
				if(!head)
				{
					newPtr = makeNode(b->data);
					head = newPtr;
				}
				else
				{
					newPtr->next = makeNode(b->data);
					newPtr = newPtr->next;
				}
				b = b->next;				
			}
			break;
		}
		else if(!b)	// second list became empty
		{
			while(a)	// copy remaining elements of a into resultant list
			{
				if(!head)
				{
					newPtr = makeNode(a->data);
					head = newPtr;
				}
				else
				{
					newPtr->next = makeNode(a->data);
					newPtr = newPtr->next;
				}
				a = a->next;
			}
			break;
		}

		if(a->data < b->data)
		{
			if(!head)
			{
				newPtr = makeNode(a->data);
				head = newPtr;
			}
			else
			{
				newPtr->next = makeNode(a->data);
				newPtr = newPtr->next;
			}
			a = a->next;
		}
		else
		{
			if(!head)
			{
				newPtr = makeNode(b->data);
				head = newPtr;
			}
			else
			{
				newPtr->next = makeNode(b->data);
				newPtr = newPtr->next;
			}
			b = b->next;
		}
	}
	return head;
}

node *mergeLL_inplace(node **head1, node **head2)
{
	// lastPtr holds the address of last node of resultant list
	node *lastPtr = NULL;

	node *a = *head1; // holds the address of first node of first list
	node *b = *head2; // holds the address of first node of second list
	node *head=NULL;	// head pointer of resultant list

	while(1)
	{
		if(!a)
		{
			if(!lastPtr)
				head = b;
			else
				lastPtr->next = b;
			break;
		}
		else if(!b)
		{
			if(!lastPtr)
				head = a;
			else
				lastPtr->next = a;
			break;
		}

		if(a->data < b->data)
		{
			if(!lastPtr)
			{	
				lastPtr=a;
				head = a;
			}
			else
			{
				lastPtr->next = a;
				lastPtr = lastPtr->next;
			}
			a=a->next;
		}
		else
		{
			if(!lastPtr)
			{
				lastPtr = b;
				head = b;
			}
			else
			{
				lastPtr->next = b;
				lastPtr = lastPtr->next;
			}
			b = b->next;
		}
	}
	return head;
}

int main()
{
	node *head1 = NULL;
	insert(&head1,1);
	insert(&head1,3);
	insert(&head1,5);

	node *head2=NULL;
	insert(&head2,2);
//	insert(&head2,4);
//	insert(&head2,6);

	printLL(mergeLL_new(head1,head2));
	return 0;
}
