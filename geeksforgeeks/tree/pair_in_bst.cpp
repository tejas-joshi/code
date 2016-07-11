//== FIND A PAIR IN BST HAVING THE SUM K..

// Idea 1 : Convert BST to DLL and then find the pair with the logic of finding the pair in sorted array with sum k
// 		but this conversion changes the BST links.

// If the links are not allowed to be changed then you have to apply this logic only.
// Idea 2 is what you thought when you get this problem at first time...

/*
 * 
 * Do Inorder and Reverse Inorder at the same time.
 * When you find the sum, print the pair and return true;
 * else
 * 		If the sum is greater than k  --> Get the next element from reverse inorder
 * 		else if the sum is lesser than k --> Get the next element from inorder
 *		
 * 		if element at inorder >= element at reverse inorder then
 * 			return false;   // there is no pair with sum k..

TC : O(n)
SC : O(logn)
 
 *
 */

bool findSumKPair(node *root,int k)
{
	stack<node *> sIn,sRevIn;		// one for inorder and another for reverse inorder
	node *currIn=root,*currRevIn=root;		// current nodes for both the traversals
	bool doIn = true,doRevIn = true;		// setting the flag for which traversal to allow for getting the next element
	int valIn,valRevIn;				// to store the current element of both the traversals	
	
	while(1)
	{
		// INORDER TRAVERSAL
		while(doIn)		// only when doIn flag is true
		{
			// NORMAL INORDER TRAVERSAL WITH STACK
		
			if(currIn)
			{
				sIn.push(currIn);
				currIn = currIn->left;		 // left
			}
			else  // Here we get the element so we have to break from while.. so setting flag to false at the end
			{
				if(!sIn.empty())
				{
					currIn = sIn.top();		// current
					sIn.pop();
					valIn = currIn->data;

					currIn = currIn->right;		// right				
				}
				
				doIn = false;	
			}
		}
		
		// REVERSE INORDER TRAVERSAL
		while(doRevIn)
		{
			// NORMAL REVERSE INORDER TRAVERSAL
			if(currRevIn)
			{
				sRevIn.push(currRevIn);
				currRevIn = currRevIn->right;	// right
			}	
			else    // Here we are going to get the element so we have to break from the loop.. so setting flag to false..
			{
				if(!sRevIn.empty())
				{
					currRevIn = sRevIn.top();	// current
					sRevIn.pop();
					valRecIn = currRevIn->data;
					
					currRevIn = currRevIn->left;	// left
				}
				doRevIn = false;
			}	
		}
		
		if(valIn != valRevIn  && valIn+valRevIn==k)		// both should not be same and checking the sum with k
		{
			cout << "Found sum with pair " << valIn << " and " << valRevIn << endl;
			return true;
		}	
		else if(valIn+valRevIn < k)	// if sum is < k then we should get next element at inorder.. so allow it only
			doIn = true;
		else if(valIn+valRevIn > k)	// if sum is > k then we should get next element at reverse inorder .. so allow that only
			doRevIn = true;
		
		if(valIn >= valRevIn)		// both elements crossed.. so no point in checking further... no pair found..returning false..
			return false;
	}
	
	
}
