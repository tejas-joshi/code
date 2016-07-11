//======== MOVE LAST NODE THE FIRST IN THE LL

/**
Logic :
Maintain two pointers prev and last
prev holds second last node because we have to set next to it NULL.
After finding last set next to last to head
and next to prev to NULL
return last

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
	{
		node *temp = *nd;
		while(temp->next)
			temp = temp->next;
		temp->next = makeNode(data);
	}
}

node *moveLastToFirst(node **head)
{
	if(!(*head) || !((*head)->next))	// atleast two nodes should be there
		return *head;
	
	node *prev;		// holds the second last node of LL as we need to set the next to that node to NULL
	node *last = *head;	// holds the last node
	while(last->next)	
	{
		prev = last;
		last = last->next;
	}
	last->next = *head;	
	prev->next = NULL;
	return last;
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
	node *head =  NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);

	printLL(moveLastToFirst(&head));

	return 0;
}
