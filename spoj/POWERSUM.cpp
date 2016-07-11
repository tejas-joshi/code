#include<iostream>
using namespace std;
typedef long long int LL;
#define MOD 1000000007
void fillPower(LL *A)
{
	LL ans=1;

	for(int i=0;i<=10000;i++)
	{
		A[i]=ans;
		ans = (A[i]*2)%MOD;
	}
}


int main()
{
	LL pw[10001];

	fillPower(pw);

	int T;
	cin >> T;

	while(T--)
	{
		LL n,a,ans=0;
		cin >> n;

		for(int i=0;i<n;i++)
		{
			cin >> a;
			ans = (ans + (a*pw[n-1])%MOD)%MOD;
		}
		cout << ans << endl;
	}
	return 0;
}

