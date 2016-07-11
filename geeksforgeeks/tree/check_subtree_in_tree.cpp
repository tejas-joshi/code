#include<iostream>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node *makeNode (int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(node **nd,int data)
{
	if((*nd)==NULL)
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

bool isIdentical(node *nd1,node *nd2)
{
	if(!nd1 && !nd2)
		return true;
	if(!nd1 || !nd2)
		return false;
	return ( (nd1->data)==(nd2->data) && isIdentical(nd1->left,nd2->left) && isIdentical(nd1->right,nd2->right) );
}

bool isSubtree(node *S,node *T)
{
	if(!S)
		return true;
	if(!T)
		return false;
		
	if(isIdentical(S,T))
		return true;
	else
		return isSubtree(S,T->left) || isSubtree(S,T->right);
}

int main()
{
	node *rootT = NULL;
	insert(&rootT,5);
	insert(&rootT,3);
	insert(&rootT,1);
	insert(&rootT,7);
	insert(&rootT,9);
	insert(&rootT,4);

	node *rootS = NULL;
	insert(&rootS,3);
	insert(&rootS,1);
	insert(&rootS,4);

	cout << isSubtree(rootS,rootT) << endl;
	
	return 0;
}
