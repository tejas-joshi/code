// UNION AND INTERSECTION OF TWO LINKED LISTS

/*
Logic :
- Sort both the list using merge sort
- Use the logic of union for both sorted lists
- Use the logic of intersection for both the sorted lists

Explanation for sorting is explained in the separate problem that itself for sorting..
For union and intersection, I dont need to explain anything...
Just read the code once...

You have only 1 minute to complete this problem... :)

TC : O(mlogm + nlogn)
SC : O(logm + logn)	// for sorting
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

node *mergeLL(node *a,node *b)
{
	if(!a)
		return b;
	if(!b)
		return a;

	node *nd = NULL, *newHead = NULL,*temp;
	while(a && b)
	{
		if(a->data < b->data)
		{
			temp = a;
			a = a->next;
		}
		else
		{
			temp = b;
			b = b->next;
		}

		if(!newHead)
			newHead = nd = temp;
		else
		{
			nd->next = temp;
			nd = nd->next;
		}
	}

	if(!a)
		nd->next = b;
	else if(!b)
		nd->next = a;
	else
		nd->next = NULL;

	return newHead;
}

void splitList(node *source,node **frontLL,node **backLL)
{
	if(!source || !source->next)
	{
		*frontLL = source;
		*backLL = NULL;
	}
	else
	{
		node *slow = source;
		node *fast = source->next;

		while(fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		*frontLL = source;
		*backLL = slow->next;
		slow->next = NULL;
	}
}

void mergeSort(node **head)
{
	if(!(*head) || !((*head)->next))
		return;

	node *a,*b;

	splitList(*head,&a,&b);

	mergeSort(&a);
	mergeSort(&b);

	*head = mergeLL(a,b);
}

void printUnion(node *a, node *b)
{
	while(a && b)
	{
		if(a->data == b->data)
		{
			cout << a->data << " ";
			a = a->next;
			b = b->next;
		}
		else if(a->data < b->data)
		{
			cout << a->data << " ";
			a = a->next;	
		}
		else
		{
			cout << b->data << " ";
			b = b->next;
		}
	}

	if(!a)
	{
		while(b)
		{
			cout << b->data << " ";
			b=b->next;
		}
	}

	if(!b)
	{
		while(a)
		{
			cout << a->data << " ";
			a=a->next;
		}
	}
	cout << endl;
}

void printIntersection(node *a,node *b)
{
	while(a && b)
	{
		if(a->data == b->data)
		{
			cout << a->data << " ";
			a=a->next;
			b=b->next;
		}
		else if(a->data < b->data)
			a=a->next;
		else
			b=b->next;
	}
	cout << endl;
}

int main()
{	
	node *head1 = NULL;
	insert(&head1,2);
	insert(&head1,1);
	insert(&head1,5);
	insert(&head1,4);
	insert(&head1,3);

	node *head2 = NULL;
	insert(&head2,7);
	insert(&head2,2);
	insert(&head2,3);
	insert(&head2,1);
	insert(&head2,8);

	mergeSort(&head1);
	mergeSort(&head2);

	printUnion(head1,head2);
	printIntersection(head1,head2);
		
//	printLL(head1);
//	printLL(head2);

	return 0;
}
