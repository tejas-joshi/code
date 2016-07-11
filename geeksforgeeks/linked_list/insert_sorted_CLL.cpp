//====== INSERT AN ELEMENT IN SORTED CIRCULAR LINKED LIST...

/*
Logic :

Here we have to handle 3 cases...	CHECK THE CODE ALSO...
1) Insertion at first node... element is smallest...
2) Insertion at the end
3) Insertion in between the list...

In the first we have to change the head also.. Take care about this...
While printing and traversing, take care about the head pointer because it's not like LL where you will find NULL in the end...
	Keep checking with head node to end the list..

Refer code for understanding...

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
	node *head = nd;
	while(nd)
	{
		cout << nd->data << " ";
		nd = nd->next;
		if(head==nd)
			break;
	}
	cout << endl;
}

void insertCLL(node **head,int d)
{
	if(!(*head))
	{
		*head = makeNode(d);
		(*head)->next = *head;
	}
	else
	{
		node *t = *head;	// t will point to the node where d is just less than t->data
		node *prev = NULL;	// prev will point to previous node to t..
		
		node *temp = makeNode(d);
		while(t->data < d)	// checking for the place to insert
		{
			prev=t;
			t=t->next;

			if(t==(*head))	// need to insert in the end... (d will be in the last)
				break;
		}

		if(t==(*head))	// insertion at first or last
		{
			if(prev==NULL)		// insertion at first place
			{
				temp->next = t;

				while(t->next!=(*head))
					t = t->next;
				t->next = temp;
				*head = temp;
			}
			else        // insertion at the end because prev is not empty ..prev points to the last node of the CLL...
			{
				prev->next = temp;
				temp->next = *head;
			}
		}
		else    // insertion in between the list
		{
			prev->next = temp;
			temp->next = t;
		}
	}
}

int main()
{	
	node *head = NULL;
	head = makeNode(4);
	head->next = makeNode(10);
	head->next->next = makeNode(14);
	head->next->next->next = makeNode(20);
	head->next->next->next->next = head;

	int d;
	cin >> d;
	insertCLL(&head,d);	
	printLL(head);
	
	return 0;
}	
