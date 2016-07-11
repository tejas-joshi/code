///============== PRINT THE REVERSE OF LINKED LIST...

/**
Given a LL, print the reverse..

Look at the problem.. Only print the reverse of LL..
Now you only have 3 seconds to think about the soln.
If you dont get it, DUB MAR....

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

void printReverse(node *nd)
{
	if(nd)	
	{
		printReverse(nd->next);
		cout << nd->data << " ";
	}
}

int main()
{
	node *head = NULL;

	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);

	printReverse(head);
	cout << endl;

	return 0;
}

