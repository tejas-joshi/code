//==== PRINT NTH NODE IN THE LL

/*
Logic : 
Just read the code. you have only 5 seconds...

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

int nth_node(node *nd,int n)
{
	if(!nd)
		return -1;
	while(nd->next && n--)
		nd = nd->next;
	return nd->data;
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
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	
	int n;
	cin >> n;
	cout << nth_node(head,n) << endl;
	return 0;
}
