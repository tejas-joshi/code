//========== KTH SMALLEST FROM THE BST

/*
Logic :
Two functions are implemented here for the solution..
Refer the code for understanding.

TC : O(n)
SC : O(k)
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

// THIS RETURNS pointer to node PASSING ADDRESS OF K ...
node *inorder_for_kth_smallest(node *nd,int *k)
{
	node *t = NULL;
	if(nd)
	{
		t = inorder_for_kth_smallest(nd->left,k);
		
		(*k)--;
		if((*k)==0)
			t = nd;

		if(!t) 	// to avoid other calls after finding kth smallest
			t = inorder_for_kth_smallest(nd->right,k);
	}
	return t;
}

// THIS FUNCTION USES STATIC VARIABLE
void inorder_kth_smallest(node *nd,int k)
{
	static int count=0;
	if(nd)
	{
		inorder_kth_smallest(nd->left,k);
		
		count++;
		if(count==k)
			cout << nd->data << endl;

		if(count<k)	// to avoid other calls after finding kth smallest
			inorder_kth_smallest(nd->right,k);
	}
}	

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,7);
	insert(&root,10);
	insert(&root,6);

	int k;
	cin >> k;

	inorder_kth_smallest(root,k);
	
	node *ans = inorder_for_kth_smallest(root,&k); 
	
	if(ans)
		cout << ans->data << endl;
	return 0;
}
