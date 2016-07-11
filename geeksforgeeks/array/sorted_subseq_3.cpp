//==== FIND THE SORTED SUBSEQUENCE OF SIZE 3 

/********
Given an unsorted array, output the sorted subsequence of size 3.
Logic :
Take auxiliary array of size n.. (minS) minS[i] which contains the index of the element which is lesser than A[i] on left side.
Take auxiliary array of size n.. (maxS) maxS[i] which contains the index of the element which is greater than A[i] on right side.
Loop throuugh 0 to n-1... print the element A[minS[i]] A[i] A[maxS[i]] when minS[i] and maxS[i] are not -1...
TC : O(n)
SC : O(n)
* 
* 
* Another logic is to use the strategy of LIS (nlogk) and when you find the vector size 3..
* 	print the solution. this way 
* 		TC : O(nlogk) --> O(nlog3) --> O(n) (we are exiting the loop when sequence reaches 3)
*		SC : O(n) -> for the vector who takes care of the sequence (vector P if you know)
* 			 O(1) -> only 3 elements will be there in vector.	(vector B if you know)
* 		     ----
* 			 O(n) 	
********/

#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int *minS,*maxS;
	minS = new int[n];
	maxS = new int[n];
	
	// filling the array minS
	int minInd = 0;
	minS[0] = -1;
	for(int i=1;i<n;i++)
	{
		if(A[i]<A[minInd])
		{
			minS[i] = -1;
			minInd = i;
		}
		else
			minS[i] = minInd;
	}

	// filling the array maxS
	int maxInd=n-1;
	maxS[n-1]=-1;
	for(int i=n-2;i>=0;i--)
	{
		if(A[i]>A[maxInd])
		{
			maxS[i] = -1;
			maxInd = i;
		}
		else
			maxS[i] = maxInd;
	}

	// print the answer by making sure that minS[i]!=-1 and maxS[i]!=-1...
	for(int i=0;i<n;i++)
		if(minS[i]!=-1 && maxS[i]!=-1)
			cout << A[minS[i]] << " " << A[i] << " " << A[maxS[i]] << endl;
	
	return 0;
}
