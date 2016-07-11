#include<iostream>
#include<stdlib.h>
using namespace std;

int compare(const void *a,const void *b)
{
	return (* (int *)a) - (* (int *)b);
}

int main()
{
	int T,N,M[1001],F[1001],sum=0;
	cin >> T;

	while(T--)
	{
		cin >> N;
		for(int i=0;i<N;i++)
			cin >> M[i];
		for(int i=0;i<N;i++)
			cin >> F[i];
		qsort(M,N,sizeof(int),compare);				
		qsort(F,N,sizeof(int),compare);				
		
		for(int i=0;i<N;i++)
			sum = sum + M[i]*F[i];
		cout << sum << endl;
		sum=0;
	}
	return 0;
}
