//====== REVERSE AN ARRAY...

//YOU MUST BE KIDDING...

#include<iostream>
using namespace std;
int main()
{	
	int m;
	cin >> m;

	int *A;
	A = new int[m];

	for(int i=0;i<m;i++)
		cin >> A[i];

	for(int i=0,j=m-1;i<=j;i++,j--)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

	for(int i=0;i<m;i++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
