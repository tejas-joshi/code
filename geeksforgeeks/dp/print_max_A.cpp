//==== How to print maximum number of A’s using given four keys

/*
Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it
                 after what has already been printed.
				 
				 
Input:  N = 3
Output: 3
We can at most get 3 A's on screen by pressing 
following key sequence.
A, A, A

Input:  N = 7
Output: 9
We can at most get 9 A's on screen by pressing 
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V


- For N < 7, the output is N itself
- Ctrl V can be used multiple times to print current buffer

The task is to find out the break=point after which we get the above suffix of keystrokes. 
Definition of a breakpoint is that instance after which we need to only press Ctrl-A, Ctrl-C once and the only Ctrl-V’s afterwards to generate the optimal length. 
If we loop from N-3 to 1 and choose each of these values for the break-point, and compute that optimal string they would produce.

Refer the code... .

(N-b-1)*findoptimal(b);
Especially why (N-b-1) ?

Then I realized the logic as follows :- 
If you are at breakpoint - b; then till that point you have achieved findoptimal(b) number of A's
Now you have (N-b) chances left. Now you will do ctrl+a and ctrl+c.
So you have findoptimal(b) in your buffer which can be used for copy.
After these two key press you have N-b-2 chances left. 
So number of times you can do ctrl+v is N-b-2
So you will get further (N-b-2)*buffer i.e. (N-b-2)*findoptimal(b) of A's

totoal number of A's =
A's till break point b + A's after breakpoint b
=findoptimal(b)+ (N-b-2)*findoptimal(b)
=(N-b-2+1)findoptimal(b)
=(N-b-1)findoptimal(b)

TC : O(n^2)
SC : O(n)

*/

#include<iostream>
#include<stdlib.h>
using namespace std;

int countMaxA(int n)
{
	int *dp;
	dp = new int[n+1];
	
	if(n<=6)
		return n;

	for(int i=0;i<=6;i++)
		dp[i] = i;
		
	for(int i=7;i<=n;i++)
	{
		dp[i]=0;
		for(int b=i-3;b>=1;b--)
			dp[i] = max(dp[i],(i-b-1)*dp[b]); // Refer description section to understand this logic.
	}
		
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << countMaxA(n) << endl;		
	return 0;
}
