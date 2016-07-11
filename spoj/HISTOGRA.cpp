#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
int main()
{
	long long A[100001],N,max=0,total,leftA[100001],rightA[100001];
	int i;

	while(1)
	{
		cin >> N;
		if(!N)
			break;

		stack<long long> S;
		max=0;	
//		A = (long long *)malloc(N*sizeof(long long));
//		leftA = (long long *)malloc(N*sizeof(long long));
//		rightA = (long long *)malloc(N*sizeof(long long));

		for(i=0;i<N;i++)
		{
			cin >> A[i];
			leftA[i]=rightA[i]=-1;
		}	

		for(i=0;i<N;i++)
		{
			while(!S.empty() && A[S.top()]>A[i])
			{
				leftA[S.top()]=i-1;
				S.pop();
			}
			S.push(i);		
		}
		
		for(i=0;i<N;i++)
			if(leftA[i]==-1)
				leftA[i]=N-1;
		
		while(!S.empty())
			S.pop();	
			
		for(i=N-1;i>=0;i--)
		{
			while(!S.empty() && A[S.top()]>A[i])
			{
				rightA[S.top()]=i+1;
				S.pop();
			}
			S.push(i);
		}

		for(i=0;i<N;i++)
			if(rightA[i]==-1)
				rightA[i]=0;

		for(i=0;i<N;i++)
		{
			total = (leftA[i]-rightA[i]+1)*A[i];
			if(total>max)
				max = total;
		}
			
		cout << max << endl;
	}
	
	return 0;	
}
