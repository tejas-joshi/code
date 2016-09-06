// XOR Linked List – A Memory Efficient Doubly Linked List 

/*
1) A function to insert a new node at the beginning.
2) A function to traverse the list in forward direction.

INSERTION
We store XOR of next and previous nodes with every node, which is the only address member we have with every node.
When we insert a new node at the beginning, npx of new node will always be XOR of NULL and current head. 
And npx of current head must be changed to XOR of new node and node next to current head.

PRINT
Traverses the list in forward direction.
To traverse the list, we need to get pointer to the next node at every point. 
We can get the address of next node by keeping track of current node and previous node. 
If we do XOR of curr->npx and prev, we get the address of next node. 
*/

typedef struct node_n
{
	int data;
	node *xPtr;
} node;

node *XOR(node *left,node *right)
{
	return  (node *)( ((unsigned int)left)^((unsigned int)right) );
}

// we are inserting new node at the head side
void insert(node **head,int data)
{
	node *temp = createNode(data);
	
	// setting xPtr of new node
	temp->xPtr = XOR(*head,NULL);
	
	// case when head is not NULL i.e. we have to update xPtr of current head also.
	if(head)
	{
		node *nextHead = XOR((*head)->xPtr,NULL);
		(*head)->xPtr = XOR(nextHead,temp);
		
		// i.e. (*head)->xPtr = XOR((*head)->xPtr,temp);
	}

	// setting the new node as head node	
	*head = temp;
}

void print(node *head)
{
	node *prev = NULL;
	node *curr = head;
	node *next;
	
	while(curr)
	{
		cout << curr->data << " ";
		
		// get address of next node: curr->xPtr is next^prev, 
		// so (curr->xPtr)^prev will be next^prev^prev which is next
		next = XOR(curr->xPtr,prev);
		
		// update prev and curr for next iteration
		prev = curr;
		curr = next;
	}
}
