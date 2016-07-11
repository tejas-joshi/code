//=== REMOVE DUPLICATES FROM THE SORTED LL

/*
Logic :
Refer the code. It's easy nothing tricky...
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
	temp->next =  NULL;
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
	insert(&head,1);
	insert(&head,3);
	insert(&head,5);
	insert(&head,5);
	
	node *nd = head;

	int d;
	while(nd)
	{
		int d = nd->data;
		while(nd->next && nd->next->data == d)
		{
			node *temp = nd->next;
			nd->next = temp->next;
			delete temp;
		}
		nd = nd->next;
	}

	printLL(head);

	return 0;
}
