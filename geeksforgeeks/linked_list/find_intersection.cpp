//==== FIND THE INTERSECTION OF TWO LINKED LISTS

/**
Given two linked lists, find the intersection of both.
e.g
	1 -> 2 
	      \
	       3 -> 4	// Here next to 2 and next to 10 is 3... 
	      /
	    10

	  OUTPUT should be 3.. (intersection point)

Logic :
1) Get count of the nodes in first list, let count be len1.
2) Get count of the nodes in second list, let count be len2.
3) Get the difference of counts d = abs(len1 – len2)
4) Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
5) Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)

TC : O(len1+len2)
SC : O(1)

**/

#include<iostream>
#include<stdlib.h>
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

int lengthLL(node *nd)
{
	int len=0;
	while(nd)
	{
		len++;
		nd = nd->next;	
	}	
	return len;
}

int main()
{
	node *head1=NULL;
	node *head2=NULL;
	
	head1 = makeNode(1);
	head1->next = makeNode(2);

	head2 = makeNode(10);

	head2->next = head1->next->next = makeNode(3);
	head2->next->next = head1->next->next->next = makeNode(4);

	int len1=0,len2=0;

	node *temp,*temp2;

	len1 = lengthLL(head1);
	len2 = lengthLL(head2);	

	int diff = abs(len1-len2);

	// deciding which LL to traverse to make the same length.. temp for bigger LL and temp2 for other one...
	if(len1>len2)
	{
		temp = head1;
		temp2= head2;
	}
	else
	{
		temp = head2;
		temp2 = head1;
	}
	
	while(diff--)
		temp = temp->next;

	while(1)
	{
		if(temp==temp2) // matched the addresses .. Here I am assuming they are intersecting otherwise put condition for not null also... 
		{
			cout << temp->data << endl;
			break;
		}
		
		temp = temp->next;
		temp2 = temp2->next;
	}

	return 0;
}
