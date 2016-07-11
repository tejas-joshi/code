//=== REMOVE NODES FROM BST WHICH ARE OUTSIDE THE GIVEN RANGE...

/*	
				6
			  /   \
			-13    14
			  \	   / \
		      -8  13  15
			     /
			    7

	RANGE IS [-10,13]
	
	NOW THE MODIFIED TREE SHOULD BE
	
		6
	  /   \
	-8     13
		  /
		 7

TC : O(n)
SC : O(height)
	
*/ 	


// rangeMin and rangeMax are the bounds of range... i.e. [rangeMin,rangeMax]
node *removeNodesRange(node *root,int rangeMin,int rangeMax)
{
	if(!root)
		return NULL;
	
	root->left = removeNodesRange(root->left,rangeMin,rangeMax);
	root->right = removeNodesRange(root->right,rangeMin,rangeMax);
	
	if(root->data < rangeMin)
	{
		node *rChild = root->right;
		delete root;
		return rChild;	
	}
	
	if(root->data > rangeMax)
	{
		node *lChild = root->left;
		delete root;
		return lChild;
	}
	
	return root;
}


int main()
{
	// adding of nodes in BST
	
	int rangeMin,rangeMax;
	cin >> rangeMin >> rangeMax;
	
	// nd will have the root node of the modified tree after removing the nodes from the range
	node *nd = removeNodesRange(root,rangeMin,rangeMax);
		
	return 0;
}
