//====== CHECK IF THE TREE IS BALANCED.. 

/*
Check if the tree is balanced or not... 
The tree is balanced if the difference of left subtree and right subtree can be max. 1..

Logic :
AWESOME LOGIC... USE THE SAME STRUCTURE IF THERE'S ANY PROBLEM WHERE YOU WANT TO RETURN MORE THAN 1 VALUE...
ONE PARAMETER THAT IS BEING RETURNED BUT FOR OTHER THINGS YOU WANT..
=> Pass the addresses of them in the paremeters and update them in the subsequent calls.
   Now you can use them in the current call for solving the problem...								

Pass the address of the height in the argument and update it in the code...
Call the isBalanced function recursively that will return bool but also updates the variable for height also..
That variable is used for the parent to decide whether their child subtrees are balanced or not...

Awesome logic... 
Just refer the code very carefully... You will surely enjoy it... 

TC : O(n)
SC : O(height of the tree)....
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node_n
{
	int data;
	struct node_n *left,*right;
};
typedef struct node_n node;

node *makeNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if((*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}	

bool isBalanced(node *nd,int *h)
{
	if(!nd)		// null so no height and balanced...
	{
		*h = 0;
		return true;
	}

	// hLeft for height of left subtree
	// hRight for height of right subtree
	bool rBal,lBal;
	int hLeft,hRight;	

	// lBal indicates whether left subtree is balanced or not.. 
	// rBal indicates whether right subtree is balanced or not..
	lBal = isBalanced(nd->left,&hLeft);		// This call will update hLeft after execution of it that is used here...
	rBal = isBalanced(nd->right,&hRight);	//		"" 	 hRight			""

	*h = 1 + max(hLeft,hRight);	// This will update the height of the tree including this node which will be used for parent...

	return (abs(hLeft-hRight)<=1 && lBal && rBal);		// checking all the conditions for balanced...
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,7);
	insert(&root,10);
	//insert(&root,4);
	insert(&root,6);
	insert(&root,12);

	int h=0;

	cout << isBalanced(root,&h) << endl;

	return 0;
}
