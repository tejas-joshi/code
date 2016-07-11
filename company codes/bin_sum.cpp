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

node *buildTree(int *A,int n,int i)
{
	if(i>=n)
		return NULL;

	node *t = makeNode(A[i]);
	t->left = buildTree(A,n,2*i+1);
	t->right = buildTree(A,n,2*i+2);	
	return t;
}

int binarySum(node *nd,int *maxCur)
{
	if(!nd)
		return INT_MIN;
	else if(!(nd->left) && !(nd->right))
	{	
		*maxCur = nd->data;
		return nd->data;
	}	
	else
	{
		int leftSum,rightSum;
		int maxLeft,maxRight;

		leftSum = binarySum(nd->left,&maxLeft);
		rightSum = binarySum(nd->right,&maxRight);

		int curSum = nd->data + maxLeft + maxRight;
		*maxCur = max(nd->data + maxLeft,nd->data + maxRight);
		if(curSum>leftSum && curSum>rightSum)
			return curSum;
		else
			return max(leftSum,rightSum);
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

void inorder(node *nd)
{
	if(nd)
	{
		inorder(nd->left);
		cout << nd->data << " ";
		inorder(nd->right);
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

		for(int i=0;i<n;i++)
			cin >> A[i];
	
		node *root = buildTree(A,n,0);
		int maxCur;
		cout << binarySum(root,&maxCur) << endl;
		deleteTree(root);
	}
	
	return 0;
}
