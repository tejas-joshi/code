//======== FIND MEDIAN OF TWO SORTED ARRAYS OF SAME SIZE...

/***
Given two sorted arrays of same size, find the median...
Logic :
Divide and conquer..
Check the median of each array and compare then take decision about the next partition need to be considered.
All are there in comments... Just understand very carefully....

TC : O(logn)
SC : O(1)
**/

#include<iostream>
using namespace std;

int median(int *arr,int n)
{
	if(n%2==0)	// even case... mean of middle elements.
		return (arr[n/2]+arr[n/2-1])/2;
	else		// odd case... middle element
		return arr[n/2];
}

// both the arrays and passing the size... the number of elements each array needs to be considered... 
// e.g. if n=3 then 3 elements in A and 3 elements in B.. both will be some/whole part of the original array...
int computeMedian(int *A,int *B,int n)
{
	if(n<=0)
		return -1;
	else if(n==1)	
		return (A[0]+B[0])/2;
	else if(n==2)	
		return (max(A[0],B[0]) + min(A[1],B[1]))/2;
	else
	{
		int m1 = median(A,n);
		int m2 = median(B,n);
		
		if(m1==m2)	// if both are same then return any of them
			return m1;

		if(m1<m2)	// m1<m2 means median is in higher part of A and lower part of B
		{
			if(n%2==0)	// even case .. take care about the parameters we are passing...
				return computeMedian(A+n/2-1,B,n-n/2+1);
			else		// odd case... take care about the parameters we are passing,
				return computeMedian(A+n/2,B,n-n/2);
		}
		else		// m1>m2 means median is in lower part of A and higher part of B
		{
			if(n%2==0)	// even case.... take care about the parameters we are passing... especially 1st and 2nd
				return computeMedian(B+n/2-1,A,n-n/2+1);
			else		// odd case... take care about the parameters we are passing...  especially 1st and 2nd..
				return computeMedian(B+n/2,A,n-n/2);
		}
	}
}

int main()
{	
	int n,*A,*B;
	cin >> n;
	A = new int[n];
	B = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];
	for(int i=0;i<n;i++)
		cin >> B[i];

	cout << computeMedian(A,B,n) << endl;	

	return 0;
}	
