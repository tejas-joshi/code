//====== ROTATE LINKED LIST BY k NODES...

/*

Logic :

To rotate the linked list, we need to change next of kth node to NULL,
next of last node to previous head node, and finally change head to (k+1)th node.
So we need to get hold of three nodes: kth node, (k+1)th node and last node.

Traverse the list from beginning and stop at kth node.
Store pointer to kth node. We can get (k+1)th node using kthNode->next.
Keep traversing till end and store pointer to last node also. Finally, change pointers as stated above.

Assuming k<(length of the linked list)...

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

node *rotateK(node *head,int k)
{
	if(k==0)
		return head;

	// prev will point to kth node in the list
	// newHead will contain head to the rotated list...
	node *prev,*nd,*newHead;
	nd = head;

	while(k-- && nd)	// go to kth node of the list...
	{
		prev = nd;
		nd = nd->next;
	}

	prev->next = NULL;	// ending the list with the NULL of the next of prev (kth node)
	newHead = nd;		// setting new head
	
	while(nd->next)		// go to last node of the original list
		nd = nd->next;

	nd->next = head;	// setting the next of last node to the head of the list..
	
	return newHead;		
}

int main()
{	
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	insert(&head,6);

	int k;
	cin >> k;
	head = rotateK(head,k);	
	printLL(head);
	
	return 0;
}	
