#include<iostream>
#include<vector>
using namespace std;

bool comparePair(pair<int,int> a,pair<int,int> b)
{
	return (a.first<b.first && a.second<b.second);
}

int main()
{
	int N;
	vector<int> V;
	cin >> N;
	pair<int,int> arr[N];

	for(int i=0;i<N;i++)
		cin >> arr[i].first >> arr[i].second;

	V.push_back(0);
	
	for(int i=1;i<N;i++)
	{
		if(comparePair(arr[V.back()],arr[i]))
		{
			V.push_back(i);
			continue;	
		}
		
		int u=0,v=V.size()-1,mid;
		while(u<v)
		{
			mid = u + (v-u)/2;
			if(comparePair(arr[V[mid]],arr[i]))
				u=mid+1;
			else
				v=mid;
		}
			
		if(comparePair(arr[i],arr[V[u]]))
			V[u] = i;
	}	
	
	cout << V.size() << endl;
		
	return 0;	
}
