//===== Count all distinct pairs with difference equal to k

/*******
Given an integer array and a positive integer k, count all distinct pairs with difference equal to k.

Input: arr[] = {1, 5, 3, 4, 2}, k = 3
Output: 2
There are 2 pairs with difference 3, the pairs are {1, 4} and {5, 2} 

Input: arr[] = {8, 12, 16, 4, 0, 20}, k = 4
Output: 5
There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, 
{8, 12}, {12, 16} and {16, 20} 

TC : O(nlogn)
SC : O(1)

==========
We can also use hashing to achieve the average time complexity as O(n) for many cases.

1) Initialize count as 0.
2) Insert all distinct elements of arr[] in a hash map.  While inserting, 
   ignore an element if already present in the hash map.
3) Do following for each element arr[i].
   a) Look for arr[i] + k in the hash map, if found then increment count.
   b) Look for arr[i] - k in the hash map, if found then increment count.
   c) Remove arr[i] from hash table. 
  
TC : O(n)

*******/

#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

// Using sorting
int getPairCount(int *arr, int n, int k)
{
	int count=0;
	sort(arr,arr+n);
	
	int low=0,high=0;
	
	while(low<n && high<n)
	{
		if(arr[high]-arr[low] == k)
		{
			count++;
			low++;
			high++;
		}
		else if(arr[high]-arr[low] > k)
			low++;
		else
			high++;
	}
	return count;
}

// Using hashing
#define MAX 100000
int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;  // Initialize count
 
    // Initialize empty hashmap.
    bool hashmap[MAX] = {false};
 
    // Insert array elements to hashmap
    for (int i = 0; i < n; i++)
        hashmap[arr[i]] = true;
 
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (x - k >= 0 && hashmap[x - k])
            count++;
        if (x + k < MAX && hashmap[x + k])
            count++;
        hashmap[x] = false;
    }
    return count;
}