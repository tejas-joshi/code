// SEGMENT TREEE--- RANGE MINIMUM QUERY..

/*
TC : O(n) for tree construction (that is one time) 
     O(logn) // because of full BT height
SC : O(n)	 // taking extra array of size 2*(2^height)-1 where height = ceil(log2(n)) 	
*/


#include<iostream>
#include<math.h>
#include<limits.h>
#define MID(low,high) (low+(high-low)/2)
using namespace std;

// main function for finding min in the range
// sStart and sEnd maintains the range for each node in the segment tree
// ind maintains the index in the segment tree
int minST(int *stree,int sStart,int sEnd,int qStart,int qEnd,int ind)
{
	// checks for range
	if(qEnd < sStart || qStart > sEnd)
		return INT_MAX;
	
	// node range totally covers query range
	if(qStart <= sStart && sEnd <= qEnd)
		return stree[ind];
	
	// node range and query range partially overlaps.. so make two parititions.. and call for both.. and return minimum..
	int mid = MID(sStart,sEnd);
	return min(minST(stree,sStart,mid,qStart,qEnd,2*ind+1),minST(stree,mid+1,sEnd,qStart,qEnd,2*ind+2));
}


int minSTWrapper(int *stree,int size,int qStart,int qEnd)
{
	// base cases for range
	if(qStart < 0 || qEnd > size-1 || qStart > qEnd)
		return -1;
	
	return minST(stree,0,size-1,qStart,qEnd,0);
}


// sStart and sEnd maintains the range for each node
// ind maintains the index of the stree array
// arr is the index of the original array
int constructST(int *arr,int *stree,int sStart,int sEnd,int ind)
{
	// this is leaf node so value would be element itself. 
	if(sStart==sEnd)
	{
		stree[ind] = arr[sStart];
		return stree[ind];
	}
	
	// now internal nodes...  make two partition with half size ..and call for both.. and then take minimum
	int mid = MID(sStart,sEnd);
	stree[ind] = min(constructST(arr,stree,sStart,mid,2*ind+1),constructST(arr,stree,mid+1,sEnd,2*ind+2));
	return stree[ind];
}

// wrapper function for building the segment tree for RMQ
int *constructSTWrapper(int *A,int n)
{
	int height = (int)(ceil(log2(n)));
	int size = 2*(int)pow(2,height) - 1;
	int *stree = new int[size];
	
	constructST(A,stree,0,n-1,0);
	
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
	cout << minSTWrapper(stree,n,qStart,qEnd) << endl;
	
	return 0;
}
