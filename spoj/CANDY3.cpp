#include<iostream>
using namespace std;
int main()
{
	long long int n,T;
	cin >> T;
	while(T--)
	{
		cin >> n;

		long long int sum=0,a;

		for(long long int i=0;i<n;i++)
		{
			cin >> a;
			sum = ((sum%n) + (a%n))%n;
		}


		if(sum!=0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}
