//=== CHECK WHETHER LL IS PALINDROME

/*
Logic :
Use the logic to reach the middle of the LL.
Push the data of slow pointer every time in the stack.

After reaching the middle of LL.
Move slow to next node.
	
while(1)
	if stack is empty
		return true

	Check top of the stack and the data of slow.
	if same 
		pop from the stack 
		slow = slow->next
	else
		return false

Refer to the code once to take care of corner cases and other things...		

TC : O(n)
SC : O(n)

Other logic to save the space is 
1) Reach the middle of the LL
2) Reverse the right half of the LL
3) Now compare both the halves of LL
4) Output whatever the result comes
5) Reverse again the next half of the LL.

TC : O(n)
SC : O(1)
*/

#include<iostream>
#include<stack>
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
		insert( &((*nd)->next),data);
}

bool isPalin(node *nd)
{
	if(!nd) // LL is empty
		return true;

	stack<int> S;
	node *slow=nd;
	node *fast=nd;

	// reaching middle of the LL
	while(fast->next && fast->next->next)
	{
		S.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}

	// push the slow data once again because in case of odd slow will point to middle one and even case slow will point to left node in the middle
	S.push(slow->data);
	
	bool isOddLen=false;
	if(!(fast->next))
		isOddLen =true;	

	slow = slow->next;	// now we use slow to traverse right half of the LL
	if(isOddLen)		// LL is of odd length so middle element should be poppped... 
		S.pop();

	while(1)
	{	
		if(S.empty())
			return true;

		if(S.top() != slow->data)
			return false;
		slow = slow->next;	// next node in the right half..
		S.pop();		// popping the stack.. i.e. going for previous node in the left half...
	}
}

int main()
{
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,2);
	insert(&head,1);	

	cout << isPalin(head) << endl;

	return 0;
}
