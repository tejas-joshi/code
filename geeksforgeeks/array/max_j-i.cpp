//====== maximum j – i such that arr[j] > arr[i]

/***
Given an array find the max j-i such that arr[j]>arr[i]

Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 6  (j = 7, i = 1)

Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
Output: 8 ( j = 8, i = 0)

Input:  {1, 2, 3, 4, 5, 6}
Output: 5  (j = 5, i = 0)

Input:  {6, 5, 4, 3, 2, 1}
Output: -1 

Logic :
To solve this problem, we need to get two optimum indexes of arr[]: left index i and right index j. 
For an element arr[i], we do not need to consider arr[i] for left index if there is an element smaller than arr[i] on left side of arr[i]. 
Similarly, if there is a greater element on right side of arr[j] then we do not need to consider this j for right index. 
So we construct two auxiliary arrays LMin[] and RMax[] such that LMin[i] holds the smallest element on left side of arr[i] 
including arr[i], and RMax[j] holds the greatest element on right side of arr[j] including arr[j]. 
After constructing these two auxiliary arrays, we traverse both of these arrays from left to right. 
While traversing LMin[] and RMax[] if we see that LMin[i] is greater than RMax[j], 
then we must move ahead in LMin[] (or do i++) because all elements on left of LMin[i] are greater than or equal to LMin[i]. 
Otherwise we must move ahead in RMax[j] to look for a greater j – i value.

TC : O(n)
SC : O(n)

***/

#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int *LMin,*RMax;
	LMin = new int[n];
	RMax = new int[n];

	LMin[0] = A[0];
	for(int i=1;i<n;i++)
		LMin[i] = min(LMin[i-1],A[i]);

	RMax[n-1] = A[n-1];
	for(int i=n-2;i>=0;i--)
		RMax[i] = max(RMax[i+1],A[i]);

	int i=0,j=0,diff=-1;
	while(i<n && j<n)
	{
		if(LMin[i]<RMax[j])
		{
			diff = max(diff,j-i);
			j++;
		}
		else
			i++;
	}

	cout << diff << endl;


	return 0;
}
