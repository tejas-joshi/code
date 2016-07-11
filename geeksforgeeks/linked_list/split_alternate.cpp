//===== DIVIDE THE LL INTO TWO LLs OF ALTERNATE NODES

/*
Logic :
Refer the code.. 
Take head pointer and other pointer to maintain last node for each list
Maintain one bool variable to decide to which list the current node should be inserted.
At the end, set NULL to the last node of each list..

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

int main()
{
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);

	node *head1=NULL,*head2=NULL; // head pointers for both the lists
	node *nd1,*nd2;			// pointers to maintain the last node of each list
	node *nd = head;		// for loop thourgh original list
	bool odd=true;		// for making alternate sequence

	while(nd)
	{
		if(odd)
		{
			if(!head1)
				head1 = nd1 = nd;
			else
			{
				nd1->next = nd;
				nd1 = nd1->next;
			}	
		}
		else
		{
			if(!head2)
				head2 = nd2 = nd;
			else
			{
				nd2->next = nd;
				nd2 = nd2->next;
			}
		}
		nd = nd->next;
		odd = !odd;
	}

	if(nd1)
		nd1->next = NULL;
	if(nd2)
		nd2->next = NULL;
	
	printLL(head1);
	printLL(head2);

	return 0;
}
