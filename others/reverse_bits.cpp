//===== FIND THE NUMBER BY REPRESENTING IT BY REVERSING THE BITS OF GIVEN NUMBER

/*
e.g. 26 => 11010 -- Reverse bits --> 01011 ---> 11 (output)

Logic : 
answer=0;
Everytime,
we right shift (/2) the given number, we are also left shift (*2) the answer.
Before that we just check last bit (LSB) and if it is set then we add 1 to ans otherwise not.

TC : O(logn base 10)
SC : O(1)
*/

#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;

	int ans=0;

	while(n)
	{
		ans = ans*2 + (n%2); // left shifting ans.. and if LSB is set then 1 will be added..
		n=n/2;		    // right shifting n.. 
	}
	cout << ans << endl;
	return 0;
}
