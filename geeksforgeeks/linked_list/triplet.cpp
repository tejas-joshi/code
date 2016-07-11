// FIND THE TRIPLET FROM THE 3 LINKED LISTS

/*

3 unsorted LLs are given, find the triplet from them such that sum will be k...

Logic :

Explanation for sorting is there in separate post of problem of merge sort..Please refer that first for sorting...

Here we have 3 lists unsorted.
1) Keep first list as it is.
2) Sort 2nd list in ascending order.
3) Sort 3rd list in descending order.

Now take each element of 1st list and search the rest of the sum in both the remaining lists.
Same logic as 2-sum problem of sorted array..

	for each element e in list1
		while(list2 && list3)
		{
			sum = e->data + list2->data + list3->data
			if sum is k
				return true
			else if sum<k
				go to next node in list2 .. // because list2 is sorted in ascending order and we need bigger sum so..
			else
				go to next node in list3... // because list3 is sorted in descending order and we need smaller sum so..
		}
	end

TC : O(n^2)
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

node *mergeLL(node *a,node *b,bool asc)
{
	if(!a)
		return b;
	if(!b)
		return a;

	node *temp,*newHead=NULL,*nd=NULL;
	while(a && b)
	{
		if(a->data < b->data)
		{
			temp = ((asc)?a:b);
			(asc)?(a=a->next):(b=b->next);
		}
		else
		{
			temp = ((asc)?b:a);
			(asc)?(b=b->next):(a=a->next);
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
			fast = fast->next;
		}

		*frontLL = source;
		*backLL = slow->next;
		slow->next = NULL;
	}
}

void mergeSort(node **head,bool asc)
{
	if(!(*head) || !((*head)->next))
		return;

	node *a,*b;

	splitList(*head,&a,&b);

	mergeSort(&a,asc);
	mergeSort(&b,asc);

	*head = mergeLL(a,b,asc);
}

bool findTriplet(node **head1,node **head2,node **head3, int k)
{
	mergeSort(head2,true);		// sort the second list in ascending order
	mergeSort(head3,false);		// sort the third list in descending order

	node *nd = *head1;		// traversing pointer for list1
	node *ptr1 = *head2;	// traversing pointer for list2	
	node *ptr2 = *head3;	// traversing pointer for list3
	int sum;
	
	while(nd)		// loop till first lists becomes empty
	{
		while(ptr1 && ptr2)	// second and third lists must not be empty
		{
			sum = nd->data + ptr1->data + ptr2->data;	
			if(sum==k)	// found the triplet
				return true;
			else if(sum<k)
				ptr1=ptr1->next;
			else
				ptr2=ptr2->next;
		}		
		nd = nd->next;	// checking for the next elements in first list
		ptr1 = *head2;	// resetting the pointer for second list
		ptr2 = *head3;	// resetting the pointer for third list
	}
	return false;
}

int main()
{	
	node *head1 = NULL;
	insert(&head1,1);
	insert(&head1,2);
	insert(&head1,3);
	insert(&head1,4);

	node *head2 = NULL;
	insert(&head2,1);
	insert(&head2,2);
	insert(&head2,3);
	insert(&head2,4);

	node *head3 = NULL;
	insert(&head3,1);
	insert(&head3,2);
	insert(&head3,3);
	insert(&head3,4);

	int k;
	cin >> k;
	cout << findTriplet(&head1,&head2,&head3,k) << endl;

	return 0;
}
