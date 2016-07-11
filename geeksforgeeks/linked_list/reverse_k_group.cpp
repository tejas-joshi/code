//====== REVERSE THE NODES IN THE GROUP OF k..

/*
Logic :

Algorithm: reverseK(head, k)
1) Reverse the first sub-list of size k.
	While reversing keep track of the next node and previous node.
	Let the pointer to the next node be next and pointer to the previous node be prev.
2) head->next = reverseK(next, k) // Recursively call for rest of the list and link the two sub-lists 
3) return prev // prev becomes the new head of the list (see the diagrams of iterative method of this post) 

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

node *reverseK(node *nd,int k)
{
	node *current,*prev,*next;
	current = nd;
	prev = NULL;
	next = NULL;
	int count=0;

	 /*reverse first k nodes of the linked list */
	while(current && count<k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* next is now a pointer to (k+1)th node
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
	if(next)
		nd->next = reverseK(next,k);

	/* prev is new head of the input list */
	return prev;
}

void printLL(node *nd)
{
	while(nd)
	{
		cout << nd->data << " ";
		nd= nd->next;
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
	insert(&head,6);

	int k;
	cin >> k;
	head = reverseK(head,k);	
	printLL(head);
	
	return 0;
}	
