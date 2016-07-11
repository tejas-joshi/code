// DIVIDE THE CLL INTO TWO HALF CLLs

/*
Logic :

Use the logic of middle node of the list and reach in the middle of CLL...
Set the next of fast to slow->next
Set the next of slow to head

TAKE CARE ABOUT MAKING JUMPS OF fast POINTER...
DONT GO FOR TWO JUMPS DIRECTLY... CHECK CONDITION ON EACH JUMP...
REFER CODE FOR CORNER CASES AND CONDITIONS...

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
	{		
		node *temp = *nd;
		while(temp->next)
			temp = temp->next;
		temp->next = makeNode(data);
	}		
}

void printLL(node *nd)
{
	node *t = nd;
	while(nd)
	{
		cout << nd->data << " ";
		nd = nd->next;

		if(t==nd)
			break;
	}
	cout << endl;
}

void partitionCLL(node *head,node **frontCLL,node **backCLL)
{
	// frontCLL will be head of first CLL
	// backCLL will be head of second CLL
	
	if(!head || !head->next)	// 0 or 1 node in CLL
	{
		*frontCLL = head;
		*backCLL = NULL;
	}
	else
	{
		// partition the CLL... slow will be the last node the first CLL(middle in original CLL), fast will be last node in the second CLL

		node *slow = head;
		node *fast = head->next;

		// TAKING CARE ABOUT THE CONDITIONS OF fast POINTER.. DONT JUMP DIRECTLY TWO JUMPS OTHERWISE IT MAY POINT TO head...
		// HERE WE HAVE MAKE next OF FAST THE MIDDLE OF THE CLL... IF fast WILL BE head THEN IT WILL BE BUG...
		
		while(fast->next!=head)	// CONDITION 1
		{
			slow = slow->next;
			fast = fast->next;	// JUMP 1 OF fast

			if(fast->next!=head)	// CONDITION 2
				fast = fast->next;	// JUMP 2 OF fast
			else
				break;
		}

		// SEPARATING THE LISTS
		*frontCLL = head;		// head of first CLL will be head of original CLL
		*backCLL = slow->next;	// head of second CLL will be next of slow which is last node in first CLL

		// MAKING THOSE CIRCULAR
		slow->next = head;		// make first LL circular...
		fast->next = *backCLL;	// making second LL cicrular...	
	}
}

int main()
{	
	node *head = NULL;
	head = makeNode(1);
	head->next = makeNode(2);
	head->next->next = makeNode(3);
//	head->next->next->next = head;
	
	head->next->next->next = makeNode(4);
	head->next->next->next->next = head;

	node *frontCLL,*backCLL;
	partitionCLL(head,&frontCLL,&backCLL);
			
	printLL(frontCLL);
	printLL(backCLL);
	return 0;
}
