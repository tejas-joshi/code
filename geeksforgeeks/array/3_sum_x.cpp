//====== FIND THE TRIPLET WHICH HAS SUM AS X

/********
Given an array, find the triplet which has the sum as x.

Logic :
Sort the array.
i from 0 to n-3
Use the same logic as 2 sum problem for i+1 to n-1 for rest of the sum(x-A[i]).

TC : O(n^2)
SC : O(1)
*********/
 
#include<iostream>
#include<stdlib.h>
using namespace std;

int compare (const void *a,const void *b)
{
	return (*(int *)a) > (*(int *)b);
}

int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	qsort(A,n,sizeof(int),compare);

	int x;
	cin >> x;

	int diff,sum;	
	bool found = false;
	for(int i=0;i<n-2;i++)
	{
		diff = x - A[i];
		int low=i+1,high=n-1;
		while(low<high)
		{
			sum = A[low] + A[high];
			if(sum==diff)
			{
				found = true;
				cout << A[i] << " " << A[low] << " " << A[high] << endl;
				break;
			}
			else if(sum<diff)
				low++;
			else
				high--;
		}
	}

	if(!found)
		cout << "not found" << endl;
		
	return 0;
}
