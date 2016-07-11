#include<iostream>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n==-1)
			break;

		int *A,sum=0;
		A = new int[n];

		for(int i=0;i<n;i++)
		{
			cin >> A[i];
			sum = sum + A[i];
		}

		int lim = sum/n;

		if(sum!=(lim*n))
		{
			cout << -1 << endl;
			continue;
		}
		

		int count=0;
		for(int i=0;i<n;i++)
			if(A[i]<lim)
				count = count + lim-A[i];

		cout << count << endl;
	}

	return 0;
}
