//======= ACTIVITY SELECTION PROBLEM

/*
Given a list of activities with start and finish time, find the maximum number of activites that can be
performed without collision.

Logic :

Sort the activities by their finish time.
Add first activity.
Add next activity if its start time is greater than the finish time of previous added activity.

TC : O(nlogn) 	//  sorting + scan => O(nlogn + n)
SC : O(n) 		// sorting space
*/

#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

// compare function for sort
bool compare(const pair<int,int>& left,const pair<int,int>& right)
{
	return left.second < right.second;	// taking second as sorting parameter becuase we want to sort by finish time
}

int main()
{
	int n,a,b;
	cin >> n;

	vector< pair<int,int> > P;

	// taking input
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		P.push_back(make_pair(a,b));
	}

	// sort the activities by their finish time
	sort(P.begin(),P.end(),compare);	

	int j=0;	// j maintain the index of previously added activity
	cout << j << " ";	// first activity is added so print the index of it

	for(int i=1;i<n;i++)
	{
		if(P[i].first >= P[j].second) 	// finish time of current activity is greater than previously added activity
		{
			cout << i << " ";	// added so print the index of it
			j=i;				// set the current acitivity as added activity
		}	
	}
	cout << endl;
	
	return 0;
}	
