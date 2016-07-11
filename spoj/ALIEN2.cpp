#include<iostream>
#include<limits.h>
using namespace std;
int main()
{	
	int  N,S;
	cin >> N >> S;

	int P1[10001],P2[10001];
	int dpA[10001];
	int dpB[10001];

	for(int i=0;i<N;i++)
		cin >> P1[i];
	for(int i=0;i<N;i++)
		cin >> P2[i];

	dpA[0] = P1[0];
	dpB[0] = P2[0];

	int maxL=0,minPpl=INT_MAX;
	
	for(int i=1;i<N;i++)
	{	
		dpA[i] = min(dpA[i-1],dpB[i-1]+P2[i]) + P1[i];
		dpB[i] = min(dpB[i-1],dpA[i-1]+P1[i]) + P2[i];
	}

	
	if(maxL==0 && dpA[0]<=S) 		
	{
		maxL=1;
		minPpl = dpA[0];
	}
	for(int i=1;i<N;i++)
		if(dpA[i]<=S)
		{
			if((i+1)>=maxL)
			{
				if((i+1)>maxL || ((i+1)==maxL && (dpA[i]<minPpl)))
					minPpl = dpA[i];
				maxL=(i+1);		
			}
		}	


	if(maxL==0 && dpB[0]<=S)
	{
		maxL=1;
		minPpl = dpB[0];
	}
	else if(maxL==1 && dpB[0]<=minPpl)
		minPpl = dpB[0];
	
	for(int i=1;i<N;i++)
		if(dpB[i]<=S)
		{
			if((i+1)>=maxL)
			{
				if((i+1)>maxL || ((i+1)==maxL && (dpB[i]<minPpl)))
					minPpl = dpB[i];
				maxL=(i+1);		
			}
		}		

	cout << maxL << " " << ((minPpl==INT_MAX)?0:minPpl) << endl;
			
	return 0;
}
