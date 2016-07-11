//==== SEGMENT TREE ... RANGE SUM QUERY AND SINGLE UPDATE QUERY
//	Here sum will also be updated after updating the element.

/*
TC : O(n)  	 // for tree constuction .. but that is one time cost
     O(logn) // for full BT height
SC : O(n)	 // taking extra array of size 2*(2^height)-1 where height = ceil(log2(n)) 	

TC : O(logn) // point update in full BT height
SC : O(n)	 // same array taken above will be updated 	
*/

#include<iostream>
#include<math.h>
#define MID(low,high) (low + (high-low)/2)
using namespace std;

// main function for segment tree updation

// sStart and sEnd keep the range for the nodes..
// if the node has range in which updInd belongs.. only those will be updates.
// ind maintains the index in the segment tree for the updation
void updateST(int *stree,int sStart,int sEnd,int ind,int updInd,int diff)
{
	// if the index is out of the range then we wont update
	if(updInd > sEnd || updInd < sStart)
		return;

	// we have to update current node and we go further for other children nodes updation
	stree[ind] = stree[ind] + diff;		
	
	// this condition is for to handle the recursive calls
	// if both are same then we cant go further because it will be leaf level.
	if(sStart!=sEnd)
	{
		int mid = MID(sStart,sEnd);	// getting the middle index to call for two partitions
		updateST(stree,sStart,mid,2*ind+1,updInd,diff);	// update for partition 1
		updateST(stree,mid+1,sEnd,2*ind+2,updInd,diff);	// update for partition 2
	}
}

// wrapper function for updation
void updateSTWrapper(int *arr,int *stree,int n,int ind,int data)
{
	// checking the base range 
	if(ind<0 || ind>=n)
		return;
	
	int diff = data - arr[ind];		// taking the difference for the updation in the segment tree
	arr[ind] = data; 	// updation in the main array
	updateST(stree,0,n-1,0,ind,diff);		
}

// main function for sum
int getSum(int *stree,int sStart,int sEnd,int qStart,int qEnd,int ind)
{
	// if end of the query is less than start index of tree OR
	// if start of the query is greater than end index of tree
	if(qStart > sEnd || qEnd < sStart)
		return 0;

	// if the query range is in the range of the stree range	
	if(qStart <= sStart && qEnd >= sEnd)
		return stree[ind];
	
	// if both range are partially overlapping then... e.g. (1,4) with (3,6)	
	
	// find mid and break the stree from the middle
	int mid = MID(sStart,sEnd);
	
	// get sum of both the partition and return their sum
	return getSum(stree,sStart,mid,qStart,qEnd,2*ind+1) + getSum(stree,mid+1,sEnd,qStart,qEnd,2*ind+2);
}

// wrapper function for sum 
int getSumWrapper(int *stree,int n,int qStart,int qEnd)
{
	// base case for checking
	if(qStart < 0 || qEnd >= n || qStart > qEnd)
		return -1;
	
	// calling the main function for sum
	return getSum(stree,0,n-1,qStart,qEnd,0);
} 

// building the segment tree

// start and end sets the range for each node in the segment tree
// ind maintains the index in the segment tree..
int constructST(int *stree,int start,int end,int *arr,int ind)
{
	// this will be the leaf nodes
	if(start==end)
	{
		stree[ind] = arr[start];	
		return stree[ind];	
	}
	
	// for non-leaf nodes	
	int mid = MID(start,end);
	stree[ind] = constructST(stree,start,mid,arr,ind*2+1) + constructST(stree,mid+1,end,arr,ind*2+2);
	return stree[ind];
}

int *constructSTWrapper(int *arr,int n)
{
	// getting the height which is ceil of log2(n)
	int height = (int)ceil(log2(n));
	
	// set the size of the segment tree array
	int size = 2*(int)pow(2,height) - 1;
	int *stree = new int[size];

	// building the segment tree	
	constructST(stree,0,n-1,arr,0);

	cout << "segment tree : ";	
	for(int i=0;i<size;i++)
		cout << stree[i] << " ";
	cout << endl;
	
	return stree;
}

int main()
{
	int n,*A;
	cin >> n;
	
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];
		
	int *stree = constructSTWrapper(A,n);
	
	int qStart,qEnd;
	cin >> qStart >> qEnd;
	cout << getSumWrapper(stree,n,qStart,qEnd) << endl;
	
	int updInd,updData;
	cin >> updInd >> updData;
	updateSTWrapper(A,stree,n,updInd,updData);

	cin >> qStart >> qEnd;
	cout << getSumWrapper(stree,n,qStart,qEnd) << endl;
	
	return 0;
}
