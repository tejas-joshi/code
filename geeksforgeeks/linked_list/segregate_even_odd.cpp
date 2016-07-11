//====== SEGREGATE EVEN AND ODD NUMBERS IN THE LINKED LIST...

/*
Logic :

Loop through whole list..
Split the linked list into two lists.
One will contain the list of even numbers
Other will contain the list of odd numbers.

After the loop join the odd list at the end of even list and return the head of even list...
TAKE CARE ABOUT THE CORNER CASES.
* WHEN THERE ARE NO ODD NUMBERS
* WHEN THERE ARE NO EVEN NUMBERS...

REFER CODE FOR MORE CLARITY AND CONDITIONS... 

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

void printLL(node *nd)
{
	while(nd)
	{
		cout << nd->data << " ";
		nd = nd->next;
	}
	cout << endl;
}

node *segregateEvenOdd(node *nd)
{
	node *headOdd=NULL,*headEven=NULL;		// head variables of both the lists
	node *tOdd=NULL,*tEven=NULL;			// pointers that points to the last node of each list..

	while(nd)	// nd to loop through whole list
	{
		if(nd->data%2)	// ODD NUMBER
		{
			if(!headOdd)	// FIRST ODD NUMBER SO INITIALIZE BOTH THE VARIABLES
				headOdd = tOdd = nd;
			else
			{
				tOdd->next = nd;	
				tOdd = tOdd->next;
			}
		}
		else       // EVEN NUMBER
		{
			if(!headEven)	// FIRST EVEN NUMBER SO INITIALIZE BOTH THE VARIABLES
				headEven = tEven = nd;
			else
			{
				tEven->next = nd;
				tEven = tEven->next;
			}	
		}
		nd = nd->next;
	}

	if(tOdd)	// ending the odd list with NULL
		tOdd->next = NULL;
	if(tEven)	// ending the even list with NULL
		tEven->next = NULL;

	
	if(headEven)	// atleast one even number so safe to join with odd list
		tEven->next = headOdd;
	else           // no even numbers so it will be odd list
		headEven = headOdd;

	return headEven;	
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

	head = segregateEvenOdd(head);	
	printLL(head);
	
	return 0;
}	
