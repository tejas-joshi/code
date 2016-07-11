#include<iostream>
#include<limits.h>
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
	else if(((*nd)->data)<data)
		insert(&((*nd)->right),data);
	else
		insert(&((*nd)->left),data);		
}

void inorder(node *nd)
{
	if(nd)
	{
		inorder(nd->left);
		cout << nd->data << " ";
		inorder(nd->right);
	}
}

void maxWeight(node *nd,int *incl,int *excl)
{
	if(!nd)
	{
		*incl = INT_MIN;
		*excl = INT_MIN;
	}
	else if(!(nd->left) && !(nd->right))
	{
		*incl = nd->data;
		*excl = INT_MIN;
	}
	else if(!(nd->left))
	{
		int incl_right,excl_right;
		maxWeight(nd->right,&incl_right,&excl_right);
			
		*incl = max(nd->data,nd->data+excl_right);
		*excl = incl_right;
	}
	else if(!(nd->right))
	{
		int incl_left,excl_left;
		maxWeight(nd->left,&incl_left,&excl_left);
			
		*incl = max(nd->data,nd->data+excl_left);
		*excl = incl_left;
	}	
	else
	{
		int incl_left,incl_right,excl_left,excl_right;
		maxWeight(nd->left,&incl_left,&excl_left);
		maxWeight(nd->right,&incl_right,&excl_right);

		*incl = max(nd->data,
				max(excl_left,
				max(excl_right,
				max(excl_left+excl_right,
				max(nd->data+excl_left,
				max(nd->data+excl_right,nd->data+excl_left+excl_right))))));
						
		*excl = max(incl_left,
				max(incl_right,incl_left+incl_right));
	}
}

void deleteTree(node *nd)
{
	if(!nd)
		return;
	else
	{
		deleteTree(nd->left);
		deleteTree(nd->right);
		delete nd;
	}
}

int main()
{
	int *A,n,T;
	cin >> T;

	while(T--)
	{
		cin >> n;
		A = new int[n];
		node *root = NULL;

		for(int i=0;i<n;i++)
		{
			cin >> A[i];
			insert(&root,A[i]);
		}

		int excl,incl;
		maxWeight(root,&incl,&excl);
		cout << max(incl,excl) << endl;
		deleteTree(root);
	}
	return 0;
}
