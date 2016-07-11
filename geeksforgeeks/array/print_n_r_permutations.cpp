//=== Print all possible combinations of r elements in a given array of size n

/**
 * 
 * Given an array of size n, generate and print all possible combinations of r elements in array. 
 * For example, if input array is {1, 2, 3, 4} and r is 2, then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.

Logic 1:
* In the comments
* 

Logic 2:	( code to handle the duplicates is also included. )
* 
* Use the logic of 0-1 Knapsack problem.
* Either you add the element or not.
* 	If you add the element then increment the index of P
* 	else keep the index same and 
* 	
* 	Code is here for reference
* 	==========================
* 
	void combinationUtil(int arr[], int n, int r, int index, int data[], int i)
	{
		// Current cobination is ready, print it
		if (index == r)
		{
			for (int j=0; j<r; j++)
				printf("%d ",data[j]);
			printf("\n");
			return;
		}

		// When no more elements are there to put in data[]
		if (i >= n)
			return;

		// current is included, put next at next location
		data[index] = arr[i];
		combinationUtil(arr, n, r, index+1, data, i+1);

		// Add this to code if you want to remove duplicates
		//	while (arr[i] == arr[i+1])
		//		i++;

		// current is excluded, replace it with next (Note that
		// i+1 is passed, but index is not changed)
		combinationUtil(arr, n, r, index, data, i+1);
	}

**/

#include<iostream>
using namespace std;

/*
	start & end ---> Staring and Ending indexes in A[]
	index  ---> Current index in P[].. or you can say the number of elements filled up in permutation
	r ---> Size of a combination to be printed 
*/

void printRNPerm(int *P,int *A,int start,int end,int index,int r) 	
{
	if(index==r)
	{
		for(int i=0;i<r;i++)
			cout << P[i] << " ";
		cout << endl;
		return;
	}

	// replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    // i.e. let say there are 5 elements remaining in the main array and you have 6 elements remaining for
    // permutaion then we should not add elements in the P array

	for(int i=start;i<=end && end-i+1>=r-index;i++)	
	{
		P[index] = A[i];
		printRNPerm(P,A,i+1,end,index+1,r);
	}
}	

void permWrapper(int *A,int n,int r)
{
	int P[n];	// array to store the combination
	
	printRNPerm(P,A,0,n-1,0,r);
}

int main()
{
	int n,*A,r;
	cin >> n >> r;
	
	A = new int[n];
	
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	permWrapper(A,n,r);
	
	return 0;
}
