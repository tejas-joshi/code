// PRINT ALL THE WAYS THROUGH WHICH NUMBER CAN BE MADE USING SUM

/*
For n = 2, the program should print following:
1 1
2

For n = 3, the program should print following:
1 1 1
1 2
2 1
3

For n = 4, the program should print following:
1 1 1 1
1 1 2
1 2 1
1 3
2 1 1
2 2
3 1

and so on...

Logic :
	start from i=1 to n
		push i to consider it and continue the work for n-i
		after the completion of the work remove i from the consideration and do it for the next i.
	
Refer code for more clarity...

*/


#include<iostream>
#include<vector>
using namespace std;

void countWays(int n,vector<int> *V)
{
	if(n==0)
	{
		// Printing the whole vector
		for(int i=0;i<V->size();i++)
			cout << V->at(i) << " ";
		cout << endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			V->push_back(i);	// consider i in the count so push it into the vector
			countWays(n-i,V);	// continue the remaining work.. so call it for n-i
			V->pop_back();		// remove i from the vector to not to consider ..and do the count for the next i's...
		}
	}
}

int main()
{
	vector<int> V;
	int n;
	cin >> n;
	countWays(n,&V);
	return 0;
}
