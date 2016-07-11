#include<iostream>
#include<queue>
using namespace std;

class compare
{
	public:
		bool operator()(pair<int,int> p1,pair<int,int> p2)
		{
			return p1.second > p2.second;
		}
};

int main()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,compare> pQ;

	pQ.push(make_pair(1,20));
	pQ.push(make_pair(2,10));

		

	return 0;
}
