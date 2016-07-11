//===== GET Nth NODE FROM LAST.

/*
Logic :
Take two pointers main and temp. 
Both points to head initially.
Move temp to n nodes from head.
Now move both pointers until temp will be NULL.
When temp reaches NULL, main will point to nth node from last in LL.

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

int nth_last(node *nd,int from_last)
{	
	node *p = nd;
	while(p && from_last--) // move p to n nodes ahead..
		p = p->next;

	if(from_last)	// from last is more than length of LL
		return -1;

	while(p)	// move both until p will be NULL
	{
		p = p->next;
		nd = nd->next;
	}
	return nd->data;
}

int main()
{
	node *head= NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);

	cout << nth_last(head,6) << endl;

	return 0;
}
