#include<iostream>
#include<stdlib.h>
#include<deque>
using namespace std;
int main()
{
	deque<int> minV,maxV;
	int N,W,*H;
	cin >> N >> W;
	H = (int *)malloc((N+1)*sizeof(int) );

	for(int i=0;i<N;i++)
		cin >> H[i];

	for(int i=0;i<W;i++)
	{
		while(!minV.empty() && H[i] <= H[minV.back()])
			minV.pop_back();
		minV.push_back(i);

		while(!maxV.empty() && H[i] >= H[maxV.back()])
			maxV.pop_back();
		maxV.push_back(i);			
	}

	int minW,maxW,count=0;
	for(int i=W;i<N;i++)
	{
		minW = H[minV.front()]; 		
		while(!minV.empty() && H[i] <= H[minV.back()])
			minV.pop_back();
		while(!minV.empty() && minV.front() <= (i-W))
			minV.pop_front();
		minV.push_back(i);

		maxW = H[maxV.front()]; 		
		while(!maxV.empty() && H[i] >= H[maxV.back()])
			maxV.pop_back();
		while(!maxV.empty() && maxV.front() <= (i-W))
			maxV.pop_front();
		maxV.push_back(i);			

		if( (maxW-minW+1)==W)
			count++;
	}

	if(H[maxV.front()]-H[minV.front()]+1==W)
		count++;

	cout << count << endl;
	
	return 0;
}
