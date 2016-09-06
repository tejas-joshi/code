//===== K’th Smallest/Largest Element in Unsorted Array

/*******

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 3
Output: 7

Using MinHeap/MaxHeap, TC will be O(nlogk).


In QuickSort, we pick a pivot element, then move the pivot element to its correct position and partition the array around it. 
The idea is, not to do complete quicksort, but stop at the point where pivot itself is k’th smallest element. 
Also, not to recur for both left and right sides of pivot, but recur for one of them according to the position of pivot. 
The worst case time complexity of this method is O(n^2), but it works in O(n) on average.


TC : O(n)

*******/

#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Randomize quickselect is having the TC :O(n)
// Just to randomize the selection of pivot point
// Picks a random pivot element between l and r and partitions
// arr[l..r] arount the randomly picked element using partition()
int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}

// normal quick sort partition logic
int partition(int *arr,int low, int high)
{
	int x = arr[high],i=low;
	for(int j=low;j<=high-1;j++)
	{
		if(arr[j]<=x)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[high]);
	return i;
}

int kthSmallest(int *arr,int low, int high,int k)
{
	// checking bounds of k
	if(k>0 && k<=(high-low+1))	
	{
		int ind = partition(arr,low,high);
		
		if(ind-low==k-1) // kth position found
			return arr[ind];
		else if(ind-low > (k-1)) // k is left side of pivot position so calling left partition
			return kthSmallest(arr,low,ind-1,k);
		else	// k is on the right side of pivot so calling right partition
			return kthSmallest(arr,ind+1,high,k-ind+low-1);
	}
	return INT_MAX;
}

int main()
{
	int n,*A,k;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];
	cin >> k;
	
	cout << kthSmallest(A,0,n-1,k) << endl;	

	return 0;
}
