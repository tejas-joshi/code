//======= FIND MIN AND SECOND MIN FROM THE ARRAY

// YOU MUST BE KIDDING... JUST READ THE CODE ONCE... :D

#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	int min1=INT_MAX,min2=INT_MAX;

	for(int i=0;i<n;i++)
	{
		if(A[i]<min1)
		{
			min2 = min1;	
			min1 = A[i];
		}
		else if(A[i]<min2)
			min2 = A[i];
	}

	cout << min1 << " " << min2 << endl;

	return 0;
}
