// Given a linked list which is sorted, how will you insert in sorted way

// Just read the code... You will easily understand.
// Take care about the corner cases.

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortedInsert(node** head_ref,  node* new_node)
{
	node* current;

	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		
		while (current->next!=NULL && current->next->data < new_node->data)
			current = current->next;
		
		new_node->next = current->next;
		current->next = new_node;
	}
}
