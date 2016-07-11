//======= MAX SUM WITH NO TWO ELEMENTS ADJACENT

/*******

Given an array, find the max sum where no two elements can be adjacent.

e.g.
5 5 10 40 50 35
80	// 5+40+35

Logic:
* Take two variables excl and incl.
* At any time, excl contains the max which doesnt include current element.
* At any time, incl contains the max which includes current element.

	excl_new = max(incl,excl)    // Here incl and excl is having max considering previous element	
		// we are not including current element so we can take max of both.

	incl = excl + A[i] // Here incl will be for current element.
		// to make sure last element was not included.

	excl = excl_new 
		// assigning excl_new to max that excluded current element
	
TC : O(n)
SC : O(1)

*******/


#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	int excl=0,incl=0,excl_new;

	if(n>0)
		incl = A[0];

	for(int i=1;i<n;i++)
	{
		// max excluding A[i];
		excl_new = max(incl,excl);

		// max including A[i];
		incl = excl + A[i];
		excl = excl_new;		
	}

	cout << max(excl,incl) << endl;

	

	return 0;
}
