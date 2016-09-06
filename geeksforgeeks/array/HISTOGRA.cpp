//=== FIND THE MAXIMUM RECTANGULAR AREA FROM THE HISTOGRAM... 
//- .. e.g. the poster problem of mooshak

/*

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
* For simplicity, assume that all bars have same width and the width is 1 unit.

For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 2, 6}. 
* The largest possible rectangle possible is 14

Logic:
* 
* We traverse the array two times and maintain two arrays 
* 	1) Left to Right - to maintain the index in the left to current element till which I can extend from this index
*   2) Right to Left - to maintain the index in the right to current element till which I can extend from this index

Finally I traverse both these arrays together to find the maximum area that can be covered by considering left and right extension.
* Max. area will be the answer.

*/

#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
int main()
{
	long long A[100001],N,max=0,total,leftA[100001],rightA[100001];
	int i;

	cin >> N;

	stack<long long> S;
	max=0;	

	for(i=0;i<N;i++)
	{
		cin >> A[i];
		leftA[i]=rightA[i]=-1;
	}	

	for(i=0;i<N;i++)
	{
		while(!S.empty() && A[S.top()]>A[i])
		{
			leftA[S.top()]=i-1;
			S.pop();
		}
		S.push(i);		
	}
	
	for(i=0;i<N;i++)
		if(leftA[i]==-1)
			leftA[i]=N-1;
	
	for(int i=0;i<N;i++)
		cout << leftA[i] << " ";
	cout << endl;
	
	while(!S.empty())
		S.pop();	
		
	for(i=N-1;i>=0;i--)
	{
		while(!S.empty() && A[S.top()]>A[i])
		{
			rightA[S.top()]=i+1;
			S.pop();
		}
		S.push(i);
	}

	for(i=0;i<N;i++)
		if(rightA[i]==-1)
			rightA[i]=0;

	for(int i=0;i<N;i++)
		cout << rightA[i] << " ";
	cout << endl;


	for(i=0;i<N;i++)
	{
		total = (leftA[i]-rightA[i]+1)*A[i];
		if(total>max)
			max = total;
	}
		
	cout << max << endl;
	
	return 0;	
}
