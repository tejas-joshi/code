//====== FIND THE MIDDLE NODE OF THE LINKED LIST

/*
Logic :
Take two pointers slow and fast.
slow jumps one node at a time
fast jumps two nodes at a time
When fast reaches end of the LL, slow will point to middle of the LL.
Take care about the corner cases.. ( one/two nodes in LL.)

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

// middle node in the case of odd lenght LL
// left side node in the case of even length LL
int middleNode(node *nd)
{
	if(!nd)	// empty LL
		return -1;

	node *slow = nd;
	node *fast = nd;

	while(fast->next && fast->next->next) // at least 3 nodes in LL
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

int main()
{
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);

	cout << middleNode(head) << endl;

	return 0;
}
