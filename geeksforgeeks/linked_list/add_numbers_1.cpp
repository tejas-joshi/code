//====== ADD TWO NUMBERS REPRESENTED IN THE LINKED LIST...

/*
Given two numbers represented by two lists,
write a function that returns sum list.
The sum list is list representation of addition of two input numbers.

Example 1

Input:
  First List: 5->6->3  // represents number 365
  Second List: 8->4->2 //  represents number 248
Output
  Resultant list: 3->1->6  // represents number 613

Input:
  First List: 7->5->9->4->6  // represents number 64957
  Second List: 8->4 //  represents number 48
Output
  Resultant list: 5->0->0->5->6  // represents number 65005

Logic :
Here LSB of the number is in the starting of the list so it will be easy to add...

Take two variables num1=0,num2=0
Both the variables contain the number from LSB side if not null otherwise 0.
carry will be initially 0
sum = num1 + num2 + carry
create node with sum%10 and carry will be sum/10...

Use this logic for all the numbers until both the lists will be empty...

Refer code for more clarity... It's easy to understand... 

TC : O(max(n1,n2))  // n1 = length of first number, n2 = length of second number

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

node *addNum(node *nd1,node *nd2)
{	
	int num1,num2,carry=0,sum=0;
	node *headSum=NULL,*tSum=NULL;

	while(nd1 || nd2)
	{
		num1=0,num2=0;		// to handle the case if any list becomes empty..
		
		if(nd1)		// from first list
		{
			num1 = nd1->data;
			nd1 = nd1->next;
		}
		if(nd2)		// from second list
		{
			num2 = nd2->data;
			nd2 = nd2->next;
		}
	
		sum = num1 + num2 + carry;	// sum
		
		if(!headSum)	// first number so initializing
			headSum = tSum = makeNode(sum%10);
		else        // other number
		{
			tSum->next = makeNode(sum%10);
			tSum = tSum->next; 
		}
		carry = sum/10;	// carry
	}

	if(carry)	// in the case where there is carry in the end
	{
		tSum->next = makeNode(carry);
		tSum = tSum->next;
	}	
	
	if(headSum)		// ending the list with NULL
		tSum->next = NULL;
		
	return headSum;
}

int main()
{	
	node *num1 = NULL;
	insert(&num1,9);
	insert(&num1,9);
	insert(&num1,9);

	node *num2 = NULL;
	insert(&num2,4);
	insert(&num2,5);
	insert(&num2,6);

	node *sum = addNum(num1,num2);	
	printLL(sum);
	
	return 0;
}	
