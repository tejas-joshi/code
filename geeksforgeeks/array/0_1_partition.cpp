//====== PARTITION THE ARRAY INTO 0s AND 1s ..(SEGREGATE 0s AND 1s)

/******

Given an array containing 0s and 1s, partition the arrays of 0 and 1.
i.e. all 0s on left side and 1s on right side.
 
Logic :
* Take two indexes i and j... i=0 and j=n-1
* Keep incrementing i till A[i]==0
* Keep decrementing j till A[j]==1
* else swap them... continue this till i<j.

TC : O(n)
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

	for(int i=0,j=n-1;i<j;)
	{
		if(A[i]==0)
			i++;
		else if(A[j]==1)
			j--;
		else
		{
			A[i++]=0;
			A[j--]=1;
		}
	}

	for(int i=0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
