#include<iostream>
#include<limits.h>
using namespace std;

int costFun(int t,int j,int n)
{
	if(t<0)
		return INT_MAX;
	else if(j==n && t>0)
		return 0;
	else
		return t*t*t;
}

int main()
{
	int n,*l;
	cin >> n;
	l = new int[n];
	for(int i=0;i<n;i++)
		cin >> l[i];

	int M;
	cin >> M;

	int *cost;
	cost = new int[n+1];
	cost[0] =0;

	int p=M;
	for(int j=1;j<=n;j++)
	{
		p=p-l[i-1];
		int t = p;
		int lc;
		cost[i] = INT_MAX;
		for(int i=1;i<=j;i++)
		{	
			t=t-l[j-1];
			if(j!=1)
				t--;
			lc = costFun(t,j,n);
			cout  << t << " ";
			if(cost[i-1]!=INT_MAX && lc!=INT_MAX && cost[j]>cost[i-1]+lc)
				cost[j] = cost[i-1] + lc;
		}
		cout << endl;
	}
	cout << cost[n] << endl;

	return 0;
}
