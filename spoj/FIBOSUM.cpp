#include<iostream>
#include<cstring>
#define MOD 1000000007
using namespace std;

long long fibonacci(int n)
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
                        tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j])%MOD;
            for(i=0; i<2; i++)
				for(j=0; j<2; j++)
					ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof(tmp));
        for(i=0; i<2; i++)
			for(j=0; j<2; j++)
				for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j])%MOD;
        for(i=0; i<2; i++)
			for(j=0; j<2; j++)
				fib[i][j]=tmp[i][j];
        n=n/2;
    }
    return (ret[0][1])%MOD;
}

int main()
{
	int m,n,t;
	cin >> t;
	while(t--)
	{
		cin >> m >> n;
		cout << (fibonacci(n+2) - fibonacci(m+1) + MOD)%MOD << endl;
	}
}
