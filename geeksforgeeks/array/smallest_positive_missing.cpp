//======== FIND THE SMALLEST POSITIVE NUMBER MISSING FROM UNSORTED ARRAY

/****
Given an unsorted array, output the smallest positive number which is missing...
Logic :
Partition (-ve and 0) and +ve values on separate sides. i.e. -ve on left side and +ve on right side. 
	This will take O(n) time.
Now ignore the -ve and 0 from the array. 
Start from the index where +ve numbers start.
and change the sign of the element at that index. (Take an offset for -ve and 0 elements)
Now traverse the array again for +ve values.
If found then output the index+1... that will be the number which is missing because that is the number which was not referenced in array...

TC : O(n)
SC : O(1)

********/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	// partition -ve and +ve numbers in array... 
	// countNeg contains the number of -ve and 0s in array. that will help for taking offset for +ve numbers.
	int posI=n-1,negI=0,countNeg=0;
	while(negI<posI)
	{
		while(A[negI]<=0)
		{
			countNeg++;
			negI++;
		}
		while(A[posI]>0)
			posI--;
		if(negI<posI)
		{
			int temp = A[negI];
			A[negI] = A[posI];
			A[posI] = temp;
			negI++;
			posI--;
			countNeg++;
		}
	}

	// start from countNeg which is offset... change the sign of each element if it is in limit...
	for(int i=countNeg;i<n;i++)	// loop through offset to n...
		if((abs(A[i])-1)<(n-countNeg))	// checking the limit...
			A[abs(A[i])+countNeg-1] = -A[abs(A[i])+countNeg-1];	// changing the sign
	
	for(int i=countNeg;i<n;i++)	
		if(A[i]>0)	// check for +ve numbers
		{
			cout << (i-countNeg)+1 << endl; 
			break;
		}
	return 0;
}
