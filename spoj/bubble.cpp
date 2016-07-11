#include<iostream>
using namespace std;
int main()
{
	int A[82];
	int n=82;
	for(int i=0;i<n;i++)
		cin >> A[i];

	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i;j++)
			if(A[j]>A[j+1])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}

	for(int i=0;i<n;i++)
		cout << A[i] << endl;
}
