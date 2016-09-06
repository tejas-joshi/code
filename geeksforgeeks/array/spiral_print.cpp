//=== PRINT MATRIX IN SPIRAL FORM
	
/*******
Given a matrix, print it in spiral form.
Logic:
You know the logic. You have done it many times.. 
4 for loops inside a loop...

EACH ITERATION 
1 - left to right (including both corner elements - (0,0) and (0,n-1) for 1st row )
2 - top to bottom (excluding both corner elements)
3 - right to left (including both corner elements - (n-1,n-1) and (n-1,0) for last row )
4 - down to top	  (excluding both corner elements)
top++,down--,left++ and right--...

TC : O(mn)
SC : O(1)
********/

#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cin >> m >> n;
	int **A;
	A = new int*[m];
	for(int i=0;i<m;i++)
		A[i] = new int[n];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> A[i][j];

	int top=0,down=m-1,left=0,right=n-1,count=0;
	
	// Here you can store m*n into some variable to avoid m*n multiplications.
	while(count<=(m*n))	
	{
		for(int i=left;i<=right && count<=m*n;i++,count++)	// printing left to right
			cout << A[top][i] << " ";
		for(int i=top+1;i<down && count<=m*n;i++,count++)	// printing top to bottom  
			cout << A[i][right] << " ";
		for(int i=right;i>=left && count<=m*n;i--,count++)	// printing right to left
			cout << A[down][i] << " ";
		for(int i=down-1;i>top && count<=m*n;i--,count++)	// printing down to top
			cout << A[i][left] << " ";
		top++;
		left++;
		right--;
		down--;
	}
	cout << endl;

	return 0;
}
