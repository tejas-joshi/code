//===== CHECK MAJORITY ELEMENT IN A SORTED ARRAY

/*******

Given a sorted array, check whether x is majority element.
x is majority element if x is there in array more than (n/2) times.

Logic :
* Find x using binary search.
	If x is not found then print "not found"
	else
	* find lower bound of x using binary search. (min)
	* find higher bound of x using binary search. (max)
	* Check whether (max-min-1 > n/2).. If true then x is majority element otherwise not...

TC : O(logn)
SC : O(1)

*******/
	

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

	int low=0,high=n-1,mid,min,max;
	bool found=false;
	while(low<=high)	// search x
	{
		mid = low + (high-low)/2;
		if(A[mid]==x)
		{
			found=true;
			break;
		}
		else if(A[mid]<x)
			low = mid+1;
		else
			high = mid-1;
	}
	
	int ind = mid;
	if(found)
	{
		low=0,high=ind;
		while(low<=high)	// find lower bound of x
		{
			mid = low + (high-low)/2;
			if(A[mid]==x)
				high=mid-1;
			else
				low=mid+1;
		}
		min = high;	
		
		low=ind,high=n-1;
		while(low<=high)	// find upper bound of x
		{	
			mid = low + (high-low)/2;
			if(A[mid]==x)
				low=mid+1;
			else
				high=mid-1;
		}
		max = low;
	
		//cout << max-min-1 << endl;	// no. of occurences of x
		if((max-min-1)>(n/2))	// check whether x is majority element
			cout << x << " is majority element." << endl;
		else
			cout << x << " is not majority element." << endl;
	}	
	else
		cout << "Not found.." << endl;
	
	return 0;
}
