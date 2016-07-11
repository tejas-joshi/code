#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
typedef long long int LL;
map <LL,LL> M;
map <LL,LL>:: iterator it;

LL countExchange(LL n)
{
	if(n<=0)
		return 0;
	
	it = M.find(n);
	if(it==M.end())
		M[n] =  max(n,countExchange(n/2)+countExchange(n/3)+countExchange(n/4));
	return M[n];
}

int main()
{
	LL n;
	
	while(scanf("%lld",&n)!=EOF)
	{
		cout << countExchange(n) << endl;
		M.clear();
	}
	return 0;
}
