//==== NO. OF CONNECTED COMPONENTS

/*********

POINTS TO BE TAKEN CARE
* Here I have used DFS. BFS can also be used to implement this.

The only difference between DFS/BFS and NO. OF CONNECTED COMPONENTS is
* only one loop to check whether any vertice is non-visited.

TC : O(V^2)
SC : O(|V|)

*********/

#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
int main()
{
	int n;	
	bool **E,*visited;
	stack<int> S;

	cin >> n;
	visited = (bool *)calloc(sizeof(bool),n);
	E = (bool **)calloc(sizeof(bool*),n);
	for(int i=0;i<n;i++)
		E[i] = (bool*)calloc(sizeof(bool),n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> E[i][j];

	int components=0;
	for(int v=0;v<n;v++)
	{
		if(!visited[v])
		{
			components++;
			visited[v] = true;
			S.push(v);	// while loop below this will traverse all the node in the component where v belongs to.
		}

		while(!S.empty())
		{
			int elem = S.top();
			S.pop();

			for(int i=0;i<n;i++)
				if(!visited[i] && E[elem][i])
				{
					visited[i] = true;
					S.push(i);
				}
		}	
	}

	cout << components << endl;	
	
	return 0;		
}	
