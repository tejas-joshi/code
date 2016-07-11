#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int N;
	cin >> N;
	
	bool edges[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			edges[i][j] = false;
		
	bool visited[N];
	for(int i=0;i<N;i++)
		visited[i] = false;
	
	int src,dst;
	
	while(1)
	{
		cin >> src;
		if(src==-1)
			break;
		cin >> dst;
		
		edges[src][dst] = true;
	}
	
	stack<int> S;
	S.push(0);
	bool foundCycle = false;
	int loopAt;
	
	while(!S.empty())
	{
		int nd = S.top();
		visited[nd] = true;
		
		for(int i=0;i<N;i++)
		{
			if(nd!=i)	
				if(visited[i])
				{
					loopAt = i;
					foundCycle = true;
					break;
				}
				else if(edges[nd][i])
					S.push(i);
		}
		
		if(foundCycle)
			break;
	}

	cout << foundCycle << endl;
	
	while(!S.empty())
	{
		cout << S.top() << " ";
		S.pop();
	}
	
	//cout << loopAt << endl;
	
	
	return 0;	
}
