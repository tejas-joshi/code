//=== FIND THE MINIMUM DISTANCE BETWEEN TWO ELEMENTS IN ARRAY

/*****
Given an array, find the minimum distance between two elements given.
Input: arr[] = {1, 2}, x = 1, y = 2
Output: Minimum distance between 1 and 2 is 1.

Input: arr[] = {3, 4, 5}, x = 3, y = 5
Output: Minimum distance between 3 and 5 is 2.

Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
Output: Minimum distance between 3 and 6 is 4.

Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
Output: Minimum distance between 3 and 2 is 1.

Logic :
Take a varialbe 'prev'
loop through all the elements 

If prev is -1 and element is either x or y then prev=current index.

If element is x and prev is also x then update the index of x as current index as we want the distance to be minimum.
If element is x and prev is y then update the diff if it is minimum.

Same for the cases when the element is y... 

output diff...
Look into code for more clarity...

TC : O(n)
SC : O(1)
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

	int x,y;
	cin >> x >> y;

	int prev=-1,diff=n+1;
	for(int i=0;i<n;i++)
	{
		if(A[i]==x)	// current element is x
		{
			if(prev==-1 || A[prev]==x)	// update prev
				prev=i;
			else if(A[prev]==y)		// element at prev is y and current is x so check the diff for minimum
				diff = min(i-prev,diff);
		}
		else if(A[i]==y)
		{
			if(prev==-1 || A[prev]==y)	// update prev
				prev=i;
			else if(A[prev]==x)		// element at prev is x and current is y so check the diff for minimum
				diff = min(i-prev,diff);
		}
	}
	cout << diff << endl;	

	return 0;
}
