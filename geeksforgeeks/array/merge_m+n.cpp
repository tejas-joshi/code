// === MERGE TWO ARRAYS INPLACE

/**********

A is of length m
B is of length m+n in which only n elements are valid otherwise -1.
Both are sorted.
Merge A and B into B..

4
5 8 12 14
3
2 -1 7 -1 -1 10 -1

o/p : 2 5 7 8 10 12 14

TC : O(m+n)
SC : O(1)

*********/


#include<iostream>
using namespace std;
int main()
{
	int *A,*B;
	int m,n;
	
	cin >> m;
	A = new int[m];

	for(int i=0;i<m;i++)
		cin >> A[i];

	cin >> n;
	B = new int[m+n];

	for(int i=0;i<(m+n);i++)	// invalid entries as -1...
		cin >> B[i];

	int j=0;
	for(int i=0;i<(m+n);i++)	// take all the valid into front side
		if(B[i]!=-1)
		{
			int temp = B[i];
			B[i] = B[j];
			B[j] = temp;
			j++;			
		}

	if(j>0)
		j=j-1;
		
	for(int i=(m+n)-1,k=m-1;i>=0,k>=0;i--)	// merge both the arrays from back side.. 
		if(B[j]>A[k])
			B[i] = B[j--];
		else
			B[i] = A[k--];

	for(int i=0;i<(m+n);i++)
		cout << B[i] << " ";
	cout << endl;

	return 0;
}
