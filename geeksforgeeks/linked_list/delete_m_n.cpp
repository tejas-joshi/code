// Delete N nodes after M nodes of a linked list

/*
Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, 
continue the same till end of the linked list.

Difficulty Level: Rookie

Examples:

Input:
M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
Output:
Linked List: 1->2->5->6

Input:
M = 3, N = 2
Linked List: 1->2->3->4->5->6->7->8->9->10
Output:
Linked List: 1->2->3->6->7->8
*/

void skipMdeleteN(node *head,int M,int N)
{
	node *curr = head;
	
	while(curr)
	{
		// this loop iterates (M-1) times because we are at the head already so one node already done..
		for(int i=1;i<M && curr;i++)
			curr = curr->next; 
			
		if(!curr)
			return;
		
		// now we start deleting nodes
		node *del = curr->next;
	
		// this will be N times because we have to delete del node also.
		for(int i=1;i<=N;i++)
		{
			node *temp = del;
			del = del->next;
			delete temp;
		}
		
		// connecting the links
		curr->next = del;	
	
		// go for next turn
		curr = curr->next;
	}
}
