//==== PRINT ELEMENTS IN ZIG-ZAG MANNER IN TREE

/****
 * 
 * LOGIC :
 * =====
 *
 * Here we take deque D and push NULL. NULL is used to indicate partition between front and back partition of D.
 *
 * Push root to front.
 *
 * Here we loop through till D has >1 elements. (D has some elements other than NULL(partition element)
 *
 * left bool variable is used to indicate current direction of traversing (pushing to the deque).
 *
 * if left is true	( it means push the left child first and then right child )
		loop through all elements in front till you meet NULL(partition element).
			print current element.
			push LEFT(if not null) and then RIGHT(if not null) child to back of D. pop current element
		invert the value of left.
	else
		loop through all elements in back till you meet NULL (partition element).
			print current element.
			push RIGHT(if not null) and then LEFT(if not null) child to front of D. pop current element.
		invert the value of left.

NOTE :
* Look at the sequence of insertion (LEFT/RIGHT) at both sides
* Only push those nodes which are not null. So check the node before inserting otherwise it will be interpreted as partition element.

TC : O(n)
SC : O(n) (size of deque)

****/

#include<iostream>
#include<stdlib.h>
#include<deque>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node *makeNode(int data)
{
	node *t = (node *)malloc(sizeof(node));
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
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

	deque<node *> D;

	D.push_front(NULL);	// partition element
	
	if(root)
		D.push_front(root);
	
	bool left = true; // decide current direction of traversing

	while(D.size()>1)	// D has some elements other than NULL(partition element)
	{
		if(left)	// front side
		{
			node *t = D.front();
			while(t)
			{
				cout << t->data << " ";
				if(t->left)		
					D.push_back(t->left);	// first left
				if(t->right)	
					D.push_back(t->right);	// then right
				D.pop_front();
				t = D.front();
			}
			left = !left;	// change direction to back
		}
		else     // back side
		{
			node *t = D.back();
			while(t)
			{
				cout << t->data << " ";
				if(t->right)	
					D.push_front(t->right);	// first right
				if(t->left)		
					D.push_front(t->left);	// then left
				D.pop_back();
				t = D.back();	
			}
			left = !left;	// change direction to front
		}
	}
	
	return 0;
}
