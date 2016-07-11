//==== CHECK FOR THE CYCLE IN THE LL

/**
Logic :
Use the logic of finding the middle of the LL i.e. slow and fast pointer.
If they meet -> there is cycle.
else 	there isnt any cycle.

TC : O(n)
SC : O(1)
**/

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

bool checkCycle(node *nd)
{
	if(!nd)	// empty LL -> no cycle.
		return false;

	// same logic as finding middle element
	node *slow = nd;
	node *fast = nd;

	while(fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast)		// take care about where to place this condition... if it is above the updation of slow and fast.. then it will be always true on the first iteration itself.
			return true;
	}
	return false;
}

int main()
{	
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	
	//head->next = head;
	head->next->next->next->next = head->next;	// next of 4 is pointing to 2

	cout << checkCycle(head) << endl;

	return 0;
}
