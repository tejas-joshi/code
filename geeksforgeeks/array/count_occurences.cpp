//====== COUNT OCCURENCES IN SORTED ARRAY...

/******
Given a sorted array, count number of occurences of x in it.

Input: arr[] = {1, 1, 2, 2, 2, 2, 3} and   x = 2
Output: 4 // x (or 2) occurs 4 times in arr[]

Logic :
Find the number in array using binary search because array is sorted.
let say element is found at k and it will have low and high for that iteration.
Now find the index in left side i.e. between low and k ..say x..
Now find the index in right side i.e. between k and high .. say y
output : y-x+1... 

Look into code for more clarity...

TC : O(logn)
SC : O(1)
******/

#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int x;
	cin >> x;

	int low=0,high=n-1;
	bool found=false;
	while(low<=high)	//searching the element
	{
		int mid = low + (high-low)/2;
		if(A[mid]==x)	// found
		{
			found = true;
			int ind = mid;
			
			// Now we are going to find the boundaries in both the sides.

			// In left side we keep finding till A[leftlow]!=x and A[lefthigh]==x 
			// It will break when lefthigh is next to leftlow... 

			// searching left boundary...
			int leftlow = low;
			int lefthigh = mid;
			while( (lefthigh-leftlow)>1 )  
			{
				int m = leftlow + (lefthigh-leftlow)/2;
				if(A[m]==x)
					lefthigh=m;
				else 
					leftlow=m;
			}	
			if(A[leftlow]==x)	// if A[leftlow] itself is x
				lefthigh = leftlow;

			// In right side we keep finding till A[rightlow]==x and A[righthigh]!=x 
			// It will break when righthigh is next to rightlow... 

			// searching rightmost boundary
			int rightlow = ind;
			int righthigh = high;
			while( (righthigh-rightlow)>1)
			{
				int m = rightlow + (righthigh-rightlow)/2;
				if(A[m]==x)
					rightlow=m;
				else
					righthigh=m;
			}
			if(A[righthigh]==x)	// if A[righthigh] itself is x
				rightlow = righthigh;

			cout << rightlow-lefthigh+1 << endl;
			break;
		}
		else if(A[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}

	if(!found)
		cout << "element not found.. " << endl;
	return 0;
}
