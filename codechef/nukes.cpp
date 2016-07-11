#include<iostream>
using namespace std;
int main()
{
	long int A,N,K;
	cin >> A >> N >> K;
	for(int i=0;i<K;i++)
	{
		if(A>N)
		{
			cout << N << " ";
			A = A-N;
		}
		else if(A>0)
		{
			cout << A%N << " ";
			A=0;
		}
		else
			cout << 0 << " ";
	}
	cout << endl;
	return 0;
}
