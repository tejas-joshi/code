//=========	THE GREAT TREE-LIST PROBLEM...

/*
Given a tree, convert it to circular DLL...

See the pics of the link : http://cslibrary.stanford.edu/109/TreeListRecursion.html

AWESOME LOGIC... FAAAAAAADDDDDDDDDDD.... MMAAASSSTT...

Logic is in the comments..

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
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if( (*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}

// sets the pointer for join... 
void join(node *a, node *b)
{
	a->right = b;	// right of a TO b
	b->left = a;	// left of b TO a
}

// this function return the head of new DLL in which b is appended to a...
node *append(node *a,node *b)
{
	if(!a)		// a is null so b itself 
		return b;
	if(!b)		// b is null so a itself
		return a;

	node *aLeft = a->left;	// go to left of head of a... a->left will point to the last node in DLL a
	node *bLeft = b->left;	// go to left of head of b... b->left will point to the last node in DLL a

	// HERE WE HAVE TWO JOINS TO JOIN a AND b DLLs...
	// 1) Last of a (a->left) TO first node of b (b)
	// 2) last node of b (b->left) TO first node of a (a) 

	join(aLeft,b);		// do (1)	
	join(bLeft,a);		// do (2)

	return a;		// return the head which is first node of list a (now joint DLL)
}

node *treeToList(node *root)
{
	if(!root)	
		return NULL;

	node *leftList,*rightList;

	leftList = treeToList(root->left);		// recursively for left subtree
	rightList = treeToList(root->right);	// recursively for right subtree

	// making the root circular DLL with single node..
	root->left = root;		
	root->right = root;

	// Here we have circular DLL for left subtree with the head 'leftList'
	// 						 	 for right subtree with the head 'rightList'
	//	and root with circular DLL of single node (itself)

	leftList = append(leftList,root);		// joining left circular DLL to root DLL
	leftList = append(leftList,rightList);	//  joining the above joined DLL to right DLL

	return leftList;	// return the head of the DLL which is head of left DLL...
}

// printing the circular linked list
void printLL(node *head)
{
	node *nd = head;
	while(nd)
	{
		cout << nd->data << " ";
		nd = nd->right;
		if(nd==head)
			break;
	}
	cout << endl;
}

int main()
{
	node *root = NULL;
	insert(&root,4);
	insert(&root,6);
	insert(&root,1);
	insert(&root,3);
	insert(&root,2);
	insert(&root,10);

	node *head = treeToList(root);
	printLL(head);
	return 0;
}
