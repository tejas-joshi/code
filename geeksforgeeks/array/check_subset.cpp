//====== CHECK WHETHER B IS SUBSET OF A

/****
Given two arrays A and B, check whether B is subset of A.
Logic :
Sort A.
Check each element of B in A using binary search.
If all found then B is subset of A else not.

TC : O(nlogn + mlogn) = O(nlogn)	(because n>m) // n is size of A and m is size of B
SC : O(1)

You can also try by sorting both the arrays and using merge logic. That way also the complexity will be same.
TC will be O(nlogn + mlogm + m + n) 
******/

#include<iostream>
#include<stdlib.h>

int compare(const void *a,const void *b)
{	return (*(int *)a) > (*(int *)b);	}

using namespace std;
int main()
{
	int n,*A;
	int m,*B;
	
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	cin >> m;
	B = new int[m];
	for(int i=0;i<m;i++)
		cin >> B[i];
	
	qsort(A,n,sizeof(int),compare);

	bool found=false;
	for(int i=0;i<m;i++) // loop through each element of B
	{
		int elem = B[i];
		int low=0,high=n-1;
		found=false;
		while(low<=high)	// binary search in A
		{
			int mid = low + (high-low)/2;
			if(A[mid]==elem)
			{
				found = true;
				break;
			}
			else if(A[mid]<elem)
				low = mid+1;
			else
				high = mid-1;
		}

		if(!found) 	// element not found in A
		{
			cout << "B is not subset of A " << endl;
			break;
		}
	}

	if(found)	// all elements found in A
		cout << "B is subset of A " << endl;	

	return 0;
}
