//==== COUNT NUMBER OF INVERSIONS IN THE ARRAY

/****
Given an array, count inversions in the array.
Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If array is already sorted then inversion count is 0. 
If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Logic :
Divide and conquer is used to solve this problem.
Use the logic of merge sort and especially while merging, we are going to count number of inversions.

In merge process, let i is used for indexing left sub-array and j for right sub-array. 
At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. 
because left and right subarrays are sorted, 
so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

TC : O(nlogn)
SC : O(n)
****/

#include<iostream>
using namespace std;

int merge(int *temp,int *A,int left,int mid,int right)
{
	int inv_count=0;
	int i=left,j=mid,k=left;	// i for left parition, j for right partition, k for temp array indexing
	while(i<=mid-1 && j<=right)	// take care of conditions.
	{
		if(A[i]<=A[j])		
			temp[k++]=A[i++];
		else
		{
			temp[k++]=A[j++];
			inv_count = inv_count + (mid-i);			
		}
	}

	while(i<=(mid-1))
		temp[k++] = A[i++];
	while(j<=right)
		temp[k++] = A[j++];

	for(int i=left;i<=right;i++)
		A[i] = temp[i];
	return inv_count;
}

int divide(int *temp,int *A,int left,int right)
{
	int inv_count=0;
	if(left<right)
	{
		int mid = (left+right)/2;
		
		// inversions in left partition
		inv_count = inv_count + divide(temp,A,left,mid);

		// inversions in right partition
		inv_count = inv_count + divide(temp,A,mid+1,right);

		// inversions while merging left and right partition
		inv_count = inv_count + merge(temp,A,left,mid+1,right);
	}
	return inv_count;
}

int countInv(int *A,int n)
{
	int *temp = new int[n];
	return divide(temp,A,0,n-1);
}

int main()
{		
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];
	cout << countInv(A,n) << endl;


	return 0;
}
