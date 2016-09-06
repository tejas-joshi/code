// FIND THE MAXIMUM OF WINDOW k 

/*
Logic :

Take dequeue of size k.
Use index of the array in the dequeue

From the front side.. take out the elements which are going out side the window.
From the back side.. take out the elements which are lesser than current element
Push the element to back
Front element is the answer.

Refer code for more clarity...

TC : O(n)
SC : O(k)

*/

#include<iostream>
#include<deque>
using namespace std;

void printMaxK(int *A,int n,int k)
{
	deque<int> Q;
	
	// for first k elements
	for(int i=0;i<k;i++)
	{
		// checking from the back side for the elements which are lesser than A[i]
		while(!Q.empty() && (A[Q.back()] <= A[i]))
			Q.pop_back();
		
		Q.push_back(i);
	}
	
	// for the rest of the elements of array
	// front element always hold the answer for window of size k
	for(int i=k;i<n;i++)
	{
		// printing the max element of window k
		cout << A[Q.front()] << " ";
		
		// checking from the front side for the elements which are going out of window
		while(!Q.empty() && (Q.front() <= (i-k)))
			Q.pop_front();
		
		// checking from back side for the elements which are lesser than A[i]
		while(!Q.empty() && (A[Q.back()] <= A[i]))
			Q.pop_back();
		
		// found the place for ith element... pushing back
		Q.push_back(i);
	}
	
	// printing the answer for the last window because we are printing element at the starting of the loop..
	// another reason is what if the last element is max. in the last window..
	cout << A[Q.front()] << endl;
}

int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	int k;
	cin >> k;
	
	printMaxK(A,n,k);
	
	return 0;
}
