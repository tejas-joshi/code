#include<iostream>
using namespace std;
int main()
{	
	double T,A[501],n,k;
	double sum=0,part;

	cin >> T;

	int i;

	while(T--)
	{
		cin >> n >> k;
		for(i=0;i<n;i++)
		{
			cin >> A[i];
			sum = sum + A[i];
		}
		part=sum/k;
	
		double tempSum=0,tempPart=part;
		for(i=0;i<n-1;i++)
		{
			cout << A[i] << " ";
			tempSum = tempSum + A[i];
			if(tempSum+A[i+1]>tempPart)
			{
				cout << "/ ";
				tempPart = tempPart + part;
			}
		}		
		cout << A[i] << endl;
		sum=0;
	}
	
	return 0;	
}	
