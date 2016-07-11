//======== PRINT ALL ROOT TO LEAF PATHS

/***
		5
       / \
      3	  7
     /   /
    1   6

op : 5 3 1
     5 7 6

Logic :

Take vector and pass the address of it in the function
Push the data for all the non-leaf nodes and go to left and right.. Then pop the data from vector..
When leaf is found, print the whole vector and then data on leaf(because that was not pushed into vector)

TAKE CARE ABOUT VECTOR SYNTAX...

	if v is pointer to vector then
		v->push_back(..)
		v->pop_back()
		v->size()
		v->at(..)	// you cant access using V[i]

	Look for vector syntax 
	- call in main
	- definition of function
	- push_back
	- pop_bacl
	- call for left and right
	- size
	- accessing elements
	ALL THESE POINTS ARE MARKED AS  (//   <==== VECTOR SYNTAX ====================)   IN THE CODE... TAKE CARE....

Refer code for more clarity...

TC : O(n)
SC : O(n)	// to print

*/

#include<iostream>
#include<vector>
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

void printRootLeafPath(node *nd,vector<int> *V)  		//   <==== VECTOR SYNTAX ==================== second paramater
{
	if(!nd)	// null node
		return;
	else if(!(nd->left) && !(nd->right)) // leaf node ... print vector + leaf data
	{
		int size = V->size();				//   <==== VECTOR SYNTAX ====================	size
		for(int i=0;i<size;i++)			
			cout << V->at(i) << " ";		//   <==== VECTOR SYNTAX ====================   accessing element
		cout << nd->data << endl;
	}
	else	// non-leaf nodes
	{	
		V->push_back(nd->data);	// push data to vector  //   <==== VECTOR SYNTAX ==================== push_back
				
		printRootLeafPath(nd->left,V);	// call left    //   <==== VECTOR SYNTAX ==================== second parameter
		printRootLeafPath(nd->right,V);	// call right   //   <==== VECTOR SYNTAX ==================== second parameter
		
		V->pop_back();		// pop from vector because current data wont be used  //   <==== VECTOR SYNTAX ==================== pop_back
	}
}

int main()
{
	vector<int> V;	 //   <==== VECTOR SYNTAX ==================== definition
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,7);
	insert(&root,9);
	insert(&root,4);
	
	printRootLeafPath(root,&V); //   <==== VECTOR SYNTAX ==================== second parameter

	return 0;
}	
