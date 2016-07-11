//=== DELETE THE NODE FROM LINKED LIST

/*
Logic:
Maintain two pointers prev and curr that points to the previous and current nodes.
When data of current node is same as data we want to delete ..
Just point the next of prev to next of curr..
Take care about the corner cases.. (first node and last node)

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

void deleteNode(node **head,int d)
{
	node *nd = *head;
	if(nd)
	{
		node *prev = NULL;
		node *curr = nd;

		while(curr && curr->data!=d)	// reaching the node we want to delete.
		{
			prev = curr;
			curr = curr->next;
		}

		if(curr->data==d)
		{
			if(prev)	// prev is not NULL i.e. the node we want to delete is not first node
				prev->next = curr->next;
			else		// deletion of first node case... 
				*head = curr->next;	// CHANGING THE head 
			delete curr;	// deleting the memory of the node we want to delete.
		}
	}
}

int main()
{
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);

	deleteNode(&head,3);

	printLL(head);

	return 0;
}
