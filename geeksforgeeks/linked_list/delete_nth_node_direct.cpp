//====== Given only a pointer to a node to be deleted in a singly linked list, how do you delete it?

/*
Logic:
Just copy the data of next node to data of current node and 
set next of current node to the next of next of current.
Free the memory of next to the node to be deleted...
This soln. wont work of the node to be deleted is last node because we cant have the address of previous node.

TC : O(1)
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
	
	printLL(head);

	node *delNode = head->next; // deleting second node.. i.e. 2
	
	if(delNode->next)
	{
		node *temp;
		temp = delNode->next;
		delNode->data = temp->data;
		delNode->next = temp->next;
		delete temp;
	}
	
	printLL(head);

	return 0;
}
