//====== ROTATE THE MATRIX LEFT/RIGHT

/**

Given a matrix, rotate it left... It can be right...

The code given is for square matrix..

Logic :
Read the comments.. Awesome logic... 
Only square matrix can be rotated inplace..
For non-square matrix, we have to take another matrix and set the elements in it and print later on (NAIVE APPROACH).

TC : O(n^2) .. (for square matrix.. else m*n)
SC : O(1) for square matrix.
     O(mn) otherwise...

**/     

#include<iostream>
using namespace std;
int main()
{
	int n,**A;
	cin >> n;
	A = new int*[n];
	for(int i=0;i<n;i++)
		A[i] = new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> A[i][j];
	
	// inplace transpose -- mirror the matrix along the diagonal line
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			int temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}

	// horizontal mirroring for left rotation...LOVE THIS LOGIC
	for(int i=0;i<n/2;i++)
		for(int j=0;j<n;j++)
		{
			int temp = A[i][j];
			A[i][j] = A[n-i-1][j];
			A[n-i-1][j] = temp;
		}
/*
	// vertical mirroring for right rotation... LOVE THIS ALSO..
	for(int j=0;j<n/2;j++)
		for(int i=0;i<n;i++)
		{
			int temp = A[i][j];
			A[i][j] = A[i][n-j-1];
			A[i][n-j-1] = temp;
		}
*/

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	return 0;
}
