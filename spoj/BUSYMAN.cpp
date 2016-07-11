#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

bool compare (const pair<int,int>& left,const pair<int,int>& right)
{	return left.first<right.first;		}

int main()
{
	int a,b,t,n;
	vector< pair<int,int> > A;
	vector<int> B;

	cin >> t;
	while(t--)
	{
		cin >> n;
		
		for(int i=0;i<n;i++)
		{
			cin >> a >> b;
			A.push_back(make_pair(a,b));
		}

		sort(A.begin(),A.end(),compare);

		
		B.push_back(0);

		for(int i=1;i<n;i++)
		{
			if(A[i].second >= A[B.back()].second && A[i].first >= A[B.back()].second)	// checking both conditions
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

			if(A[i].second <= A[B[u]].second && A[i].first <= A[B[u]].second)		// checking both conditions
			{
				B[u]=i;
			}
		}

		cout << B.size() << endl;

		A.clear();
		B.clear();
	}
	return 0;
}
