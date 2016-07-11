#include<iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		cin >> x >> y;

		if(x%2==0 && y%2==0 && ((x-y)==2 || x==y) )
			cout << x+y << endl;
		else if(x%2 && y%2 && ((x-y)==2 || x==y) )
			cout << x+y-1 << endl;
		else
			cout << "No Number" << endl;
	}

	return 0;
}
