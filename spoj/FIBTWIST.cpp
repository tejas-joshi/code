#include<iostream>
#include<cstring>
using namespace std;

long long fibonacci(long long int n,long long int MOD)
{
    long long fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n%2)
        {
            memset(tmp,0,sizeof(tmp));
            for(i=0; i<2; i++)
				for(j=0; j<2; j++)
					for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]%MOD + ((ret[i][k]%MOD *fib[k][j]%MOD)%MOD))%MOD;
            for(i=0; i<2; i++)
				for(j=0; j<2; j++)
					ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof(tmp));
        for(i=0; i<2; i++)
			for(j=0; j<2; j++)
				for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]%MOD + ((fib[i][k]%MOD)*(fib[k][j]%MOD))%MOD)%MOD;
        for(i=0; i<2; i++)
			for(j=0; j<2; j++)
				fib[i][j]=tmp[i][j];
        n=n/2;
    }
    return (ret[0][1])%MOD;
}

int main()
{
	long long int M,n,res;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> M;
		res = (2*fibonacci(n+2,M)-n-2)%M;
		if(res<0)
			res = res + M;
		cout << res << endl;
	}
}
