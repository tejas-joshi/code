/********************************

Majority Element: A majority element in an
array A[] of size n is an element
that appears more than n/2 times
(and hence there is at most one such element).

Write a function which takes an array and
emits the majority element (if it exists),
otherwise prints NONE as follows:

       I/P : 3 3 4 2 4 4 2 4 4
       O/P : 4 

       I/P : 3 3 4 2 4 4 2 4
       O/P : NONE

**************************
* Moore’s Voting Algorithm
* 
This is a two step process.
1. Get an element occurring most of the time in the array.
   This phase will make sure that if there is a majority element then it will return that only.
2. Check if the element obtained from above step is majority element. 

********************************/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *A,n;

	// taking no. of elements.
	cin >> n;
	A = (int *)malloc(n*sizeof(int));

	// taking elements.
	for(int i=0;i<n;i++)
		cin >> A[i];

	int max_index=0,count=1;

	// This loop checks for majority element in array.
	for(int i=1;i<n;i++)
	{
		if(A[max_index]==A[i])
			count++;
		else if(count>0)
			count--;
		else
		{
			max_index=i;
			count=1;
		}	
	}

	// This loop makes sure that majority element
	// occurs more than (n/2) times.
	count=0;
	for(int i=0;i<n;i++)
		if(A[i]==A[max_index])
			count++;
		
	if(count>(n/2))
		cout << "Majority element is " << A[max_index] << endl;
	else
		cout << "There is no majority element." << endl;
	
	return 0;
}
