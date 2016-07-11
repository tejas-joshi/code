//====== FIND THE DIAMETER OF THE TREE

/*

Given a tree, find the diameter of the tree.
Diameter is the max. distance between two nodes in the tree... 

		5
       / \
      3   9
     /   / \
    1	6   10 
	     \
	     12
Here the max. distance is between 1 and 12... 

Logic :
AWESOME LOGIC... YOU WANT MORE THAN ONE PARAMETERS TO SOLVE THE PROBLEM THEN 
		RETURN THE VARIABLE YOU WANT AS ANSWER AND PASS ADDRESSES OF OTHES AS THE PARAMETERS IN THE CALL AND UPDATE THEM IN THE CODE
								WHICH WILL BE USED IN THE PARENT TO SOLVE THE PROBLEM...

		SAME STRUCTURE IS FOLLOWED IN PROBLEM : CHECK IF THE TREE IS BALANCED OR NOT...

Use the same logic here..
You need height and the diameter till now to solve this problem...
So pass the address of height in the function and return the diameter..

Look into the code for more understanding... You will surely enjoy it...

TC : O(n)
SC : O(height)

*/

#include<iostream>
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

int diameter(node *nd,int *h)
{
	if(!nd)		// null => 0 diameter and 0 height
	{
		*h =0;
		return 0;
	}	

	// hLeft - height of left subtree
	// hRight - height of right subtree
	// lDia - diameter of left subtree
	// rDia - diameter of right subtree

	int hLeft,hRight;	
	int lDia,rDia;

	lDia = diameter(nd->left,&hLeft);	// Pass the address of hLeft.. value of hLeft will be updated after the execution of this call 
	rDia = diameter(nd->right,&hRight);	//		""     hRight				""
	// Both of these heights are used to decide current height as well as in the checking the diameter including this node...

	*h = 1 + max(hLeft,hRight);	// height of the tree including current node... This h will be used by the parent of the current node...
	return max(1+hLeft+hRight,max(lDia,rDia));		// udpdate the diameter if required.... AWESOME LOGIC NA !!! :)...
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,7);
	insert(&root,9);
	insert(&root,10);
	insert(&root,6);
	insert(&root,4);

	int h=0;
	cout << diameter(root,&h) << endl;


	return 0;
}	
