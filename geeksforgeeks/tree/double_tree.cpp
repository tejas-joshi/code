//====== DOUBLE TREE PROBLEM

/*
To create Double tree of the given tree, create a new duplicate for each node, and insert the duplicate as the left child of the original node. 
		2
       / \
      1   3

is changed to…

        2
       / \
      2   3
     /   /
    1   3
   /
  1

            1
          /   \
         2      3
        /  \
      4     5

is changed to

                     1
                   /   \
                  1      3
                 /      /
               2       3
             /  \
            2    5
           /    /
          4    5
         /   
        4    

Logic :
Recursively convert the tree to double tree in postorder fashion. 
For each node, first convert the left subtree of the node, then right subtree, 
finally create a duplicate node of the node and fix the left child of the node and left child of left child.

Refer code for more clarity...

TC : O(n)
SC : O(height)	// stack space

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

void doubleTree(node **nd)
{
	if(*nd)
	{
		doubleTree(&((*nd)->left));
		doubleTree(&((*nd)->right));
	
		if(!((*nd)->left))				// DO WE REQUIRE THIS CONDITION ??.. OR IS IT ENOUGH TO WRITE 3 STATEMENTS IN else PART...	AS FAR AS YOU CHECKED, CONDITION IS NOT REQUIRED...
			(*nd)->left = makeNode((*nd)->data);
		else
		{
			node *temp = makeNode((*nd)->data);
			temp->left = (*nd)->left;
			(*nd)->left = temp;
		}
	}
}

// ANOTHER IMPLEMENTATION YOU THOUGHT IS 

void doubleTree2(node **nd)
{
	if(*nd)
	{
		node *leftNd = (*nd)->left;
		(*nd)->left = makeNode((*nd)->data);
		(*nd)->left->left = leftNd;
		
		doubleTree2(&leftNd);
		doubleTree2(&((*nd)->right));
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
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,4);

	doubleTree(&root);

	inorder(root);
	cout << endl;

	return 0;
}
