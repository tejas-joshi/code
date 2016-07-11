//=== PRINT THE SORTED ORDER FROM THE ARRAY THAT HAS LEVEL ORDER OF COMPLETE TREE..

/*
Logic : 
Just modify the inorder traversal.
If element at i is current node then left subtree is at 2*i+1 and right subtree is at 2*i+2...
Refer code for more understanding

THIS LOGIC ONLY WORKS FOR COMPLETE BINARY TREE..

TC : O(n)
SC : O(logn) // stack space
*/

#include<iostream>
using namespace std;

void printSorted(int *A,int start,int end)
{
	if(start<=end)
	{
		printSorted(A,start*2+1,end);	// left subtree
		cout << A[start] << " ";
		printSorted(A,start*2+2,end);	// right subtree
	}
}

int main()
{
	int *A,n;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	printSorted(A,0,n-1);

	return 0;
}
