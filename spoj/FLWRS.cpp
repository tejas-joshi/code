
// http://oeis.org/A002464

#include<iostream>
using namespace std;
typedef long long int LL;

int main()
{
	LL N,M;
	int T=28;
	
	while(T--)
	{
		LL ans[2001];
		cin >> N >> M;
		LL t1,t2,t3,t4;
		ans[0] = 1;
		ans[1] = 1;
		ans[2] = 0;
		ans[3] = 0;

		for(LL i=4;i<=N;i++)
		{
			t1 = ((i+1)*ans[i-1])%M;
			t2 = ((i-2)*ans[i-2])%M;
			t3 = ((i-5)*ans[i-3])%M;
			t4 = ((i-3)*ans[i-4])%M;
			ans[i] = ((t1<0)?(t1+M):t1) - ((t2<0)?(t2+M):t2) - ((t3<0)?(t3+M):t3) + ((t4<0)?(t4+M):t4);
			
			ans[i] = ans[i]%M;
			if(ans[i]<0)
				ans[i] = ans[i] + M;
		}
		cout << ans[N] << endl;
	}
	return 0;
}
