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

void insertLL(node **nd,int d)
{
	if(!(*nd))
		*nd = makeNode(d);
	else
	{
		node** current = nd;
		node *new_node = makeNode(d);
		
		// finding the correct place to insert the node in the list
		while (*current && (*current)->data < d)
		{
			cout << "in loop " << (*current)->data << " ";
			current = &((*current)->next);
		}

		cout << (*current)->data << endl;

		new_node->next = *current;
		*current = new_node;
		/*
		node *n = makeNode(d);
		node *temp = *nd;
		while(temp && (temp->data < d))
			temp = temp->next;

		n->next = temp;
		temp = n;
		*/
	}
}

void printLL(node *nd)
{
	while(nd)
	{
		cout << nd->data << " ";
		nd=nd->next;
	}
	cout << endl;
}

int main()
{
	node *head = NULL;

	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,5);
	
	insertLL(&head,4);

	printLL(head);
	
	return 0;
}
