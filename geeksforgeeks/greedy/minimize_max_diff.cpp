////=========== Minimize the maximum difference between the heights
/*
Given heights of n towers and a value k. We need to either increase or decrease height of every tower by k (only once) where k > 0. 
The task is to minimize the difference between the heights of the longest and the shortest tower after modifications, and output this difference.

Input  : arr[] = {1, 15, 10}, k = 6
Output : arr[] = {7, 9, 4}
         Maximum difference is 5.
Explanation : We change 1 to 6, 15 to 
9 and 10 to 4. Maximum difference is 5
(between 4 and 9). We can't get a lower
difference.

* Sort array in increasing order
* Initialize maximum and minimum elements.
	maxe = arr[n-1], mine = arr[0]
* If k is more than difference between maximum and minimum, add/subtract k to all elements as k cannot decrease the difference. Example {6, 4}, k = 10.
* In sorted array, update first and last elements.
	arr[0] += k; // arr[0] is minimum and k is +ve
	arr[n-1] -= k; // arr[n-1] is maximum and k is -ve
* Initialize max and min of modified array (only two elements have been finalized)
	new_max = max(arr[0], arr[n-1]), new_min = min(arr[0], arr[n-1])
* Finalize middle n-2 elements. Do following for every element arr[j] where j lies from 1 to n-2.
	If current element is less than min of modified array, add k.
	Else If current element is more than max of modified array, subtract k.
	arr[j] is between new_min and new_max.
	If arr[j] is closer to new_max, subtract k
	Else add k to arr[j].
* Update new_max and new_min if required
	new_max = max(arr[j], new_max), new_min = min(arr[j], new_min)
* Returns difference between new_max and new_min
	return (new_max – new_min);

TC : O(nlogn)

PS : This algo is giving wrong answer for 
k= 4 arr=[3,4,5,6,7,8]
Soln : [7,8,9,10,11,4] diff : 7
Correct :  [7,8,9,10,11,12] diff : 5
Check for correct soln and correct the algo.
	
*/


#include<iostream>
#include<algorithm>
using namespace std;

int getMinDiff(int *heights, int n, int d)
{
	if(n==1)
		return 0;
	
	sort(heights,heights+n);
	
	int currMin = heights[0];
	int currMax = heights[n-1];
	
	if(currMax-currMin <= d)
	{
		for(int i=0;i<n;i++)
			heights[i]=heights[i]+d;
		return currMax-currMin;
	}

	heights[0]=heights[0]+d;
	heights[n-1]=heights[n-1]-d;
	
	currMax=max(heights[0],heights[n-1]);
	currMin=min(heights[0],heights[n-1]);
	for(int j=1;j<n-1;j++)
	{
		if(heights[j]<currMin)
			heights[j]+=d;
		else if(heights[j]>currMax)
			heights[j]-=d;
		else if((currMax-heights[j])>(heights[j]-currMin))
			heights[j]+=d;
		else
			heights[j]-=d;
		currMin=min(currMin,heights[j]);
		currMax=max(currMax,heights[j]);
	}
	
	return currMax-currMin;
}

int main()
{
	int n,d;
	cin >> n >> d;
	
	int *heights = new int[n];
	for(int i=0;i<n;i++)
		cin >> heights[i];
	
	cout << getMinDiff(heights,n,d) << endl;
	
	for(int i=0;i<n;i++)
		cout << heights[i] << " ";
	cout << endl;
	
    return 0;
}