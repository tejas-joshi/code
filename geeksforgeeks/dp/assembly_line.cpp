#include<iostream>
using namespace std;

int main()
{
	int assembly[2][4] = {{4, 5, 3, 2},{2, 10, 1, 4}};
	int time[2][4] = {{0, 7, 4, 5},{0, 9, 2, 8}};
	int entry[2] = {10, 12}, exit[2] = {18, 7};            

	int ans[2][4];
	
	ans[0][0] = entry[0] + assembly[0][0];
	ans[1][0] = entry[1] + assembly[1][0];
		
	for(int i=1;i<4;i++)	
	{
		ans[0][i] = assembly[0][i] + min(ans[0][i-1],ans[1][i-1]+time[1][i]);
		ans[1][i] = assembly[1][i] + min(ans[1][i-1],ans[0][i-1]+time[0][i]);
	}
	
	cout << min(ans[0][3]+exit[0],ans[1][3]+exit[1]) << endl;

	return 0;
}
