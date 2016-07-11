//===== OUTPUT TWO ELEMENTS WHOSE SUM IS CLOSEST TO 0

/*******

Given an array, output two elements whose sum is closest to 0.
e.g. 1 60 -10 70 -80 85
-80 85

Logic :
* Sort the array.
* set diff = INT_MAX
* Use the same logic as sum of two elements is x... Here x=0.
* Everytime check abs(sum) if it is lower then previous then update it and record both the index accordingly.

output A[i] and A[j]

TC : O(nlogn)
SC : O(1)

*******/

#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;


int compare (const void *a,const void *b)
{	return (*(int *)a) > (*(int *)b);	}

int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	qsort(A,n,sizeof(int),compare);

	int min,max,diff=INT_MAX,sum;
	for(int i=0,j=n-1;i<j;)
	{
		sum = A[i]+A[j];
		if(abs(sum)<abs(diff))
		{
			min=i;	// update i
			max=j;	// update j
			diff = abs(sum);	// update diff
		}
		if(sum<0)
			i++;
		else
			j--;
	}

	cout << A[min] << " " << A[max] << endl;

	return 0;
}
