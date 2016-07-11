/**************************************

Write a C program that, given an array A[] of n numbers and another number x,
determines whether or not there exist two elements in S whose sum is exactly x. 


LOGIC :
*
* 1) SORT THE ARRAY.
* 2) START i FROM 0 AND j FROM n-1.
*    CHECK FOR SUM OF BOTH ELEMENTS.
*    IF IT'S THERE
* 			DONE
* 	 ELSE IF (SUM>X)
*   		// WE NEED BIG ELEMENT TO MAKE SUM X SO WE MOVE i TO NEXT TO TAKE NEXT BIGGEST.
* 	 ELSE
* 			// NOW WE NEED SMALL ELEMENT TO MAKE SUM SMALLER SO WE MOVE j TO NEXT SMALLEST.
* 
*****************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;

int compare( const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{	
	int *A,n,X;
	cin >> n >> X;
	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

	// SORT THE ARRAY
	qsort(A,n,sizeof(int),compare);

	bool avail=false;
	for(int i=0,j=n-1;i<j;)
	{
		if(A[i]+A[j]==X)	// WE GOT THE SUM
		{
			cout << "Sum exists." << endl;
			avail=true;
			break;
		}
		
		else if(A[i]+A[j] < X)	// WE NEED BIGGER ELEMENT SO MOVE TO NEXT BIGGER ELEMENT.
			i++;	
		else                    // WE NEED SMALLER ELEMENT SO MOVE TO NEXT SMALLEST ELEMENT
			j--;
	}
	
	if(!avail)
		cout << "Sum does not exist." << endl;

	return 0;
}
