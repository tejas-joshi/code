//====== CHECK WHETHER TWO LISTS ARE IDENTICAL...

/*
Logic :

Go parallel in both the lists.
Loop till you find the elements are same
When you find mismatch.. return false...

Refer code for more clarity....
It's too easy...

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
	while(nd)
	{
		cout << nd->data << " ";
		nd = nd->next;
	}
	cout << endl;
}

bool checkIdentical(node *nd1,node *nd2)
{
	while(nd1 && nd2)	// both must be non-null in order to compare data
	{
		if(nd1->data==nd2->data)	// data comparison of respective data
		{
			nd1 = nd1->next;
			nd2 = nd2->next;
		}	
		else                 // mismatch of data
			return false;
	}

	if(!nd1 && !nd2)   // break of loop... now both must be null inorder to identical...
		return true;
	else   
		return false;
}

int main()
{	
	node *head1 = NULL;
	insert(&head1,1);
	insert(&head1,2);
	insert(&head1,3);
	insert(&head1,4);
	insert(&head1,5);
	insert(&head1,6);

	node *head2 = NULL;
	insert(&head2,1);
	insert(&head2,2);
	insert(&head2,3);
	insert(&head2,4);
	insert(&head2,5);
	insert(&head2,6);

	cout << checkIdentical(head1,head2) << endl;	
	
	return 0;
}	
