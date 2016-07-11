//===== DELETE ALTERNATE NODES FROM LL

/*
Logic :
Refer the code.
Just think recursively but code it iteratively to save space.
i.e. the state after execution of current iteration SHOULD BE SAME AS the next state in the case of recursion. 

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

void deleteAlt(node **head)
{
	node *p = *head;
	while(p && p->next)
	{
		node *temp = p->next; // the node to be deleted.
		p->next = temp->next; 
		delete temp;
		p = p->next;	     // setting p for next pair
	}
}

int main()
{
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	//insert(&head,5);

	deleteAlt(&head);

	printLL(head);
	return 0;
}
