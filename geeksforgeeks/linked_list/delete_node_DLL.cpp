// Delete a node in a Doubly Linked List

/*
Algorithm
Let the node to be deleted is del.
1) If node to be deleted is head node, then change the head pointer to next current head.
2) Set next of previous to del, if previous to del exixts.
3) Set prev of next to del, if next to del exixts.
*/

/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void deleteNode(struct node **head_ref, struct node *del)
{
  /* base case */
  if(*head_ref == NULL || del == NULL)
    return;
 
  /* If node to be deleted is head node */
  if(*head_ref == del)
    *head_ref = del->next;
 
  /* Change next only if node to be deleted is NOT the last node */
  if(del->next != NULL)
    del->next->prev = del->prev;
 
  /* Change prev only if node to be deleted is NOT the first node */
  if(del->prev != NULL)
    del->prev->next = del->next;    
 
  /* Finally, free the memory occupied by del*/
  free(del);
}     
