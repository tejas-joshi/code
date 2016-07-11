// ==== Convert a given Binary Tree to Doubly Linked List

// TC : O(n)
// SC : O(height) // stack space

node *BT_DLL_Rec(node *nd)
{
	// base case
	if(!nd)
		return NULL;
	
    // Convert the left subtree and link to root
	if(nd->left)
	{
		// convert the left subtree
		node *left = BT_DLL_Rec(nd->left);
		
		// Find inorder predecessor. After this loop, left
        // will point to the inorder predecessor
		while(left->right)
			left = left->right;
		
		// joining predecessor and current node
		
		left->right = nd;
		nd->left = left;
	}
	
    // Convert the right subtree and link to root
	if(nd->right)
	{
		// convert the right subtree
		node *right = BT_DLL_Rec(nd->right);
		
		// Find inorder sucessor. After this loop, right
        // will point to the inorder sucessor
		while(right->left)
			right = right->left;
		
		// joining successor with current node
		
		right->left = nd;
		nd->right = right;
	}
	
	return nd;
}

node *BT_DLL(node *root)
{
	// base case
	if(!root)
		return NULL;
	
	root = BT_DLL_Rec(root);
	
	// BT_DLL_Rec() returns root node of the converted
    // DLL.  We need pointer to the leftmost node which is
    // head of the constructed DLL, so move to the leftmost node
	while(root->left)
		root = root->left;
	
	return root;
}
