//=== Maximum Sum Path in Two Arrays
/**
Given two sorted arrays such the arrays may have some common elements. 
Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. 
We can switch from one array to another array only at common elements.

Input:  ar1[] = {2, 3, 7, 10, 12}, ar2[] = {1, 5, 7, 8}
Output: 35
35 is sum of 1 + 5 + 7 + 10 + 12.

1) Initialize result as 0. Also initialize two variables sum1 and sum2 as 0. 
Here sum1 and sum2 are used to store sum of element in ar1[] and ar2[] respectively. 
These sums are between two common points.

2) Now run a loop to traverse elements of both arrays. While traversing compare current elements of ar1[] and ar2[].
    2.a) If current element of ar1[] is smaller than current element of ar2[], then update sum1, else if current element of ar2[] is smaller, then update sum2.
    2.b) If current element of ar1[] and ar2[] are same, then take the maximum of sum1 and sum2 and add it to the result. Also add the common element to the result.

TC : O(m+n)
SC : O(1)

**/


#include<iostream>
#include<limits.h>
using namespace std;

int main()
{	
	int m,n,*A,*B;
	cin >> m >> n;
	A = new int[m];
	for(int i=0;i<m;i++)
		cin >> A[i];
	B = new int[n];
	for(int i=0;i<n;i++)
		cin >> B[i];

	int first=0,second=0;
	
	int sumA=0,sumB=0,maxSum=0;

	while(first<m && second<n)
	{
		if(A[first] < B[second]) // moving first array ahead
			sumA = sumA + A[first++];
		else if(A[first] > B[second]) // moving second array ahead
			sumB = sumB + B[second++];	
		else	// moving both the array ahead
		{
			maxSum = maxSum + max(sumA,sumB) + A[first++];
			second++;
			sumA = sumB = 0;
		}
	}
	
	while(first<m) // add the rest of the elements of first array
		sumA = sumA + A[first++];
	while(second<n) // add the rest of the elements of second array
		sumB = sumB + B[second++];
	
	maxSum = maxSum + max(sumA,sumB);
	cout << maxSum << endl;
	
	return 0;	
}
