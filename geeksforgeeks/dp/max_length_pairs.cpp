/**********

Find the max. chain of pairs where they dont have any intersection interval.
A pair (c, d) can follow another pair (a, b) if b < c.

Logic :
* Sort the pairs by first element of all pairs.
* LIS on second element.
	--- While adding the pair, make sure that both the start and end time is greater than last event....

TC : O(nlogn) 		( Sort + LIS ) => ( O(nlogn) + O(nlogk) )
SC : O(n)

***********/

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

// To sort all the pairs by first element

// this function is different from compare function of qsort... ( in qsort case, it swaps if the function return true...)
// here the case if reverse...

bool compare (const pair<int,int>& left,const pair<int,int>& right)
{	return left.first<right.first;		}

int main()
{
	int n,**dp;
	vector< pair<int,int> > A;
	cin >> n;

	int a,b;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		A.push_back(make_pair(a,b));
	}

	// Sort the pairs by first element
	sort(A.begin(),A.end(),compare);

	// LIS on second element of pairs
	vector<int> B;
	B.push_back(0);

	for(int i=1;i<n;i++)
	{
		if(A[i].first > A[B.back()].second)	// checking conditions ..... considering pairs (i,j) where i<=j
		{
			B.push_back(i);
			continue;
		}

		int u=0,v=B.size()-1,c;
		while(u<v)
		{
			c=u+(v-u)/2;
			if(A[B[c]].second<A[i].second)
				u=c+1;
			else
				v=c;
		}

		if(A[i].second < A[B[u]].second && A[i].first < A[B[u]].second)		// checking both conditions
			B[u]=i;
	}

	// Answer
	cout << B.size() << endl;
	
	return 0;
}
