
struct node
{
	int data1,data2;
	struct node *left,*right;
};

typedef sturct node Node;

Node *makeNode(int data1,int data2,Node *left,Node *right)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data1 = data1;
	temp->data2 = data2;
	temp->left = left;
	temp->right = right;
	return temp;
}

Node *func(int low,int high)
{
	Node *t1=NULL,*t2=NULL,*nd;
	if(high-low==1)
	{
		t1 = makeNode(A[low],-1,NULL,NULL);
		t2 = makeNode(A[high],-1,NULL,NULL);
		nd = makeNode(A[low],A[high],t1,t2);
	}
	else if(high-low==0)
	{
		t1 = makeNode(A[low],-1,NULL,NULL);
		nd = makeNode(A[low],NULL,t1,t2);
	}
	else
	{
		t1 = func(low,(high-low)/2);
		t2 = func((high-low)/2+1,high);
		nd = makeNode(t1->data1,t2->data2,t1,t2);
	}
	return nd;
}
