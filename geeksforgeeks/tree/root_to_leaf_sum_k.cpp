//===== CHECK WHETHER ROOT TO LEAF PATH CONTAINS THE GIVEN SUM..

/*
e.g.
		10
       /   \
      8     2
     / \   /
    3   5 2

 The tree given above should give true for sum
 21 => 10 + 8 + 3
 23 => 10 + 8 + 5
 14 => 10 + 2 + 2

 For all other cases it should output false...

Logic :

If node is null and k is 0 then true
else if nd is not null, go to next level recursively but subtract data of current node from k and call for left and right
else false

	checkSum(nd,k)
		if nd is null and k=0
			true
		else if nd
			checkSum(nd->left,k- nd->data) || checkSum(nd->right,nd->right,k-nd->data)
		else
			false
TC : O(n)
SC : O(height) // stack space


Another solution is use BFS and store the sum of node to current sum and store it in the queue. While popping out the node..
* Check the node, it is leaf then check with X.. 

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
	else if( (*nd)->data > data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}

bool checkRootLeafSum(node *nd,int k)
{
	if(!nd && k==0)
		return true;
	else if(nd)
		return checkRootLeafSum(nd->left,k-nd->data) || checkRootLeafSum(nd->right,k-nd->data);
	else
		return false;
}

int main()
{
	node *root=NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,4);
	insert(&root,7);
	insert(&root,9);

	int k;
	cin >> k;
	cout << checkRootLeafSum(root,k) << endl;
	return 0;
}
