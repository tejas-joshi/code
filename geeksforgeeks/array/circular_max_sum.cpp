//======== MAX SUM IN CIRCULAR ARRAY

/*****
  Given an array, find the max sum which can be circular...
  8
  -1 40 -14 7 6 5 -4 -1
  o/p : 52 ... (7+6+5+(-4)+(-1)+(-1)+40)

Logic :
* First compute the max. subarray sum by kadane. ( max sum can be contiguous.. not circular)
* Find the subarray sum which is min in the array. How will you do it ?
	Just compute kadane by taking -A[i]... You will have min sum of the array... but in opposite sign.
	In the given example it will be 14... (minimum sum is -14 actually)
	Now we have to subtract it from the whole sum of array in order to remove that portion... but we already have that sum with opposite sign.
		Just add it with whole sum of array.
	In the given example totalsum=38.. and minsum=14... (because of -14)
	so ans by circular kadane = totalsum + minsum	
	
answer = max(kadane_normal,kadane_circular)

TC : O(n)
SC : O(1)

******/

#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int n,*A,sumTotal=0;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
	{
		cin >> A[i];
		sumTotal = sumTotal + A[i];
	}
	
	int max_sum_forw=INT_MIN,max_sum_circ=INT_MIN,sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		sum1 = sum1 + A[i];
		if(sum1<0)
			sum1=0;
		else if(sum1>max_sum_forw)
			max_sum_forw=sum1;

		sum2 = sum2 + (A[i]*-1);	
		if(sum2<0)
			sum2=0;
		else if(sum2>max_sum_circ)
			max_sum_circ=sum2;	
	}	
	cout << max(max_sum_forw,sumTotal+max_sum_circ) << endl;
	return 0;
}

