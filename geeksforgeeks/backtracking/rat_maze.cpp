// RAT IN THE MAZE PROBLEM
// A rat is there in the maze at (0,0) and it has to reach (n-1,n-1).
// Maze contains the cell in which each cell has value 0 or 1/
// 0 indicates wall and 1 indicate the space

// SIMPLE DP SOLUTION

#include<iostream>
using namespace std;

int main()
{
	int **Mz,n;
	bool **Sol;
	cin >> n;
	
	Mz = new int*[n];
	for(int i=0;i<n;i++)
		Mz[i] = new int[n];

	Sol = new bool*[n];
	for(int i=0;i<n;i++)
		Sol[i] = new bool[n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	
			cin >> Mz[i][j];
			Sol[i][j] = false;
		}

	Sol[0][0] = true;

	for(int i=1;i<n;i++)
		Sol[i][0] = Sol[i-1][0] && (Mz[i][0]==1); 
	for(int j=1;j<n;j++)
		Sol[0][j] = Sol[0][j-1] && (Mz[0][j]==1); 

	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			Sol[i][j] = ((Sol[i-1][j] || Sol[i][j-1]) && (Mz[i][j]==1)); 
	
	cout << Sol[n-1][n-1] << endl;	
		
	return 0;	
}
