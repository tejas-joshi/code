//======= FLOOR-CEILING

/***********
Given an array, print floor and celing of an element

For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    floor doesn't exist in array,  ceil  = 1
For x = 1:    floor  = 1,  ceil  = 1
For x = 5:    floor  = 2,  ceil  = 8
For x = 20:   floor  = 19,  ceil doesn't exist in array

Logic :
* Use Binary search
* if element is searched then
	floor=ceiling=x
  else if (middle element < x )
     update floor = middle element
  else
	 update ceiling = middle element

Take two boolean variable to check whether floor and ceiling has been updated atleast once.
If false then "NO" else print corresponding value..

TC : O(log n)
SC : O(1)
***********/	 

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
	int ceil,floor;
	bool cBool=false,fBool=false;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(A[mid]==x)
		{
			fBool=cBool=true;	// same element so floor and ceiling exists
			floor = ceil = x;	// updating floor and ceiling
			break;
		}
		else if(A[mid]<x)
		{
			fBool = true;		// floor exists
			floor = A[mid];		// updating floor
			low=mid+1;
		}
		else
		{
			cBool = true;		// ceiling exists
			ceil = A[mid];		// updating ceiling
			high=mid-1;
		}
	}

	fBool?(cout << floor << " "):(cout << "NO" << " ");		// printing floor
	cBool?(cout << ceil << endl):(cout << "NO" << endl);	// printing ceiling
	
	return 0;
}
