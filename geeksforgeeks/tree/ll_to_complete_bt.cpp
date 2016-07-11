// === CONVERT SINGLY LINKED LIST TO COMPLETE BINARY TREE..

/*

LL : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

BT :

			1
		   /  \
		  2    3
	     / \  / \
    	4   5 6  7
	   /
	  8
*/

// JUST OBSERVE THE EXAMPLE.. YOU WILL GET THE LOGIC FOR THE SOLUTION

/*
Logic : 

USE BFS for this problem

1. Create an empty queue.
2. Make the first node of the list as root, and enqueue it to the queue.
3. Until we reach the end of the list, do the following.
………a. Dequeue one node from the queue. This is the current parent.
………b. Traverse two nodes in the list, add them as children of the current parent.
………c. Enqueue the two nodes into the queue.

TC : O(n)
SC : O(n/2) // max number of nodes in the leaf level

*/

BTNode *convertLLtoBT(LLNode *head)
{
	BTNode *root;
	
	if(!head)
	{
		root = NULL;
		return root;
	}
	
	queue<BTNode *> Q;
	
	root = createBTNode(head->data);
	Q.push(root);
	
	head = head->next;
	
	while(head)
	{
		BTNode *nd = Q.front();
		Q.pop();
		
		if(head)
		{
			nd->left = createBTNode(head->data);
			Q.push(nd->left);			
			head = head->next;
			
			if(head)
			{
				nd->right = createBTNode(head->data);
				Q.push(nd->right);
				head = head->next;
			}
		}
	}
	return root;
}
