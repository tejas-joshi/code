// SWAP KTH AND (KTH FROM LAST) NODE IN THE LINKED LIST....

void swapKlastK(node **head,int k)
{
	int n = countNodes(*head);	// counting the nodes
	
	if(k>n)			
		return;
	if(2*k-1==n)		// K and last from K are same
		return;
	
	node *K=*head;
	node *prevK=NULL;
	for(int i=0;i<k;i++)		// maintain K and previous of K 
	{
		prevK = K;
		K = K->next;	
	}	

	node *lastK=*head;
	node *prevlastK=NULL;
	for(int i=0;i<n-k+1;i++)	// maintain last from K and its previous
	{
		prevlastK = lastK;
		lastK = lastK->next;	
	}	
	
	// updation of pointers .... TAKE CARE .. READ TWICE
	if(prevK)					
		prevK->next = lastK;
	if(prevlastK)
		prevlastK->next = K;
		
	node *temp = K->next;
	K->next = lastK->next;
	lastK->next = temp;

	// CORNER CASES	... TAKE CARE... READ THRICE
	if(k==1)				
		*head = lastK;
	if(k==n)				
		*head = K;
}
