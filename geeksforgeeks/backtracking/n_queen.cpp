// N QUEEN PROBLEM

// PUT N QUEENS IN N*N CHESS BOARD SUCH THAT NO QUEENS CONFLICT EACH OTHER...

// LOGIC IN THE CODE

#include<iostream>
#define N 8
using namespace std;

bool isSafe(bool **board,int row,int col)
{
	// checking for row conflict
	for(int i=0;i<col;i++)
		if(board[row][i])
			return false;
	
	// checking for diagonal on upper side
	for(int i=row,j=col;i>=0 && j>=0;i--,j--)
		if(board[i][j])
			return false;
	
	// checking for diagonal on lower side
	for(int i=row,j=col;i<N && j>=0;i++,j--)
		if(board[i][j])
			return false;
	
	// no conflict so it is safe	
	return true;
}

// we reach to the solution by incrementing column each time and check for all rows in each call
bool solNQ(bool **board,int col)
{
	// we reach to the end of the board so found the solution
	if(col>=N)
		return true;
	
	for(int i=0;i<N;i++)
	{
		if(isSafe(board,i,col))		// checking for conflict if we put the queen on current position
		{
			board[i][col] = true;	// setting the current position as true	
			if(solNQ(board,col+1))	// checking in rest of the board for solution
				return true;		
			board[i][col] = false;	// we didnt find the solution from rest of the board so setting false to current position.. try for next row..
		}
	}
}

void printSolution(bool **board)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

void getNQSolution()
{
	bool **board;
	board = new bool*[N];
	for(int i=0;i<N;i++)
		board[i] = new bool[N];
		
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			board[i][j] = false;

	if(solNQ(board,0))
		printSolution(board);
	else
		cout << "No solution found. " << endl;
}

int main()
{
	getNQSolution();
	return 0;	
}
