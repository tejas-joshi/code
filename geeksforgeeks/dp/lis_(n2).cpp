#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *A,n;
	cin >> n;
	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

	int *L,max=1;
	L = (int *)malloc(n*sizeof(int));
	L[0]=1;
	
	for(int i=1;i<n;i++)
	{
		L[i]=1;
		for(int j=0;j<i;j++)
			if(A[j]<A[i] && (L[j]+1)>L[i])
				L[i] = 1 + L[j];
		if(L[i]>max)
			max = L[i];
	}	
	cout << max << endl;	
	
	return 0;
}
