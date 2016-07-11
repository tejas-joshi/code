//=== FIND 4 ELEMENTS WHICH HAS SUM AS X

/*******
Logic :
Sort the array.
Use the same logic as 2 sum problem.
Set i and j... find rest of the sum in j to n-1 array...

TC : O(n^3)
SC : O(1)
********/


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
	
	int X;
	cin >> X;
	
	qsort(A,n,sizeof(int),compare);
	
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
		{
			int rem_sum = X - A[i] - A[j];
			int low=j+1,high=n-1;
			while(low<high)
			{
				if(A[low]+A[high]<rem_sum)
					low++;
				else if(A[low]+A[high]>rem_sum)
					high--;
				else
				{	
					cout << A[i] << " " << A[j] << " " << A[low] << " " << A[high] << endl;	
					break;
				}
			}	
		}

	return 0;
}
