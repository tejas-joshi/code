// CHECK WHETHER THE NUMBER IS LUCKY OR NOT..

/*
Take the whole set of numbers. (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18...)
Now delete every second number..so (1 3 5 7 9 11 13 15 17 19..)
Now delete every third number.. so (1 3 7 9 13 15 19..)
Now delete every fourth number... etc..

If the number gets never deleted then the number is lucky...

Logic :
n is the number we are checking for.
Initially the position of the number is n.

Take another variable counter for maintaining which number we are going to delete...(i.e. If we are going to delete every third number then counter=3..)
So counter will be initially 2..
If n is divisible by counter any time then n is going to be deleted for sure.. so check every time in the loop..

counter=2.. After delete every second number the updated position of n will be (n-(n/2)) 
counter=3.. next position of the number will be (n-(n/3))...
repeat this for all till the counter exceeds n..

refer code for more clarity...

Think about the time complexity...

*/

#include<iostream>
using namespace std;

bool checkLucky(int n)
{
	int curr_pos = n;	// initial position of n
	for(int counter=2;counter<=curr_pos;counter++)
	{	
		if(curr_pos%counter==0)	// Here n is going to be deleted..
			return 0;
		curr_pos = curr_pos - (curr_pos/counter); // updating the current position of n
	}
	return 1;	// n was not deleted at all so lucky..
}

int main()
{	
	int n;
	cin >> n;
	cout << checkLucky(n) << endl;	
	return 0;
}
