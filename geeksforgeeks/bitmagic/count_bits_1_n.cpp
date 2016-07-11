// Count total set bits in all numbers from 1 to n

/*
Given a positive integer n, count the total number of set bits in binary representation of all numbers from 1 to n.

Examples:

Input: n = 3
Output:  4

Input: n = 6
Output: 9

Explanation is there in the comments and document also.. Refer please.

*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,count=0;
	cin >> n;
	
	while(n)
	{
		int ln = floor((int)log2(n));	// finding the power of 2 which is just less than n
		
		if(n == ((1<<(ln+1))-1))	// if n is like 1,3,7,15,31 then we are done... 
		{
			count = count + (ln+1)*(1<<ln);
			break;
		}
		
		n = n - (1<<ln);	// removing the upper part which we have computed
		count = count + (n+1) + ln*(1<<(ln-1));		// adding the count of set bits for the upper part which we have considered
	}
	
	cout << count << endl;
	
	return 0;	
}

// if the function floor is not allowed then use this function
int getLeftmostBit (int n)
{
   int m = 0;
   while (n  > 1)
   {
      n = n >> 1;
      m++;
   }
   return m;
}
