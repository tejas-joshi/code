//===== Find k closest elements to a given value

/*******

Given a sorted array arr[] and a value X, find the k closest elements to X in arr[]. 

Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}
Output: 30 39 42 45    (if X is available in the array then dont include in these elements)

Logic :
* Search the crossover point using binary search. (The point before which elements are smaller than or equal to X and after which elements are greater)
* Once we find the crossover point, we can compare elements on both sides of crossover point to print k closest elements. This step takes O(k) time.

TC : O(logn + k)
SC : O(1)

*******/

#include<iostream>
using namespace std;

int findCrossOverPoint(int *arr,int low,int high,int x)
{
	if(arr[high]<=x)
		return high;
	if(arr[low]>x)
		return low;
	
	int mid = low + (high-low)/2;
	
	if(arr[mid]<=x && x<arr[mid+1])
		return mid;
	
	if(arr[mid]<x)
		return findCrossOverPoint(arr,mid+1,high,x);
	else
		return findCrossOverPoint(arr,low,mid-1,x);
}

int printKClosest(int *arr,int n,int x,int k)
{
	int low = findCrossOverPoint(arr,0,n-1,x);
	int high = low+1;
	if(arr[low]==x)
		low--;	
	
	int count=0;
	while(low>=0 && high<n && count<k)
	{
		if(x-arr[low] > arr[high]-x)
			cout << arr[high++] << " ";
		else
			cout << arr[low--] << " ";
		count++;
	}
	
	while(count<k && low>=0)
	{	
		cout << arr[low--] << " ";
		count++;
	}
	
	while(count<k && high<n)
	{
		cout << arr[high++] << " ";
		count++;
	}
}

int main()
{
	int n,*A,x,k;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];
	cin >> x >> k;
	
	printKClosest(A,n,x,k);

	return 0;
}
