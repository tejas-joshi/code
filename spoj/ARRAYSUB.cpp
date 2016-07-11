#include<iostream>
#include<deque>
#include<limits.h>
using namespace std;
int main()
{
	deque<int> Q;
	int n,k,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	cin >> k;
	for (int i=0;i<k;i++)
	{
		while (!Q.empty() && A[i]>=A[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	cout << A[Q.front()];

	for(int i=k;i<n;i++)
	{
		while(!Q.empty() && A[Q.back()]<=A[i])
			Q.pop_back();
		while(!Q.empty() && Q.front()<=(i-k))
			Q.pop_front();
		Q.push_back(i);
		cout << " " << A[Q.front()];
	}
	cout << endl;
	
	return 0;
}

