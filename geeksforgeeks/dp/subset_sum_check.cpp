//==== SUBSET SUM PROBLEM

/*
Given a set of non-negative integers, and a value sum, determine if there is a
subset of the given set with sum equal to given sum.

Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

Logic :

// NICE LOGIC.. SAME AS CHECKING WHETHER given amount is possible using of given coins

Always subset with 0 sum is possible because empty set can generate 0 sum.
Take a boolean array with size same as given sum(S) let say isSum

Make isSum[0]=true

Take each element i in array
	loop through j as S-A[i] to 0 
		if isSum[j] is true
			isSum[j+A[i]]=true // if isSum[j] is true because of previous elements.. so if we add current element A[i] then
							   // sum will be possible after adding A[i] so make isSum[j+A[i]] true...
	check if isSum[S] is true
		print "yes" and break from the loop
			
if isSum[S] is false
	print "no"

TC : O(sum*n)
SC : O(sum)	// boolean array of size sum

*/

#include<iostream>
using namespace std;
int main()
{
	int n,*A,S;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	cin >> S;

	bool *sumPoss;
	sumPoss = new bool[S+1];
	// if sumPoss[i] is true then subset having sum i is possible else not possible

	sumPoss[0] = true;	// 0 sum is always possible because of empty set

	for(int i=1;i<=S;i++)	
		sumPoss[i] = false;	// initialize all other as false

	for(int i=0;i<n;i++)	// taking each element
	{
		for(int j=S-A[i];j>=0;j--)	// loop through S-A[i] to 0
			if(sumPoss[j])			// sumPoss[j] is true because previous elements 
				sumPoss[j+A[i]]=true;		// if we add current element then sum j+A[i] is possible so make isSum[j+A[i]] true 
		if(sumPoss[S])	// checking for our answer
		{
			cout << "Sum is possible" << endl;
			break;
		}
	}

	if(!sumPoss[S])	// we havent find the given sum
		cout << "Sum is not possible" << endl;		
	
	return 0;
}
