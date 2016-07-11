//=== SORT THE ARRAY 0s, 1s and 2s...

/**
Given an array of 0s,1s and 2s. Sort the array 
	i.e. <all 0s> <all 1s> <all 2s>
This is — Dutch National Flag Algorithm, or 3-way Partitioning —

AWESOME LOGIC... MAZA AA GAYA...

You have 10 seconds to think about the solution... If you got it then WOW... 

Logic:
take 3 variables low,mid and high

low holds the index for next 0
mid holds the index for next 1
high holds the index for next 2

initially low=0,mid=0 and high=n-1
i.e. we partition the array for indexing 0s and 1s in forward way and for 2s it will be backward way.

code:
while(mid<=high)
	if A[mid] is 0
		swap low and mid .. increment both low and mid.
	if A[mid] is 1
		increment mid because mid contains the next position for 1
	if A[mid] is 2 
		swap mid and high... decrement high.. nothing to do with mid

Understand the code very carefully even if it is the same as the logic explained above...

MAST LOGIC... HATS OFF... <3

TC : O(n)
SC : O(1)

**/


#include<iostream>
using namespace std;

int swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

int main()
{	
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int low=0,mid=0,high=n-1;
	while(mid<=high)
	{
		switch(A[mid])
		{
			case 0:
				swap(&A[low++],&A[mid++]);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(&A[mid],&A[high--]);
				break;
		}
	}

	for(int i=0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;	
}
