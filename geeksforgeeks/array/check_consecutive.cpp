//===== CHECK WHETHER ARRAY ELEMENTS ARE CONSECUTIVE.

/******
Given an array, check whether elements are consecutive or not.
a) If array is {5, 2, 3, 1, 4}, then the function should return true because the array has consecutive numbers from 1 to 5.

b) If array is {83, 78, 80, 81, 79, 82}, then the function should return true because the array has consecutive numbers from 78 to 83.

c) If the array is {34, 23, 52, 12, 3 }, then the function should return false because the elements are not consecutive.

d) If the array is {7, 6, 5, 5, 3, 4}, then the function should return false because 5 and 5 are not consecutive.

Logic :
Find the min and max of the array and check with the size of the array... it should be (max-min+1).. if not then they are not consecutive.
if yes then
	use element-min as index and change the sign of the element at index.
	If it is already -ve then declare they are not consecutive because element is repeating.
	If no element found -ve while changing the sign then it is consecutive.

This method won't work for -ve/0 values in range. then you have to use sorting and check..

TC : O(n)
SC : O(1)

******/

#include<iostream>
#include<stdlib.h>
using namespace std;

// finding the min. of the array
int minArray(int *A,int n)
{
	int min=A[0];
	for(int i=1;i<n;i++)
		if(A[i]<min)
			min = A[i];
	return min;
}

// finding the max of the array...
int maxArray(int *A,int n)
{
	int max=A[0];
	for(int i=1;i<n;i++)
		if(A[i]>max)
			max = A[i];
	return max;
}

int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	int minVal = minArray(A,n);
	int maxVal = maxArray(A,n);

	bool done=true;
	if( (maxVal-minVal+1)==n)	// checking the size.. 
	{
		for(int i=0;i<n;i++)	
		{
			if( (abs(A[i])-minVal)>=0 && (abs(A[i])-minVal)<n && A[abs(A[i])-minVal]>0) // checking the bound and sign of the element
				A[abs(A[i])-minVal] = -A[abs(A[i])-minVal];	// changing the sign of the element.
			else
			{
				done = false;
				break;
			}
		}

	}
	else
		done = false;
				
	if(!done)
		cout << "no" << endl;
	else
		cout << "yes" << endl;

	return 0;
}
