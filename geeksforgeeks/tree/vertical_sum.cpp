//===== PRINT VERTICAL SUM OF BTREE
// LOGIC IN THE COMMENTS

// YOU KNOW THE LOGIC... TRY TO FIND OUT THE MAXIMUM SIZE OF THE HASH

#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;


node *makeNode(int data)
{
	node *t = new node;
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

void verticalSum(node *nd,map<int,int>* myMap,int level)
{
	if(nd)
	{
		verticalSum(nd->left,myMap,level-1);	// previous level for left element
		(*myMap)[level] = (*myMap)[level] + nd->data;	// add current element to current level
		verticalSum(nd->right,myMap,level+1);	// next level for right element	
	}
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,4);
	insert(&root,7);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);

	map<int,int> myMap;
	verticalSum(root,&myMap,0);		// considering root at level 0

	// Printing each level's sum from map
	for(map<int,int>:: iterator it = myMap.begin();it!=myMap.end();it++)
		cout << it->second << " ";
	
	return 0;
}
