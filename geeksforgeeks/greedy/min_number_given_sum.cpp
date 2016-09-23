////=========== Find smallest number with given number of digits and sum of digits
/*
Find the smallest number with given digit sum s and number of digits d

Input  : s = 9, d = 2
Output : 18

Input  : s = 20, d = 3
Output : 299

* Fill one by one digit starting from right to left
* Deduct 1 from sum s so that we have smallest digit at the end. 
* After deducting 1, we apply greedy approach. We compare remaining sum with 9, if remaining sum is more than 9, we put 9 at the current position, 
	else we put the remaining sum. Since we fill digits from right to left, we put the highest digits on the right side. 

TC : O(d)	
	
*/

#include<iostream>
using namespace std;

void printMinNumber(int n,int sum)
{
	// If sum of digits is 0, then a number is possible
    // only if number of digits is 1.
	if(sum==0 && n==1)
		cout << 1 << endl;

	// Sum greater than the maximum possible sum.
	if(9*n<sum)
		return;
		
	int *num=new int[n];
	
	// deduct sum by one to account for cases later
    // (There must be 1 left for the most significant digit)
	// e.g. sum=9 and n=4... here ans is 1008... Here 1 will be used later on for setting/updating MSB 
	sum--;
	
	// Check the condition.. we are not setting num[0] here.
	for(int i=n-1;i>0;i--)
	{
		// If sum is still greater than 9,
        // digit must be 9.
		if(sum>9)
		{
			num[i]=9;
			sum=sum-9;
		}
		else
		{
			num[i]=sum;
			sum=0;
		}
	}
	
	// Whatever is left should be the most significant digit.
	num[0]=sum+1;
	
	for(int i=0;i<n;i++)
		cout << num[i];
}

int main()
{
	int n,sum;
	cin >> n >> sum;
	printMinNumber(n,sum);
    return 0;
}