//==== FIND MIN AND MAX OF ARRAY IN MINIMUM COMPARISONS

/****
Logic :
If n is odd then initialize min and max as first element.
If n is even then initialize min and max as minimum and maximum of the first two elements respectively.
For rest of the elements, pick them in pairs and compare their
maximum and minimum with max and min respectively.

Total number of comparisons: Different for even and odd n, see below:

If n is odd:    3*(n-1)/2  ( 3 comparisons for each pair so 3 comparisons for (n-1)/2 ... no comparison for first one.. so n-1.) 
If n is even:   1 Initial comparison for initializing min and max,
   		( 3 comparisons for each pair in (n-2) elements so 3(n-2)/2 and 1 for first pair..)
	        and 3(n-2)/2 comparisons for rest of the elements  
	        =  1 + 3*(n-2)/2 = 3n/2-2

This can also be solved using divide and conquer method:
-------------------------------------------------------
Pair MaxMin(array, array_size)
   if array_size = 1
         return element as both max and min
   else if arry_size = 2
          one comparison to determine max and min
	        return that pair
   else    // array_size  > 2 
      recur for max and min of left half
      recur for max and min of right half
         one comparison determines true max of the two candidates
        one comparison determines true min of the two candidates
      return the pair of max and min

T(2) = 1
T(1) = 0

If n is a power of 2, then we can write T(n) as:
T(n) = 2T(n/2) + 2 
After solving above recursion, we get

T(n)  = 3/2n -2 

Thus, the approach does 3/2n -2 comparisons if n is a power of 2. And it does more than 3/2n -2 comparisons if n is not a power of 2.

*****/
#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int minVal,maxVal,i;
	if(n%2)
	{
		minVal = A[0];
		maxVal = A[0];
		i=1;
	}
	else
	{
		if(A[0]>A[1])
		{
			minVal = A[1];
			maxVal = A[0];
		}
		else
		{
			minVal = A[0];
			maxVal = A[1];
		}
		i=2;
	}

	while(i<n-1)
	{
		if(A[i]>A[i+1])
		{
			if(A[i]>maxVal)
				maxVal = A[i];
			if(A[i+1]<minVal)
				minVal = A[i+1];
		}
		else
		{
			if(A[i+1]>maxVal)
				maxVal = A[i+1];
			if(A[i]<minVal)
				minVal = A[i];
		}
		i=i+2;
	}

	cout << minVal << " " << maxVal << endl;

	return 0;
}
