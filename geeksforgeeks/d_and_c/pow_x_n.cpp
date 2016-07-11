//==== FIND x^n

/**

Logic :
Ye samjhane ki jarurat nai hai be !!
You have only 5 seconds to understand code/logic... If it takes more then DOOB MAR SAALE .... 

TC : O(logn)
SC : O(logn) // stack space...

**/
#include<iostream>
using namespace std;

int power(int x,int n)
{
	if(n==0)
		return 1;
	else
	{
		int temp = power(x,n/2);
		if(n%2)
			return x*temp*temp;
		else
			return temp*temp;
	}
}

int main()
{
	int x,n;
	cin >> x >> n;
	cout << power(x,n) << endl;

	return 0;
}
