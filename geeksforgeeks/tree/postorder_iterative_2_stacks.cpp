// ITERATIVE POST ORDER USING TWO STACKS

// YOU CAN ALSO IMPLEMENT REVERSE POSTORDER FROM THIS ALSO... 
// JUST CHANGE THE ORDER OF PUSHING INTO FIRST STACK.. (first right then left)

void postorderItr(node *root)
{
	stack<int> S1,S2;
	
	if(!nd)
		return;
	
	// pushing root to first stack
	S1.push(root);
	
	node *nd;
	
	while(!S1.empty())	// till first stack is not empty
	{
		// popping from first stack and pushing to second stack
		nd = S1.top();
		S1.pop();
		S2.push(nd);

		// pushing left first because right will be in the top so that right will be processed first than left.. as per postorder			
		if(nd->left)	// if the popped element has left then push it into first stack
			S1.push(nd->left);
		if(nd->right)	// if the popped element has right then push it into first stack	
			S1.push(nd->right);
	}

	// now we have all the elements in second stack in reverse order..	
	// printing from STACK will maintain the order.. so DONT WORRY
	while(!S2.empty())
	{
		cout << S2.top() << " ";
		S2.pop();	
	}
	cout << endl;
}
