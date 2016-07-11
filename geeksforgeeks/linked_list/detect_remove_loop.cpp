// DETECT THE LOOP AND REMOVE IT..

/*
Logic :

1) Detect Loop using Floyd’s Cycle detection algo and get the pointer to a loop node.
2) Count the number of nodes in loop. Let the count be k.
3) Fix one pointer to the head and another to kth node from head.
4) Move both pointers at the same pace, they will meet at loop starting node.
5) Get pointer to the last node of loop and make next of it as NULL.

Logic is explained in the code and comments....

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
	head = makeNode(1);
	head->next = makeNode(2);
	head->next->next = makeNode(3);
	head->next->next->next = makeNode(4);
	head->next->next->next->next = head->next;

	// slow will move 1 node and fast will move to 2 nodes at a time..
	node *slow,*fast;
	slow = fast = head;

	while(fast && fast->next)	// to make sure to make 2 jumps for fast
	{
		slow = slow->next;		
		fast = fast->next->next;

		if(slow==fast)	// found the loop
			break;
	}

	node *loopPtr;
	if(slow && slow==fast)	// first confirms that LL is not empty.. found the loop so we are going to remove it	.. now slow and fast both are in loop
	{
		int count=0;	// to count the length of loop
		while(1)
		{
			slow = slow->next;		
			count++;
			if(slow==fast)	// came back to loop.. count will have the length of loop
				break;
		}

		node *ndFront = head;	// to make 'count' jumps from head..
		node *ndBack = head;	
		// so distance between ndFront and ndBack will be length of cycle..

		while(count--)
			ndFront = ndFront->next;		// moving ndFront as lenght of cycle..

		while(ndBack->next !=ndFront->next)	// move till next to both the nodes will be same.. 
		{
			ndBack = ndBack->next;
			ndFront = ndFront->next;
		}

		// Here ndFront is the last node in the loop..so make next to it to NULL...
		ndFront->next = NULL;
	}
		
	printLL(head);

	return 0;
}
