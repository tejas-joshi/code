//==== DEPTH FIRST SEARCH

/*********

POINTS TO BE TAKEN CARE
* Make visited[i]=true before pushing it into stack.

TC : O(|V|+|E|)
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

	visited[0] = true;
	S.push(0);

	while(!S.empty())
	{
		cout << S.top() << " ";
		int elem = S.top();
		S.pop();

		for(int i=0;i<n;i++)
			if(!visited[i] && E[elem][i])
			{
				visited[i] = true;
				S.push(i);
			}
	}	
	
	return 0;		
}	
