#include<iostream>
using namespace std;
int main()
{
	int a=0,b=1,c;
	int n;

	cin >> n;

	if(n==1)
		cout << a << endl;
	else if(n==2)
		cout << b << endl;
	else
	{
		n=n-2;
		while(n--)
		{
			c=a+b;
			a=b;
			b=c;
		}
		cout << c << endl;
	}
	return 0;
}
