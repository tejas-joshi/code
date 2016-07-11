//====== REVERSE ALTERNATE k NODES IN THE LINKED LIST...

/*
Logic :

First understand the problem of reverse every k nodes...
Then you will surely get idea about this problem...
Refer code for more clarity... Comments also..

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

node *reverseK(node *nd,int k,bool doRev)
{
	if(!nd)
		return NULL;
		
	node *current,*prev,*next;
	current = nd;
	prev = NULL;
	int count=0;

	/* reverse first k nodes of the linked list */
	while(current && count<k)
	{
		next = current->next;

		if(doRev)	/* Reverse the nodes only if doRev is true */
			current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* 3) If doRev is true, then node is the kth node.
          So attach rest of the list after node.
       4) After attaching, return the new head */
	if(doRev)
	{
		nd->next = reverseK(current,k,!doRev);
		return prev;
	}
	else   /* If doRev is not true, then attach rest of the list after prev. So attach rest of the list after prev */  
	{
		prev->next = reverseK(current,k,!doRev);
		return nd;
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
	insert(&head,5);
	insert(&head,6);

	int k;
	cin >> k;
	head = reverseK(head,k,true);	
	printLL(head);
	
	return 0;
}	
