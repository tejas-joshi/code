// Check for Identical BSTs without building the trees

/*
Given two arrays which represent a sequence of keys. Imagine we make a Binary Search Tree (BST) from each array. We need to tell whether two BSTs will be identical or not without actually constructing the tree.

Examples
For example, the input arrays are {2, 4, 3, 1} and {2, 1, 4, 3} will construct the same tree 

Solution :

Two arrays represent same BST if for every element x, the elements in left and right subtrees of x appear after it in both arrays. 
And same is true for roots of left and right subtrees.
The idea is to check of if next smaller and greater elements are same in both arrays. 
Same properties are recursively checked for left and right subtrees. 

TC : O(n^2)		// because linear searching is taking time
SC : O(n)		// in case of skewed BST .. stack space

*/

#include<iostream>
#include<limits.h>
using namespace std;

bool _checkBSTs(int *A,int *B,int size,int indA,int indB,int min,int max)
{
	int iA,iB;
	
	// finding the index that matches the constraints in array A
	for(iA=indA;iA<size;iA++)
		if(A[iA]>min && A[iA]<max)
			break;

	// finding the index that matched the constraints in array B
	for(iB=indB;iB<size;iB++)
		if(B[iB]>min && B[iB]<max)
			break;
	
	// both are leaves
	if(iA==size && iB==size)
		return true;
		
	// either of them is leaf  OR data mismatch	
	if((iA==size)^(iB==size) || A[iA]!=B[iB])
		return false;
		
	// check for left subtree and right subtree for both the arrays	
	return _checkBSTs(A,B,size,iA+1,iB+1,min,A[iA]) && _checkBSTs(A,B,size,iA+1,iB+1,A[iA],max);
}

bool checkForIdenticalBSTs(int *A,int *B,int size)
{
	return _checkBSTs(A,B,size,0,0,INT_MIN,INT_MAX);
}

int main()
{
	int n,*A,*B;
	cin >> n;
	
	A = new int[n];
	B = new int[n];
	
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	for(int i=0;i<n;i++)
		cin >> B[i];
	
	cout << checkForIdenticalBSTs(A,B,n) << endl;
	
	return 0;
}
