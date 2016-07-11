//====== UNION AND INTERSECTION

/*****

Given two sorted arrays, output union and intersection.

Logic :
I don't think you need it... ;)... Comments please

******/


#include<iostream>
using namespace std;
int main()
{	
	int nA,nB;
	int *A,*B;
	
	cin >> nA;
	A = new int[nA];

	for(int i=0;i<nA;i++)
		cin >> A[i];

	cin >> nB;
	B = new int[nB];

	for(int i=0;i<nB;i++)
		cin >> B[i];

	int i=0,j=0;	
	while(i<nA && j<nB)
	{
		if(A[i]==B[j])	// same element .. print only one and increment both
		{
			cout << A[i] << " ";
			i++;
			j++;
		}
		else if(A[i]<B[j])	//  A[i] is lesser.. print it and increment i.
		{
			cout << A[i] << " ";
			i++;
		}
		else    // B[j] is lesser and increment j..
		{
			cout << B[j] << " ";
			j++;
		}
	}

	while(i<nA)
		cout << A[i++] << " ";
	while(j<nB)
		cout << B[j++] << " ";

	cout << endl;
	i=0,j=0;

	while(i<nA && j<nB)
	{
		if(A[i]==B[j])	// both are same ..print it and increment both..
		{
			cout << A[i] << " ";
			i++;
			j++;
		}
		else if(A[i]<B[j])   // A[i] is lesser ..increment i..
			i++;
		else       // B[j] is lesser ... increment j...
			j++;
	}
	cout << endl;
		
	return 0;
}
