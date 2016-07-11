//====== COUNT THE NUMBER OF OCCURENCES OF GIVEN INTEGER IN LINKED LIST

/**
Logic :
Traverse the whole list and count the occurences. That's all... done

TC : O(n)
SC : O(1)
**/

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
	temp->data =data;
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

int countInt(node *nd,int d)
{
	int count=0;
	while(nd)
	{
		if(nd->data==d)
			count++;
		nd=nd->next;
	}
	return count;
}

int main()
{
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,2);
	insert(&head,2);
	
	cout << countInt(head,2) << endl;

	return 0;
}
