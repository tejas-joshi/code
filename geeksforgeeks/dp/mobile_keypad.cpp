//==== Mobile Numeric Keypad Problem

/*
Please refer the keypad in the main method.
Given the mobile numeric keypad. You can only press buttons that are up, left, right or down to the current button. 
You are not allowed to press bottom row corner buttons (i.e. * and # ).
Given a number N, find out the number of possible numbers of given length.

For N=1, number of possible numbers would be 10 (0, 1, 2, 3, …., 9)
For N=2, number of possible numbers would be 36
Possible numbers: 00,08 11,12,14 22,21,23,25 and so on.

Logic :
- Refer the pic in the dp folder. (mobile_keypad_logic.jpg)
- for n=0. all will be 0... and for n=1, all would be 1 because only one keypress is allowed.
- Now consider a key and compute number of ways the keypress sequence ends at that key.
	- So it would be (current count + all the neighbour count) for previous n value

so we will take 2 1-D array of size 10. 
We will compute for the current array using the previous array. ( n%2 and (n-1)%2  alternatively)

TC : O(n)	
SC : O(1)

*/

#include<iostream>
using namespace std;

int getCount(char keypad[][3], int n)
{
	int count[2][10];
	for(int i=0;i<10;i++)
		count[0][i] = 0;
	for(int i=0;i<10;i++)
		count[1][i] = 1;

	int prev;
	for(int i=2;i<=n;i++)
	{
		prev = i-1; // Taking the previous i value
		count[i%2][0] = count[prev%2][0] + count[prev%2][8];
		count[i%2][1] = count[prev%2][1] + count[prev%2][2] + count[prev%2][4];
		count[i%2][2] = count[prev%2][2] + count[prev%2][1] + count[prev%2][3] + count[prev%2][5];
		count[i%2][3] = count[prev%2][3] + count[prev%2][2] + count[prev%2][6];
		count[i%2][4] = count[prev%2][4] + count[prev%2][1] + count[prev%2][5] + count[prev%2][7];
		count[i%2][5] = count[prev%2][5] + count[prev%2][2] + count[prev%2][4] + count[prev%2][8] + count[prev%2][6];
		count[i%2][6] = count[prev%2][6] + count[prev%2][3] + count[prev%2][5] + count[prev%2][9];
		count[i%2][7] = count[prev%2][7] + count[prev%2][4] + count[prev%2][8];
		count[i%2][8] = count[prev%2][8] + count[prev%2][0] + count[prev%2][5] + count[prev%2][7] + count[prev%2][9];
		count[i%2][9] = count[prev%2][9] + count[prev%2][6] + count[prev%2][8];
	}
	
	// Sum of all the keypress ends at i
	int totalCount=0;
	for(int i=0;i<10;i++)
		totalCount = totalCount + count[n%2][i];
	return totalCount;
}

int main()
{	
	char keypad[4][3] = 
	{
		{'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
        {'*','0','#'}
    };
	int n;
	cin >> n;
	
	cout << getCount(keypad,n) << endl;
	
	return 0;
}
