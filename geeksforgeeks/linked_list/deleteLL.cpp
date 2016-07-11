//======== DELETE THE LINKED LIST

/*
Logic :
Take a pointer 'nd' that points to the first node of the LL.
Then head will point to next to head.
Now delete nd
Loop this till head becomes NULL
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

	node *nd;
	while(head)
	{
		nd = head;
		head = head->next;
		delete nd;
	}

	printLL(head);

	return 0;
}
