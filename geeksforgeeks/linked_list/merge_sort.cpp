//====== MERGE SORT IN SINGLY LINKED LIST

/*
Logic :

Let head be the first node of the linked list to be sorted and headRef be the pointer to head. 
* Note that we need a reference to head in MergeSort() as the below implementation changes next links 
* to sort the linked lists (not data at the nodes), 
* so head node has to be changed if the data at original head is not the smallest value in linked list.

MergeSort(headRef)
1) If head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b); // a and b are two halves 
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);


The whole logic is explained in the code...

TC : O(nlogn)
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
		nd= nd->next;
	}
	cout << endl;
}

void splitList(node *source,node **frontLL,node **backLL)
{
	if(!source || !source->next)	// 0 or 1 nodes in the list..
	{
		*frontLL = source;
		*backLL = NULL;
	}
	else
	{
		// now we will partition the list by method of reaching middle of the list..
		node *slow = source;
		node *fast = source->next;

		while(fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		*frontLL = source;		// head of first list will be the source..
		*backLL = slow->next;	// head of second list will be middle of the list...
		slow->next = NULL;		// ending the first list with NULL.. because it still points to the other nodes of the original list..
	}
}

node *mergeLL(node *a,node *b)	// merge list a and b which will return the head pointer to new merged list	
{
	// BASE CONDITIONS
	if(!a)		// first list is empty ..return second
		return b;
	if(!b)		// second list is empty.. return first
		return a;

	node *newHead=NULL,*nd = NULL,*temp;
	// nd will point to the last node of the merged list in the loop...
	
	while(a && b)	// both have elements
	{
		if(a->data < b->data)	// comparison
		{
			temp = a;
			a = a->next;
		}
		else
		{
			temp = b;
			b = b->next;
		}

		if(!nd)	// first node in the new list..so initialize head and nd both...
			newHead = nd = temp;
		else       // point the next of nd to the target...
		{
			nd->next = temp;
			nd = nd->next;
		}
	}

	if(!a)	// a is empty so rest of elements of b will be attached to the new list...	b list has NULL in the end...
		nd->next = b;
	else if(!b)		// b is empty so rest of nodes of a will be attached to the new list... a list has NULL in the end...
		nd->next = a;
	else     // both a and b are empty... so set NULL in the end of the new list...
		nd->next = NULL;

	return newHead;		// return the head of the new list....
}

void mergeSort(node **head)		// passing the ref. to the head because it may be changed if head is not the smallest element...
{
	if(!(*head) || !((*head)->next))	// 0 or 1 node in the LL
		return;

	node *a,*b;

	splitList(*head,&a,&b);		// split the list into 2 sublists... a and b will be the head of both the lists respectively...

	mergeSort(&a);		// recursively for list a
	mergeSort(&b);		// recursively for list b

	*head = mergeLL(a,b);	// merge a and b lists
}

int main()
{	
	node *head = NULL;
	insert(&head,10);
	insert(&head,52);
	insert(&head,32);
	insert(&head,12);
	insert(&head,5);
	insert(&head,60);

	mergeSort(&head);
	printLL(head);
	
	return 0;
}	
