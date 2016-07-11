#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(const pair<int,int>& left,const pair<int,int>& right)
{
	return left.second < right.second;	// taking second as sorting parameter becuase we want to sort by finish time
}

int main()
{
	int n,a,b,t,count=1;
	vector< pair<int,int> > P;
	cin >> t;

	while(t--)
	{	
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> a >> b;
			P.push_back(make_pair(a,b));
		}

		// sort the activities by their finish time
		sort(P.begin(),P.end(),compare);	

		int j=0;	// j maintain the index of previously added activity
		for(int i=1;i<n;i++)
		{
			if(P[i].first >= P[j].second) 	// finish time of current activity is greater than previously added activity
			{
				count++;
				j=i;				// set the current acitivity as added activity
			}	
		}
		P.clear();
		cout << count << endl;
		count=1;
	}
	
	return 0;
}	
